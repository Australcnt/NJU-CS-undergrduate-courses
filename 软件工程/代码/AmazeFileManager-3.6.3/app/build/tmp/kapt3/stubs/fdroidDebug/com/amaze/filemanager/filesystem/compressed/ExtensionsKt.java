package com.amaze.filemanager.filesystem.compressed;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 2, d1 = {"\u0000\f\n\u0000\n\u0002\u0010\u000b\n\u0002\u0018\u0002\n\u0000\u001a\n\u0010\u0000\u001a\u00020\u0001*\u00020\u0002\u00a8\u0006\u0003"}, d2 = {"isPasswordProtectedCompat", "", "Lcom/github/junrar/Archive;", "app_fdroidDebug"})
public final class ExtensionsKt {
    
    /**
     * Extension function to patch [Archive.isPasswordProtected] which uses API that is not available
     * for Android 6.0 or lower.
     *
     * @see [Archive.isPasswordProtected]
     * @see [java.util.stream.Stream]
     * @return true if archive is password protected
     */
    public static final boolean isPasswordProtectedCompat(@org.jetbrains.annotations.NotNull()
    com.github.junrar.Archive $this$isPasswordProtectedCompat) {
        return false;
    }
}