package com.amaze.filemanager.filesystem.root;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u000e\n\u0000\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006\u00a8\u0006\u0007"}, d2 = {"Lcom/amaze/filemanager/filesystem/root/DeleteFileCommand;", "Lcom/amaze/filemanager/filesystem/root/base/IRootCommand;", "()V", "deleteFile", "", "path", "", "app_fdroidDebug"})
public final class DeleteFileCommand extends com.amaze.filemanager.filesystem.root.base.IRootCommand {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.root.DeleteFileCommand INSTANCE = null;
    
    private DeleteFileCommand() {
        super();
    }
    
    /**
     * Recursively removes a path with it's contents (if any)
     *
     * @return boolean whether file was deleted or not
     */
    public final boolean deleteFile(@org.jetbrains.annotations.NotNull()
    java.lang.String path) throws com.amaze.filemanager.file_operations.exceptions.ShellNotRunningException {
        return false;
    }
}