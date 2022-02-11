package com.amaze.filemanager.filesystem;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u001a\u0010\u0003\u001a\u00020\u00042\b\u0010\u0005\u001a\u0004\u0018\u00010\u00062\u0006\u0010\u0007\u001a\u00020\bH\u0007J\u0018\u0010\t\u001a\u00020\u00042\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\u0005\u001a\u00020\nH\u0007\u00a8\u0006\u000b"}, d2 = {"Lcom/amaze/filemanager/filesystem/MakeDirectoryOperation;", "", "()V", "mkdir", "", "file", "Ljava/io/File;", "context", "Landroid/content/Context;", "mkdirs", "Lcom/amaze/filemanager/filesystem/HybridFile;", "app_fdroidDebug"})
public final class MakeDirectoryOperation {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.MakeDirectoryOperation INSTANCE = null;
    
    private MakeDirectoryOperation() {
        super();
    }
    
    /**
     * Create a folder. The folder may even be on external SD card for Kitkat.
     *
     * @param file The folder to be created.
     * @return True if creation was successful.
     */
    @java.lang.Deprecated()
    public static final boolean mkdir(@org.jetbrains.annotations.Nullable()
    java.io.File file, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return false;
    }
    
    public static final boolean mkdirs(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.filesystem.HybridFile file) {
        return false;
    }
}