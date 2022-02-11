package com.amaze.filemanager.filesystem;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u0011\n\u0002\b\u0006\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\f\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u001a\u0010\f\u001a\u00020\r2\b\u0010\u000e\u001a\u0004\u0018\u00010\u00042\u0006\u0010\u000f\u001a\u00020\u0010H\u0007J\u0012\u0010\u0011\u001a\u00020\u00122\b\b\u0002\u0010\u0013\u001a\u00020\u0004H\u0007J\u0012\u0010\u0014\u001a\u00020\u00152\b\u0010\u0016\u001a\u0004\u0018\u00010\u0017H\u0007J\u0010\u0010\u0018\u001a\u00020\u00152\u0006\u0010\u0019\u001a\u00020\u0004H\u0007J\u0012\u0010\u001a\u001a\u00020\u00152\b\u0010\u0016\u001a\u0004\u0018\u00010\u0017H\u0007J\u001a\u0010\u001b\u001a\u00020\u00152\b\u0010\u001c\u001a\u0004\u0018\u00010\u00172\u0006\u0010\u001d\u001a\u00020\u0010H\u0007J\u001a\u0010\u001e\u001a\u00020\u00042\u0006\u0010\u001f\u001a\u00020\u00042\b\b\u0002\u0010 \u001a\u00020\u0015H\u0007J\u0012\u0010!\u001a\u0004\u0018\u00010\u00042\u0006\u0010\"\u001a\u00020\u0004H\u0007R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R!\u0010\u0005\u001a\u0010\u0012\f\u0012\n \u0007*\u0004\u0018\u00010\u00040\u00040\u0006\u00a2\u0006\n\n\u0002\u0010\n\u001a\u0004\b\b\u0010\tR\u000e\u0010\u000b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000\u00a8\u0006#"}, d2 = {"Lcom/amaze/filemanager/filesystem/FileProperties;", "", "()V", "COM_ANDROID_EXTERNALSTORAGE_DOCUMENTS", "", "EXCLUDED_DIRS", "", "kotlin.jvm.PlatformType", "getEXCLUDED_DIRS", "()[Ljava/lang/String;", "[Ljava/lang/String;", "STORAGE_PRIMARY", "checkFolder", "", "f", "context", "Landroid/content/Context;", "getDeviceStorageRemainingSpace", "", "volume", "isReadable", "", "file", "Ljava/io/File;", "isValidFilename", "text", "isWritable", "isWritableNormalOrSaf", "folder", "c", "remapPathForApi30OrAbove", "path", "openDocumentTree", "unmapPathForApi30OrAbove", "uriPath", "app_fdroidDebug"})
public final class FileProperties {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.FileProperties INSTANCE = null;
    private static final java.lang.String STORAGE_PRIMARY = "primary";
    private static final java.lang.String COM_ANDROID_EXTERNALSTORAGE_DOCUMENTS = "com.android.externalstorage.documents";
    @org.jetbrains.annotations.NotNull()
    private static final java.lang.String[] EXCLUDED_DIRS = null;
    
    private FileProperties() {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String[] getEXCLUDED_DIRS() {
        return null;
    }
    
    /**
     * Check if a file is readable.
     *
     * @param file The file
     * @return true if the file is reabable.
     */
    public static final boolean isReadable(@org.jetbrains.annotations.Nullable()
    java.io.File file) {
        return false;
    }
    
    /**
     * Check if a file is writable. Detects write issues on external SD card.
     *
     * @param file The file
     * @return true if the file is writable.
     */
    public static final boolean isWritable(@org.jetbrains.annotations.Nullable()
    java.io.File file) {
        return false;
    }
    
    /**
     * Check for a directory if it is possible to create files within this directory, either via
     * normal writing or via Storage Access Framework.
     *
     * @param folder The directory
     * @return true if it is possible to write in this directory.
     */
    public static final boolean isWritableNormalOrSaf(@org.jetbrains.annotations.Nullable()
    java.io.File folder, @org.jetbrains.annotations.NotNull()
    android.content.Context c) {
        return false;
    }
    
    /**
     * Checks whether the target path exists or is writable
     *
     * @param f the target path
     * @return 1 if exists or writable, 0 if not writable
     */
    public static final int checkFolder(@org.jetbrains.annotations.Nullable()
    java.lang.String f, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return 0;
    }
    
    /**
     * Validate given text is a valid filename.
     *
     * @param text
     * @return true if given text is a valid filename
     */
    public static final boolean isValidFilename(@org.jetbrains.annotations.NotNull()
    java.lang.String text) {
        return false;
    }
    
    @org.jetbrains.annotations.Nullable()
    public static final java.lang.String unmapPathForApi30OrAbove(@org.jetbrains.annotations.NotNull()
    java.lang.String uriPath) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String remapPathForApi30OrAbove(@org.jetbrains.annotations.NotNull()
    java.lang.String path, boolean openDocumentTree) {
        return null;
    }
    
    public static final long getDeviceStorageRemainingSpace(@org.jetbrains.annotations.NotNull()
    java.lang.String volume) {
        return 0L;
    }
}