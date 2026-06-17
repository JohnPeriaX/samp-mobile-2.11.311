package com.rockstargames.oswrapper.view;

import android.graphics.PointF;
import android.hardware.input.InputManager;
import android.util.Log;
import android.util.SparseArray;
import android.util.SparseIntArray;
import android.view.InputDevice;
import android.view.InputEvent;
import android.view.KeyEvent;
import android.view.MotionEvent;

import com.rockstargames.oswrapper.GameActivityBase;
import com.rockstargames.oswrapper.GameThread;
import com.rockstargames.oswrapper.UtilsKt;

import java.util.ArrayList;
import kotlin.jvm.internal.Intrinsics;

public class InputHandler implements GameViewHandler, InputManager.InputDeviceListener {

    public static  InputHandler INSTANCE = new InputHandler();

    private static   String TAG = "GameView.InputHandler";

    // Xbox 360 button mappings
    private static   int OSX360_A         = 0;
    private static   int OSX360_B         = 1;
    private static   int OSX360_X         = 2;
    private static   int OSX360_Y         = 3;
    private static   int OSX360_START     = 4;
    private static   int OSX360_BACK      = 5;
    private static   int OSX360_L1        = 6;
    private static   int OSX360_R1        = 7;
    private static   int OSX360_DPADUP    = 8;
    private static   int OSX360_DPADDOWN  = 9;
    private static   int OSX360_DPADLEFT  = 10;
    private static   int OSX360_DPADRIGHT = 11;
    private static   int OSX360_L3        = 12;
    private static   int OSX360_R3        = 13;

    // OSX Platform buttons
    private static   int OSXP_BACK    = 14;
    private static   int OSXP_GP_MENU = 15;
    private static   int OSXP_MENU    = 12;
    private static   int OSXP_SEARCH  = 13;
    private static final int MAX_TOUCH_POINTERS = 4;

    private boolean dpadUpPressed;
    private boolean dpadDownPressed;
    private boolean dpadLeftPressed;
    private boolean dpadRightPressed;
    private boolean processing;

    private   SparseArray<PointF> touches = new SparseArray<>();
    private final SparseIntArray pointerSlots = new SparseIntArray();
    private InputManager inputManager;

    private InputHandler() {}

    // -----------------------------------------------------------------------
    // Controller helpers
    // -----------------------------------------------------------------------

    private boolean isGamepad(InputDevice device) {
        return device != null && device.getControllerNumber() > 0 && (device.getSources() & 16778257) != 0;
    }

    private boolean isGamepad(int deviceId) {
        return inputManager != null && isGamepad(inputManager.getInputDevice(deviceId));
    }

    private boolean isGamepadEvent(InputEvent event) {
        return event != null && isGamepad(event.getDevice());
    }

    private int[] getConnectedGamepads() {
        int[] deviceIds = InputDevice.getDeviceIds();
        Intrinsics.checkNotNullExpressionValue(deviceIds, "getDeviceIds(...)");
        ArrayList<Integer> connected = new ArrayList<>();
        for (int i : deviceIds) {
            if (isGamepad(i)) {
                connected.add(i);
            }
        }
        int[] result = new int[connected.size()];
        for (int i = 0; i < connected.size(); i++) {
            result[i] = connected.get(i);
        }
        return result;
    }


    // -----------------------------------------------------------------------
    // Key mapping
    // -----------------------------------------------------------------------

    private final int toGamepadButton(int keyCode) {
        if (keyCode == 4) {
            return 14;
        }
        if (keyCode == 82) {
            return 15;
        }
        if (keyCode == 110) {
            return 4;
        }
        if (keyCode == 96) {
            return 0;
        }
        if (keyCode == 97) {
            return 1;
        }
        if (keyCode == 99) {
            return 2;
        }
        if (keyCode == 100) {
            return 3;
        }
        if (keyCode == 102) {
            return 6;
        }
        if (keyCode == 103) {
            return 7;
        }
        switch (keyCode) {
            case 106:
                return 12;
            case 107:
                return 13;
            case 108:
                return 4;
            default:
                return -1;
        }
    }


    // -----------------------------------------------------------------------
    // Back button
    // -----------------------------------------------------------------------

