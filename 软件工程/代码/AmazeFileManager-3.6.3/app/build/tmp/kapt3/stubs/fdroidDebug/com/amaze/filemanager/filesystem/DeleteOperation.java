package com.amaze.filemanager.filesystem;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0007J\u0018\u0010\u000b\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0003R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082D\u00a2\u0006\u0002\n\u0000\u00a8\u0006\f"}, d2 = {"Lcom/amaze/filemanager/filesystem/DeleteOperation;", "", "()V", "LOG", "", "deleteFile", "", "file", "Ljava/io/File;", "context", "Landroid/content/Context;", "rmdir", "app_fdroidDebug"})
public final class DeleteOperation {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.DeleteOperation INSTANCE = null;
    private static final java.lang.String LOG = "DeleteFileOperation";
    
    private DeleteOperation() {
        super();
    }
    
    /**
     * Delete a folder.
     *
     * @param file The folder name.
     * @return true if successful.
     */
    private static final boolean rmdir(java.io.File file, android.content.Context context) {
        return false;
    }
    
    /**
     * Delete a file. May be even on external SD card.
     *
     * @param file the file to be deleted.
     * @return True if successfully deleted.
     */
    public static final boolean deleteFile(@org.jetbrains.annotations.NotNull()
    java.io.File file, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return false;
    }
}