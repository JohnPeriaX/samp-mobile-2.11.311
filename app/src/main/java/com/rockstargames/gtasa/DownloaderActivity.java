package com.rockstargames.gtasa;

import com.kurdish.roleplay.R;
import com.rockstargames.oswrapper.DownloaderActivityBase;
import com.rockstargames.oswrapper.DownloaderConfig;
import com.rockstargames.oswrapper.DownloaderPackConfig;
import com.rockstargames.oswrapper.DownloaderPackType;
import kotlin.Metadata;
import kotlin.collections.CollectionsKt;
public final class DownloaderActivity extends DownloaderActivityBase {
    private final DownloaderConfig config = new DownloaderConfig(
            R.drawable.download_background,
            GameActivity.class,
            CollectionsKt.listOf(new DownloaderPackConfig[] {
                    new DownloaderPackConfig("data_main", R.string.asset_pack_main, DownloaderPackType.INSTALL),
                    new DownloaderPackConfig("data_sfx1", R.string.asset_pack_sfx1, DownloaderPackType.INSTALL),
                    new DownloaderPackConfig("data_sfx2", R.string.asset_pack_sfx2, DownloaderPackType.INSTALL),
                    new DownloaderPackConfig("data_streams", R.string.asset_pack_streams, DownloaderPackType.INSTALL)
            })
    );

    public DownloaderActivity() throws Exception {
    }
    @Override
    protected DownloaderConfig getConfig() {
        return this.config;
    }
}