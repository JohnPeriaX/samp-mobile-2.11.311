package com.kurdish.roleplay.game;

import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.Display;
import android.view.KeyEvent;
import android.view.WindowManager;
import android.widget.Toast;

import com.google.firebase.crashlytics.FirebaseCrashlytics;
import com.joom.paranoid.Obfuscate;
import com.kurdish.roleplay.game.ui.AttachEdit;
import com.kurdish.roleplay.game.ui.CustomKeyboard;
import com.kurdish.roleplay.game.ui.Hud;
import com.kurdish.roleplay.game.ui.LoadingScreen;
import com.kurdish.roleplay.game.ui.Speedometer;
import com.kurdish.roleplay.game.ui.dialog.DialogManager;
import com.kurdish.roleplay.game.ui.tab.Tab;
import com.kurdish.roleplay.launcher.util.GameStorage;

import java.io.UnsupportedEncodingException;
import java.nio.charset.StandardCharsets;
import java.util.Locale;

@Obfuscate
public class SAMP extends GTASA implements CustomKeyboard.InputListener, HeightProvider.HeightListener {

    private static final String TAG = "SAMP";
    private static SAMP instance;

    private CustomKeyboard mKeyboard;
    private DialogManager mDialog;
    private HeightProvider mHeightProvider;

    private AttachEdit mAttachEdit;
    private LoadingScreen mLoadingScreen;
    Tab mTab = null;
    Hud mHud = null;
    Speedometer mSpeedometer = null;

    private float mLastDisplayRefreshRate = -1.0f;
    private int mLastEffectiveFPSLimit = -1;

    //java systems
    public void updateSpeedInfo(int speed, int fuel, int hp, int mileage, int engine, int light, int belt, int lock) { runOnUiThread(() -> { mSpeedometer.UpdateSpeedInfo(speed, fuel, hp, mileage, engine, light, belt, lock); }); }

    public void updateHudInfo(int health, int armour, int weaponid, int ammo, int ammoinclip,
                              int money, int eat, int drink, int bankMoney, int playerid) {
        runOnUiThread(() -> { mHud.UpdateHudInfo(health, armour, weaponid, ammo, ammoinclip,
                money, eat, drink, bankMoney, playerid);
        });
    }
    public void showHud() { runOnUiThread(() -> { mHud.ShowHud(); }); }
    public void hideHud() { runOnUiThread(() -> { mHud.HideHud(); }); }

    public void showSpeed() { runOnUiThread(() -> { mSpeedometer.ShowSpeed(); }); }

    public void hideSpeed() { runOnUiThread(() -> { mSpeedometer.HideSpeed(); }); }
    public void showTabWindow() { runOnUiThread(() -> mTab.show(true)); }
    public void setTabStat(int id, String name, int score, int ping) { runOnUiThread(() -> mTab.setStat(id, name, score, ping) ); }

    public native void sendDialogResponse(int i, int i2, int i3, byte[] str);

    public static SAMP getInstance() {
        return instance;
    }

    private native void setDisplayRefreshRate(float refreshRateHz);
    private native int getEffectiveFPSLimit();

    private float getCurrentDisplayRefreshRate() {
        try {
            Display display = null;

            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
                display = getDisplay();
            }

            if (display == null) {
                WindowManager windowManager = (WindowManager) getSystemService(WINDOW_SERVICE);
                if (windowManager != null) {
                    display = windowManager.getDefaultDisplay();
                }
            }

            if (display != null) {
                float refreshRate = display.getRefreshRate();
                if (refreshRate > 1.0f) {
                    return refreshRate;
                }
            }
        } catch (Throwable throwable) {
            Log.w(TAG, "Failed to read display refresh rate", throwable);
        }