    private void onBackPressed() {
        Log.i(TAG, "[!!] onBackPressed");
        GameThread.INSTANCE.onBackButtonPressed();
    }

    // -----------------------------------------------------------------------
    // Key events
    // -----------------------------------------------------------------------

    public boolean onKeyDown(int keyCode, KeyEvent event) {
        boolean isGamepad = isGamepadEvent(event);
        if (keyCode == 4 && !isGamepad) {
            return true; // consume, handle on up
        }
        int button = toGamepadButton(keyCode);
        if (event == null || button == -1) return false;
        GameThread.INSTANCE.onGamepadButtonDown(event.getDeviceId(), button);
        return true;
    }

    public boolean onKeyUp(int keyCode, KeyEvent event) {
        boolean isGamepad = isGamepadEvent(event);
        if (keyCode == 4 && !isGamepad) {
            onBackPressed();
            return true;
        }
        int button = toGamepadButton(keyCode);
        if (event == null || button == -1) return false;
        GameThread.INSTANCE.onGamepadButtonUp(event.getDeviceId(), button);
        return true;
    }

    // -----------------------------------------------------------------------
    // Gamepad axes / motion
    // -----------------------------------------------------------------------

    public final boolean onGenericMotionEvent(MotionEvent event) {
        if (!processing || event == null || !isGamepadEvent(event)) {
            return false;
        }
        int deviceId = event.getDeviceId();
        float axisValue = event.getAxisValue(0);
        float axisValue2 = event.getAxisValue(1);
        float axisValue3 = event.getAxisValue(11);
        float axisValue4 = event.getAxisValue(14);
        float axisValue5 = event.getAxisValue(15);
        float axisValue6 = event.getAxisValue(16);
        if (axisValue5 > 0.2f) {
            GameThread.INSTANCE.onGamepadButtonDown(deviceId, 11);
            this.dpadRightPressed = true;
        } else if (axisValue5 < -0.2f) {
            GameThread.INSTANCE.onGamepadButtonDown(deviceId, 10);
            this.dpadLeftPressed = true;
        } else {
            if (this.dpadLeftPressed) {
                GameThread.INSTANCE.onGamepadButtonUp(deviceId, 10);
            }
            if (this.dpadRightPressed) {
                GameThread.INSTANCE.onGamepadButtonUp(deviceId, 11);
            }
            this.dpadLeftPressed = false;
            this.dpadRightPressed = false;
        }
        if (axisValue6 < -0.2f) {
            GameThread.INSTANCE.onGamepadButtonDown(deviceId, 8);
            this.dpadUpPressed = true;
        } else if (axisValue6 > 0.2f) {
            GameThread.INSTANCE.onGamepadButtonDown(deviceId, 9);
            this.dpadDownPressed = true;
        } else {
            if (this.dpadUpPressed) {
                GameThread.INSTANCE.onGamepadButtonUp(deviceId, 8);
            }
            if (this.dpadDownPressed) {
                GameThread.INSTANCE.onGamepadButtonUp(deviceId, 9);
            }
            this.dpadUpPressed = false;
            this.dpadDownPressed = false;
        }
        float fMax3 = UtilsKt.max3(event.getAxisValue(18), event.getAxisValue(19), event.getAxisValue(22));
        GameThread.INSTANCE.onGamepadAxesChanged(deviceId, axisValue, axisValue2, axisValue3, axisValue4, Math.max(event.getAxisValue(17), event.getAxisValue(23)), fMax3);
        return true;
    }


    // -----------------------------------------------------------------------
    // Touch events
    // -----------------------------------------------------------------------

    private int acquireTouchSlot(int pointerId) {
        int currentSlot = this.pointerSlots.get(pointerId, -1);
        if (currentSlot != -1) {
            return currentSlot;
        }
        for (int slot = 0; slot < MAX_TOUCH_POINTERS; slot++) {
            if (this.touches.get(slot) == null) {
                this.pointerSlots.put(pointerId, slot);
                return slot;
            }
        }
        return -1;
    }

    private int getTouchSlot(int pointerId) {
        return this.pointerSlots.get(pointerId, -1);
    }

    private void releaseTouchSlot(int pointerId) {
        this.pointerSlots.delete(pointerId);
    }

