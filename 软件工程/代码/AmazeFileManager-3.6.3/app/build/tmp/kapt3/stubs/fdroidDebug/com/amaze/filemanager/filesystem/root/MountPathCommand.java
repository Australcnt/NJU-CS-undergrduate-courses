package com.amaze.filemanager.filesystem.root;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0006\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\u0006\u001a\u0004\u0018\u00010\u00042\u0006\u0010\u0007\u001a\u00020\u00042\u0006\u0010\b\u001a\u00020\u0004J\u0012\u0010\t\u001a\u0004\u0018\u00010\u00042\u0006\u0010\u0007\u001a\u00020\u0004H\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000\u00a8\u0006\n"}, d2 = {"Lcom/amaze/filemanager/filesystem/root/MountPathCommand;", "Lcom/amaze/filemanager/filesystem/root/base/IRootCommand;", "()V", "READ_ONLY", "", "READ_WRITE", "mountPath", "path", "operation", "mountReadWrite", "app_fdroidDebug"})
public final class MountPathCommand extends com.amaze.filemanager.filesystem.root.base.IRootCommand {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.root.MountPathCommand INSTANCE = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String READ_ONLY = "RO";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String READ_WRITE = "RW";
    
    private MountPathCommand() {
        super();
    }
    
    /**
     * Mount filesystem associated with path for writable access (rw) Since we don't have the root of
     * filesystem to remount, we need to parse output of # mount command.
     *
     * @param path the path on which action to perform
     * @param operation RO or RW
     * @return String the root of mount point that was ro, and mounted to rw; null otherwise
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String mountPath(@org.jetbrains.annotations.NotNull()
    java.lang.String path, @org.jetbrains.annotations.NotNull()
    java.lang.String operation) throws com.amaze.filemanager.file_operations.exceptions.ShellNotRunningException {
        return null;
    }
    
    private final java.lang.String mountReadWrite(java.lang.String path) {
        return null;
    }
}