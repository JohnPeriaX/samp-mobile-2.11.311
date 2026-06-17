package com.rockstargames.oswrapper.services;

import com.rockstargames.oswrapper.GameView;
import kotlin.jvm.internal.Intrinsics;

public final class SplashScreenServices implements ISplashScreenServices {
    private final GameView view;

    public SplashScreenServices(GameView view) {
        Intrinsics.checkNotNullParameter(view, "view");
        this.view = view;
    }

    public final GameView getView() {
        return this.view;
    }
    @Override
    public void hideSplashScreen() {
        this.view.getSplashScreenHandler().hide();
    }
    @Override
    public boolean isSplashScreenVisible() {
        return this.view.getSplashScreenHandler().getVisible();
    }
    @Override
    public void setSplashImage(String filename) {
        Intrinsics.checkNotNullParameter(filename, "filename");
        this.view.getSplashScreenHandler().setImage(filename);
    }
    @Override
    public void setSplashText(String text) {
        Intrinsics.checkNotNullParameter(text, "text");
        this.view.getSplashScreenHandler().setText(text);
    }
    @Override
    public void showSplashScreen() {
        this.view.getSplashScreenHandler().show();
    }
}
