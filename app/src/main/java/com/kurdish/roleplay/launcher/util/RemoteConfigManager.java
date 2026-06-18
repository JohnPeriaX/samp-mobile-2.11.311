package com.kurdish.roleplay.launcher.util;

import com.google.firebase.remoteconfig.FirebaseRemoteConfig;
import com.google.firebase.remoteconfig.FirebaseRemoteConfigSettings;
import android.util.Log;

public class RemoteConfigManager {

    private static FirebaseRemoteConfig remoteConfig;
    private static boolean isInitialized = false;

    // Initialize only once
    private static void init() {
        if (isInitialized) return;

        remoteConfig = FirebaseRemoteConfig.getInstance();

        FirebaseRemoteConfigSettings settings =
                new FirebaseRemoteConfigSettings.Builder()
                        .setMinimumFetchIntervalInSeconds(0)
                        .build();

        remoteConfig.setConfigSettingsAsync(settings);

        // Defaults optional
        // remoteConfig.setDefaultsAsync(R.xml.remote_config_defaults);

        remoteConfig.fetchAndActivate()
                .addOnCompleteListener(task -> {
                    if (task.isSuccessful()) {
                        Log.d("RemoteConfig", "Fetched and activated");
                    } else {
                        Log.w("RemoteConfig", "Fetch failed; local values will be used");
                    }
                });

        isInitialized = true;
    }

    // Get parameter string
    public static String getString(String key) {
        init();
        if (!remoteConfig.getAll().containsKey(key)) {
            Log.w("RemoteConfig", "No local or remote value for key: " + key);
            return "";
        }
        String val = remoteConfig.getString(key);
        return val;
    }
}
