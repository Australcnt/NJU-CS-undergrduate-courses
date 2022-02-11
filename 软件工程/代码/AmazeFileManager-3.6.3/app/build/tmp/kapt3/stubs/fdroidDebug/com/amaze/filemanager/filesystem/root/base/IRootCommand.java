package com.amaze.filemanager.filesystem.root.base;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\b\u0016\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u001c\u0010\u0003\u001a\f\u0012\u0006\u0012\u0004\u0018\u00010\u0005\u0018\u00010\u00042\b\u0010\u0006\u001a\u0004\u0018\u00010\u0005H\u0007J\u0010\u0010\u0007\u001a\u00020\b2\b\u0010\u0006\u001a\u0004\u0018\u00010\u0005J\u0014\u0010\t\u001a\b\u0012\u0004\u0012\u00020\u00050\u00042\u0006\u0010\u0006\u001a\u00020\u0005J\u001a\u0010\n\u001a\u00020\b2\b\u0010\u0006\u001a\u0004\u0018\u00010\u00052\b\u0010\u000b\u001a\u0004\u0018\u00010\f\u00a8\u0006\r"}, d2 = {"Lcom/amaze/filemanager/filesystem/root/base/IRootCommand;", "", "()V", "runNonRootShellCommand", "", "", "cmd", "runShellCommand", "", "runShellCommandToList", "runShellCommandWithCallback", "callback", "Leu/chainfire/libsuperuser/Shell$OnCommandResultListener;", "app_fdroidDebug"})
public class IRootCommand {
    
    public IRootCommand() {
        super();
    }
    
    /**
     * Runs the command and stores output in a list. The listener is set on the handler thread [ ]
     * [MainActivity.handlerThread] thus any code run in callback must be thread safe. Command is run
     * from the root context (u:r:SuperSU0)
     *
     * @param cmd the command
     * @return a list of results. Null only if the command passed is a blocking call or no output is
     * there for the command passed
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.String> runShellCommandToList(@org.jetbrains.annotations.NotNull()
    java.lang.String cmd) {
        return null;
    }
    
    /**
     * Command is run from the root context (u:r:SuperSU0)
     *
     * @param cmd the command
     */
    public final void runShellCommand(@org.jetbrains.annotations.Nullable()
    java.lang.String cmd) throws com.amaze.filemanager.file_operations.exceptions.ShellNotRunningException {
    }
    
    /**
     * Runs the command on an interactive shell. Provides a listener for the caller to interact. The
     * caller is executed on a worker background thread, hence any calls from the callback should be
     * thread safe. Command is run from superuser context (u:r:SuperSU0)
     *
     * @param cmd the command
     */
    public final void runShellCommandWithCallback(@org.jetbrains.annotations.Nullable()
    java.lang.String cmd, @org.jetbrains.annotations.Nullable()
    eu.chainfire.libsuperuser.Shell.OnCommandResultListener callback) throws com.amaze.filemanager.file_operations.exceptions.ShellNotRunningException {
    }
    
    /**
     * @param cmd the command
     * @return a list of results. Null only if the command passed is a blocking call or no output is
     * there for the command passed
     */
    @org.jetbrains.annotations.Nullable()
    @java.lang.Deprecated()
    public final java.util.List<java.lang.String> runNonRootShellCommand(@org.jetbrains.annotations.Nullable()
    java.lang.String cmd) {
        return null;
    }
}