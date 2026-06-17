package com.rockstargames.oswrapper.services;

import com.rockstargames.oswrapper.GameActivityBase;
import kotlin.jvm.internal.Intrinsics;

public class LanguageServices implements ILanguageServices {
    private static String TAG = "LanguageServices";
    private GameActivityBase activity;

    public LanguageServices(GameActivityBase activity) {
        Intrinsics.checkNotNullParameter(activity, "activity");
        this.activity = activity;
    }

    @Override
    public int getDeviceLocale() {
        try {
            String language = java.util.Locale.getDefault().getLanguage();

            if (language.equals("en")) return 0;
            if (language.equals("fr")) return 1;
            if (language.equals("de")) return 2;
            if (language.equals("it")) return 3;
            if (language.equals("es")) return 4;
            if (language.equals("ru")) return 5;
            if (language.equals("ja")) return 6;

            return 0;
        } catch (Exception e) {
            return 0;
        }
    }
}
