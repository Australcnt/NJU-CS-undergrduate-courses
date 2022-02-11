package com.amaze.filemanager.filesystem;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0005\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\b2\u0006\u0010\n\u001a\u00020\u000bH\u0007J\u001a\u0010\f\u001a\u00020\r2\b\u0010\t\u001a\u0004\u0018\u00010\b2\u0006\u0010\n\u001a\u00020\u000bH\u0007J$\u0010\u000e\u001a\u00020\r2\b\u0010\u000f\u001a\u0004\u0018\u00010\u00042\b\u0010\u0010\u001a\u0004\u0018\u00010\u00042\u0006\u0010\u0011\u001a\u00020\u0004H\u0007R\u0014\u0010\u0003\u001a\u00020\u0004X\u0086D\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006\u00a8\u0006\u0012"}, d2 = {"Lcom/amaze/filemanager/filesystem/MakeFileOperation;", "", "()V", "LOG", "", "getLOG", "()Ljava/lang/String;", "getTempFile", "Ljava/io/File;", "file", "context", "Landroid/content/Context;", "mkfile", "", "mktextfile", "data", "path", "fileName", "app_fdroidDebug"})
public final class MakeFileOperation {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.MakeFileOperation INSTANCE = null;
    @org.jetbrains.annotations.NotNull()
    private static final java.lang.String LOG = "MakeFileOperation";
    
    private MakeFileOperation() {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getLOG() {
        return null;
    }
    
    /**
     * Get a temp file.
     *
     * @param file The base file for which to create a temp file.
     * @return The temp file.
     */
    @org.jetbrains.annotations.NotNull()
    public static final java.io.File getTempFile(@org.jetbrains.annotations.NotNull()
    java.io.File file, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return null;
    }
    
    public static final boolean mkfile(@org.jetbrains.annotations.Nullable()
    java.io.File file, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return false;
    }
    
    public static final boolean mktextfile(@org.jetbrains.annotations.Nullable()
    java.lang.String data, @org.jetbrains.annotations.Nullable()
    java.lang.String path, @org.jetbrains.annotations.NotNull()
    java.lang.String fileName) {
        return false;
    }
}