    public final boolean onTouchEvent(MotionEvent event) {
        Intrinsics.checkNotNullParameter(event, "event");
        int actionIndex = event.getActionIndex();
        int pointerId = event.getPointerId(actionIndex);
        int i = 0;
        switch (event.getActionMasked()) {
            case 0:
            case 5:
                int slot = acquireTouchSlot(pointerId);
                if (slot == -1) {
                    return true;
                }
                float x = event.getX(actionIndex);
                float y = event.getY(actionIndex);
                PointF pointF = new PointF();
                pointF.x = x;
                pointF.y = y;
                this.touches.put(slot, pointF);
                GameThread.INSTANCE.onTouchStart(slot, x, y);
                return true;
            case 1:
            case 4:
            case 6:
                int releasedSlot = getTouchSlot(pointerId);
                if (releasedSlot == -1) {
                    return true;
                }
                PointF pointF2 = this.touches.get(releasedSlot);
                if (pointF2 != null) {
                    GameThread.INSTANCE.onTouchEnd(releasedSlot, pointF2.x, pointF2.y);
                }
                this.touches.remove(releasedSlot);
                releaseTouchSlot(pointerId);
                return true;
            case 2:
                while (i < event.getPointerCount()) {
                    int pointerId2 = event.getPointerId(i);
                    int moveSlot = getTouchSlot(pointerId2);
                    if (moveSlot == -1) {
                        moveSlot = acquireTouchSlot(pointerId2);
                    }
                    if (moveSlot == -1) {
                        i++;
                        continue;
                    }
                    float x2 = event.getX(i);
                    float y2 = event.getY(i);
                    PointF pointF3 = new PointF();
                    pointF3.x = x2;
                    pointF3.y = y2;
                    this.touches.put(moveSlot, pointF3);
                    GameThread.INSTANCE.onTouchMove(moveSlot, x2, y2);
                    i++;
                }
                return true;
            case 3:
                while (i < this.touches.size()) {
                    int slotKey = this.touches.keyAt(i);
                    PointF pointF4 = this.touches.get(slotKey);
                    if (pointF4 != null) {
                        GameThread.INSTANCE.onTouchEnd(slotKey, pointF4.x, pointF4.y);
                    }
                    i++;
                }
                this.touches.clear();
                this.pointerSlots.clear();
                return true;
            default:
                return false;
        }
    }



    // -----------------------------------------------------------------------
    // GameViewHandler
    // -----------------------------------------------------------------------

    @Override
    public void setup(GameActivityBase activity) {
        Intrinsics.checkNotNullParameter(activity, "activity");
        Object service = activity.getSystemService(InputManager.class);
        if (service instanceof InputManager) {
            this.inputManager = (InputManager) service;
        }
    }

    @Override
    public void onPause() {
        this.processing = false;
        if (this.inputManager != null) {
            this.inputManager.unregisterInputDeviceListener(this);
        }
    }

    @Override
    public void onResume() {
        this.processing = true;
        if (this.inputManager != null) {
            this.inputManager.registerInputDeviceListener(this, null);
        }
        GameThread.INSTANCE.onGamepadResume(getConnectedGamepads());
    }

    @Override
    public void onInputDeviceAdded(int deviceId) {
        if (this.processing && isGamepad(deviceId)) {
            InputDevice device = this.inputManager != null ? this.inputManager.getInputDevice(deviceId) : null;
            Log.i(TAG, "[!!] [pad] Newly connected gamepad: " + deviceId + ": " + (device != null ? device.getName() : "unknown"));
            GameThread.INSTANCE.onGamepadConnected(deviceId);
        }
    }

    @Override
    public void onInputDeviceChanged(int deviceId) {
        onInputDeviceAdded(deviceId);
    }

    @Override
    public void onInputDeviceRemoved(int deviceId) {
        if (this.processing) {
            Log.i(TAG, "[!!] [pad] Disconnected gamepad: " + deviceId);
            GameThread.INSTANCE.onGamepadDisconnected(deviceId);
        }
    }

    // -----------------------------------------------------------------------
    // Helpers
    // -----------------------------------------------------------------------

    private static float max3(float a, float b, float c) {
        return Math.max(a, Math.max(b, c));
    }
}
