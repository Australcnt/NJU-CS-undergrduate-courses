package com.amaze.filemanager.filesystem.root;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0016\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\u0006\u00a8\u0006\b"}, d2 = {"Lcom/amaze/filemanager/filesystem/root/CopyFilesCommand;", "Lcom/amaze/filemanager/filesystem/root/base/IRootCommand;", "()V", "copyFiles", "", "source", "", "destination", "app_fdroidDebug"})
public final class CopyFilesCommand extends com.amaze.filemanager.filesystem.root.base.IRootCommand {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.root.CopyFilesCommand INSTANCE = null;
    
    private CopyFilesCommand() {
        super();
    }
    
    /**
     * Copies files using root
     * @param source given source
     * @param destination given destination
     */
    public final void copyFiles(@org.jetbrains.annotations.NotNull()
    java.lang.String source, @org.jetbrains.annotations.NotNull()
    java.lang.String destination) throws com.amaze.filemanager.file_operations.exceptions.ShellNotRunningException {
    }
}