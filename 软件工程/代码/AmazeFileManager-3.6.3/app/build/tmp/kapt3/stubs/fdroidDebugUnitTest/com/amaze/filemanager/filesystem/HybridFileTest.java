package com.amaze.filemanager.filesystem;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0003\b\u0007\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0003\u001a\u00020\u0004H\u0007J\b\u0010\u0005\u001a\u00020\u0004H\u0007J\b\u0010\u0006\u001a\u00020\u0004H\u0007\u00a8\u0006\u0007"}, d2 = {"Lcom/amaze/filemanager/filesystem/HybridFileTest;", "", "()V", "testGetParentGeneric", "", "testSshGetParentWithTrailingSlash", "testSshGetParentWithoutTrailingSlash", "app_fdroidDebug"})
@org.robolectric.annotation.Config(shadows = {com.amaze.filemanager.shadows.ShadowMultiDex.class}, sdk = {16, 19, 28})
@org.junit.runner.RunWith(value = androidx.test.ext.junit.runners.AndroidJUnit4.class)
public final class HybridFileTest {
    
    public HybridFileTest() {
        super();
    }
    
    /**
     * Test []
     */
    @org.junit.Test()
    public final void testGetParentGeneric() {
    }
    
    /**
     * Test [HybridFile.getParent] for SSH paths with trailing slash.
     */
    @org.junit.Test()
    public final void testSshGetParentWithTrailingSlash() {
    }
    
    /**
     * Test [HybridFile.getParent] for SSH paths without trailing slash.
     */
    @org.junit.Test()
    public final void testSshGetParentWithoutTrailingSlash() {
    }
}