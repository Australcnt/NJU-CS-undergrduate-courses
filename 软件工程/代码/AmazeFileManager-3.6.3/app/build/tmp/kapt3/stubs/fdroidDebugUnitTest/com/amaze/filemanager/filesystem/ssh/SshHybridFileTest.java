package com.amaze.filemanager.filesystem.ssh;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\b\u0007\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0007\u001a\u00020\bH\u0007J\b\u0010\t\u001a\u00020\bH\u0007J\b\u0010\n\u001a\u00020\bH\u0007R\u0010\u0010\u0003\u001a\u0004\u0018\u00010\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082D\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u000b"}, d2 = {"Lcom/amaze/filemanager/filesystem/ssh/SshHybridFileTest;", "", "()V", "ctx", "Landroid/content/Context;", "path", "", "setUp", "", "testCanDelete", "testCannotDelete", "app_fdroidDebug"})
@org.robolectric.annotation.Config(shadows = {com.amaze.filemanager.shadows.ShadowMultiDex.class, com.amaze.filemanager.test.ShadowCryptUtil.class}, sdk = {16, 19, 28})
@org.robolectric.annotation.LooperMode(value = org.robolectric.annotation.LooperMode.Mode.PAUSED)
@org.junit.runner.RunWith(value = androidx.test.ext.junit.runners.AndroidJUnit4.class)
public final class SshHybridFileTest {
    private android.content.Context ctx;
    private final java.lang.String path = "ssh://user:password@127.0.0.1:22222/test.file";
    
    public SshHybridFileTest() {
        super();
    }
    
    /**
     * Test case setup.
     *
     * TODO: some even more generic test case base to prevent copy-and-paste?
     */
    @org.junit.Before()
    public final void setUp() {
    }
    
    /**
     * Test case to verify delete SSH file success scenario.
     */
    @org.junit.Test()
    public final void testCanDelete() {
    }
    
    /**
     * Test case to verify delete SSH file failure scenario.
     */
    @org.junit.Test()
    public final void testCannotDelete() {
    }
}