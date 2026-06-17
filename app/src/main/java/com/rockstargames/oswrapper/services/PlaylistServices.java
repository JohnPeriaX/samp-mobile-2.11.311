package com.rockstargames.oswrapper.services;

import android.util.Log;
import com.rockstargames.oswrapper.GameView;

import kotlin.jvm.internal.Intrinsics;

public final class PlaylistServices implements IPlaylistServices {
    private static final String TAG = "PlaylistServices";
    private final GameView view;

    public PlaylistServices(GameView view) {
        Intrinsics.checkNotNullParameter(view, "view");
        this.view = view;
    }
    @Override
    public int playlistCount() {
        return this.view.getPlaylistHandler().getCount();
    }
    @Override
    public boolean playlistIsPlaying() {
        return this.view.getPlaylistHandler().isPlaying();
    }
    @Override
    public void playlistOpen(String name) {
        Intrinsics.checkNotNullParameter(name, "name");
        Log.i(TAG, "[!!] playlistOpen: " + name);
        this.view.getPlaylistHandler().open(name);
    }
    @Override
    public void playlistPause() {
        Log.i(TAG, "[!!] playlistPause");
        this.view.getPlaylistHandler().pause();
    }
    @Override
    public void playlistPlay() {
        Log.i(TAG, "[!!] playlistPlay");
        this.view.getPlaylistHandler().play();
    }
    @Override
    public void playlistSetVolume(float volume) {
        Log.i(TAG, "[!!] playlistSetVolume: " + volume);
        this.view.getPlaylistHandler().setVolume(volume);
    }
    @Override
    public void playlistStop() {
        Log.i(TAG, "[!!] playlistStop");
        this.view.getPlaylistHandler().stop();
    }
}
