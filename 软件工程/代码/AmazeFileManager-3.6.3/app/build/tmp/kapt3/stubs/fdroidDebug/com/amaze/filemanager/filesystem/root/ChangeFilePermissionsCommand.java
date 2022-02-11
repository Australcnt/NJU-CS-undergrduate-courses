package com.amaze.filemanager.filesystem.root;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J2\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\u00042\u0006\u0010\b\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\u000b2\u0012\u0010\f\u001a\u000e\u0012\u0004\u0012\u00020\u000b\u0012\u0004\u0012\u00020\u00060\rR\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u000e"}, d2 = {"Lcom/amaze/filemanager/filesystem/root/ChangeFilePermissionsCommand;", "Lcom/amaze/filemanager/filesystem/root/base/IRootCommand;", "()V", "CHMOD_COMMAND", "", "changeFilePermissions", "", "filePath", "updatedPermissions", "", "isDirectory", "", "onOperationPerform", "Lkotlin/Function1;", "app_fdroidDebug"})
public final class ChangeFilePermissionsCommand extends com.amaze.filemanager.filesystem.root.base.IRootCommand {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.root.ChangeFilePermissionsCommand INSTANCE = null;
    private static final java.lang.String CHMOD_COMMAND = "chmod %s %o \"%s\"";
    
    private ChangeFilePermissionsCommand() {
        super();
    }
    
    /**
     * Change permissions for a given file path - requires root
     *
     * @param filePath given file path
     * @param updatedPermissions octal notation for permissions
     * @param isDirectory is given path a directory or file
     */
    public final void changeFilePermissions(@org.jetbrains.annotations.NotNull()
    java.lang.String filePath, int updatedPermissions, boolean isDirectory, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super java.lang.Boolean, kotlin.Unit> onOperationPerform) {
    }
}