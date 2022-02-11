package com.amaze.filemanager.filesystem.ssh.test;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\fH\u0002J\u0006\u0010\r\u001a\u00020\nJ\u0006\u0010\u000e\u001a\u00020\nR\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0005\u001a\n \u0007*\u0004\u0018\u00010\u00060\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\b\u001a\n \u0007*\u0004\u0018\u00010\u00060\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u000f"}, d2 = {"Lcom/amaze/filemanager/filesystem/ssh/test/MockSshConnectionPools;", "", "()V", "ACCESS_DENIED", "", "hostKeyPair", "Ljava/security/KeyPair;", "kotlin.jvm.PlatformType", "userKeyPair", "doPrepareSSHClientInternal", "", "canDelete", "", "prepareCanDeleteScenario", "prepareCannotDeleteScenario", "app_fdroidDebug"})
public final class MockSshConnectionPools {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.ssh.test.MockSshConnectionPools INSTANCE = null;
    private static final java.lang.String ACCESS_DENIED = "Access is denied.";
    private static final java.security.KeyPair hostKeyPair = null;
    private static final java.security.KeyPair userKeyPair = null;
    
    private MockSshConnectionPools() {
        super();
    }
    
    public final void prepareCanDeleteScenario() {
    }
    
    public final void prepareCannotDeleteScenario() {
    }
    
    private final void doPrepareSSHClientInternal(boolean canDelete) {
    }
}