        return 60.0f;
    }

    private void syncDisplayRefreshRateLimit(boolean forceShow) {
        float refreshRate = getCurrentDisplayRefreshRate();
        int fallbackLimit = refreshRate >= 119.0f ? 120 : 60;
        int effectiveLimit = fallbackLimit;

        try {
            setDisplayRefreshRate(refreshRate);
            effectiveLimit = getEffectiveFPSLimit();
        } catch (UnsatisfiedLinkError error) {
            Log.e(TAG, "FPS refresh-rate native sync failed: " + error.getMessage());
        }

        String status = String.format(Locale.US,
                "Display Hz: %.2f | FPS Limit: %d",
                refreshRate, effectiveLimit);
        Log.i(TAG, status);

        boolean changed = Math.abs(refreshRate - mLastDisplayRefreshRate) >= 0.5f
                || effectiveLimit != mLastEffectiveFPSLimit;

        if (forceShow || changed) {
            final String toastText = status;
            runOnUiThread(() -> Toast.makeText(this, toastText, Toast.LENGTH_SHORT).show());
        }

        mLastDisplayRefreshRate = refreshRate;
        mLastEffectiveFPSLimit = effectiveLimit;
    }


    private void showLoadingScreen() { }

    private void hideLoadingScreen() {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                mLoadingScreen.hide();
            }
        });
    }

    public void setPauseState(boolean pause) {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if (pause) {
                    mKeyboard.HideInputLayout();
                    mHud.setPaused(true);
                    mSpeedometer.setPaused(true);
                    mTab.setPaused(true);
                    mDialog.hideWithoutReset();
                    mAttachEdit.hideWithoutReset();
                } else {
                    mHud.setPaused(false);
                    mSpeedometer.setPaused(false);
                    mTab.setPaused(false);
                    if (mDialog.isShow)
                        mDialog.showWithOldContent();
                    if (mAttachEdit.isShow)
                        mAttachEdit.showWithoutReset();
                }
            }
        });
    }

    public void exitGame() {
        FirebaseCrashlytics.getInstance().setCrashlyticsCollectionEnabled(false);
        finishAndRemoveTask();
        System.exit(0);
    }

    public void showDialog(int dialogId, int dialogTypeId, byte[] bArr, byte[] bArr2, byte[] bArr3, byte[] bArr4) {
        final String caption     = new String(bArr,  StandardCharsets.UTF_8);
        final String content     = new String(bArr2, StandardCharsets.UTF_8);
        final String leftBtnText = new String(bArr3, StandardCharsets.UTF_8);
        final String rightBtnText= new String(bArr4, StandardCharsets.UTF_8);

        runOnUiThread(() -> {
            this.mDialog.show(dialogId, dialogTypeId, caption, content, leftBtnText, rightBtnText);
        });
    }

    private native void onInputEnd(byte[] str);

    @Override
    public void OnInputEnd(String str) {
        byte[] toReturn = null;

        try {
            toReturn = str.getBytes("windows-1251");
        } catch (UnsupportedEncodingException e) { }

        try {
            onInputEnd(toReturn);
        } catch (UnsatisfiedLinkError e5) {
            Log.e(TAG, e5.getMessage());
        }
    }

    private void showKeyboard() {
        runOnUiThread(() -> {
            Log.d("AXL", "showKeyboard()");
            mKeyboard.ShowInputLayout();
        });
    }

    private void hideKeyboard() {
        runOnUiThread(() -> mKeyboard.HideInputLayout());
    }

    private void showEditObject() {
        runOnUiThread(() -> mAttachEdit.show());
    }

    private void hideEditObject() {
        runOnUiThread(() -> mAttachEdit.hide());
    }


    @Override
    public void onCreate(Bundle savedInstanceState) {
        Log.i(TAG, "**** onCreate");
        super.onCreate(savedInstanceState);

        mKeyboard   = new CustomKeyboard(this);

        mDialog     = new DialogManager(this);

        mAttachEdit = new AttachEdit(this);

        mLoadingScreen = new LoadingScreen(this);

        mHud = new Hud(this);

        mSpeedometer = new Speedometer(this);
        mTab = new Tab(this);
        instance = this;

        try {
            initializeSAMP(GameStorage.getGameBasePath(this));
            syncDisplayRefreshRateLimit(true);
        } catch (UnsatisfiedLinkError e5) {
            Log.e(TAG, e5.getMessage());
        }
    }

    private native void initializeSAMP(String gameBaseDirectory);

    @Override
    public void onStart() {
        Log.i(TAG, "**** onStart");
        super.onStart();
    }

    @Override
    public void onRestart() {
        Log.i(TAG, "**** onRestart");
        super.onRestart();
    }

    @Override
    public void onResume() {
        Log.i(TAG, "**** onResume");
        super.onResume();
        syncDisplayRefreshRateLimit(false);
    }

    public native void onEventBackPressed();

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        onEventBackPressed();
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == KeyEvent.KEYCODE_BACK)
            onEventBackPressed();
        return super.onKeyDown(keyCode, event);
    }


    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        if (hasFocus) {
            syncDisplayRefreshRateLimit(false);
        }
    }

    @Override
    public void onPause() {
        Log.i(TAG, "**** onPause");
        super.onPause();
    }

    @Override
    public void onStop() {
        Log.i(TAG, "**** onStop");
        super.onStop();
    }

    @Override
    public void onDestroy() {
        Log.i(TAG, "**** onDestroy");
        super.onDestroy();
    }

    @Override
    public void onHeightChanged(int orientation, int height) { }
}
