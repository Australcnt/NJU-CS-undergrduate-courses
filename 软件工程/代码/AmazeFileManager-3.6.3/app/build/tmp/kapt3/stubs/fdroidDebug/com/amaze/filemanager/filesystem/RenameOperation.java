package com.amaze.filemanager.filesystem;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0006\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J \u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\b2\u0006\u0010\n\u001a\u00020\u000bH\u0003J \u0010\f\u001a\u00020\u00062\u0006\u0010\r\u001a\u00020\b2\u0006\u0010\u000e\u001a\u00020\u00042\u0006\u0010\u000f\u001a\u00020\u0006H\u0003J \u0010\u0010\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\b2\u0006\u0010\n\u001a\u00020\u000bH\u0007R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082D\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0011"}, d2 = {"Lcom/amaze/filemanager/filesystem/RenameOperation;", "", "()V", "LOG", "", "copyFile", "", "source", "Ljava/io/File;", "target", "context", "Landroid/content/Context;", "rename", "f", "name", "root", "renameFolder", "app_fdroidDebug"})
public final class RenameOperation {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.RenameOperation INSTANCE = null;
    private static final java.lang.String LOG = "RenameOperation";
    
    private RenameOperation() {
        super();
    }
    
    /**
     * Copy a file. The target file may even be on external SD card for Kitkat.
     *
     * @param source The source file
     * @param target The target file
     * @return true if the copying was successful.
     */
    private static final boolean copyFile(java.io.File source, java.io.File target, android.content.Context context) {
        return false;
    }
    
    private static final boolean rename(java.io.File f, java.lang.String name, boolean root) throws com.amaze.filemanager.file_operations.exceptions.ShellNotRunningException {
        return false;
    }
    
    /**
     * Rename a folder. In case of extSdCard in Kitkat, the old folder stays in place, but files are
     * moved.
     *
     * @param source The source folder.
     * @param target The target folder.
     * @return true if the renaming was successful.
     */
    public static final boolean renameFolder(@org.jetbrains.annotations.NotNull()
    java.io.File source, @org.jetbrains.annotations.NotNull()
    java.io.File target, @org.jetbrains.annotations.NotNull()
    android.content.Context context) throws com.amaze.filemanager.file_operations.exceptions.ShellNotRunningException {
        return false;
    }
}