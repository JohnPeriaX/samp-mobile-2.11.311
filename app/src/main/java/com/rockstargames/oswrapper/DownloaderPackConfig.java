package com.rockstargames.oswrapper;

public final class DownloaderPackConfig {

    private final String id;
    private final int labelId;
    private final DownloaderPackType manifestType;

    public DownloaderPackConfig(String id, int labelId, DownloaderPackType manifestType) {
        if (id   == null) throw new NullPointerException("id is null");
        if (manifestType == null) throw new NullPointerException("manifestType is null");
        this.id           = id;
        this.labelId      = labelId;
        this.manifestType = manifestType;
    }

    public String getId()            { return id;      }
    public int    getLabelId()       { return labelId; }
    public DownloaderPackType getType() {
        String forcedType = BuildConfig.GAME_FORCE_ASSET_PACK_TYPE;
        if ("install-time".equals(forcedType)) {
            return DownloaderPackType.INSTALL;
        }
        if ("on-demand".equals(forcedType) || "fast-follow".equals(forcedType)) {
            return DownloaderPackType.RUNTIME;
        }
        return manifestType;
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) return true;
        if (!(other instanceof DownloaderPackConfig)) return false;
        DownloaderPackConfig o = (DownloaderPackConfig) other;
        return id.equals(o.id) && labelId == o.labelId && manifestType == o.manifestType;
    }

    @Override
    public int hashCode() {
        int result = id.hashCode();
        result = 31 * result + Integer.hashCode(labelId);
        result = 31 * result + manifestType.hashCode();
        return result;
    }

    @Override
    public String toString() {
        return "DownloaderPackConfig(id=" + id
                + ", labelId=" + labelId
                + ", manifestType=" + manifestType + ')';
    }
}
