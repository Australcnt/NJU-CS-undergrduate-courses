package com.amaze.filemanager.filesystem;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0011\n\u0002\b\u0005\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\"\u0010\u0007\u001a\u0004\u0018\u00010\b2\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000eH\u0007J\u001a\u0010\u000f\u001a\u0004\u0018\u00010\u00042\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\r\u001a\u00020\u000eH\u0007J\u001b\u0010\u0010\u001a\b\u0012\u0004\u0012\u00020\u00040\u00112\u0006\u0010\r\u001a\u00020\u000eH\u0003\u00a2\u0006\u0002\u0010\u0012J\u001b\u0010\u0013\u001a\b\u0012\u0004\u0012\u00020\u00040\u00112\u0006\u0010\r\u001a\u00020\u000eH\u0007\u00a2\u0006\u0002\u0010\u0012J\u0018\u0010\u0014\u001a\u00020\f2\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u0015\u001a\u00020\u000eH\u0007R\u0014\u0010\u0003\u001a\u00020\u0004X\u0086D\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006\u00a8\u0006\u0016"}, d2 = {"Lcom/amaze/filemanager/filesystem/ExternalSdCardOperation;", "", "()V", "LOG", "", "getLOG", "()Ljava/lang/String;", "getDocumentFile", "Landroidx/documentfile/provider/DocumentFile;", "file", "Ljava/io/File;", "isDirectory", "", "context", "Landroid/content/Context;", "getExtSdCardFolder", "getExtSdCardPaths", "", "(Landroid/content/Context;)[Ljava/lang/String;", "getExtSdCardPathsForActivity", "isOnExtSdCard", "c", "app_fdroidDebug"})
public final class ExternalSdCardOperation {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.ExternalSdCardOperation INSTANCE = null;
    @org.jetbrains.annotations.NotNull()
    private static final java.lang.String LOG = "ExternalSdCardOperation";
    
    private ExternalSdCardOperation() {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getLOG() {
        return null;
    }
    
    /**
     * Get a DocumentFile corresponding to the given file (for writing on ExtSdCard on Android 5). If
     * the file is not existing, it is created.
     *
     * @param file The file.
     * @param isDirectory flag indicating if the file should be a directory.
     * @return The DocumentFile
     */
    @org.jetbrains.annotations.Nullable()
    public static final androidx.documentfile.provider.DocumentFile getDocumentFile(@org.jetbrains.annotations.NotNull()
    java.io.File file, boolean isDirectory, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return null;
    }
    
    /**
     * Get a list of external SD card paths. (Kitkat or higher.)
     *
     * @return A list of external SD card paths.
     */
    @android.annotation.TargetApi(value = android.os.Build.VERSION_CODES.KITKAT)
    private static final java.lang.String[] getExtSdCardPaths(android.content.Context context) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @android.annotation.TargetApi(value = android.os.Build.VERSION_CODES.KITKAT)
    public static final java.lang.String[] getExtSdCardPathsForActivity(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return null;
    }
    
    /**
     * Determine the main folder of the external SD card containing the given file.
     *
     * @param file the file.
     * @return The main folder of the external SD card containing this file, if the file is on an SD
     * card. Otherwise, null is returned.
     */
    @org.jetbrains.annotations.Nullable()
    @android.annotation.TargetApi(value = android.os.Build.VERSION_CODES.KITKAT)
    public static final java.lang.String getExtSdCardFolder(@org.jetbrains.annotations.NotNull()
    java.io.File file, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return null;
    }
    
    /**
     * Determine if a file is on external sd card. (Kitkat or higher.)
     *
     * @param file The file.
     * @return true if on external sd card.
     */
    @android.annotation.TargetApi(value = android.os.Build.VERSION_CODES.KITKAT)
    public static final boolean isOnExtSdCard(@org.jetbrains.annotations.NotNull()
    java.io.File file, @org.jetbrains.annotations.NotNull()
    android.content.Context c) {
        return false;
    }
}