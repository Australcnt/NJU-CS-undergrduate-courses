package com.amaze.filemanager.filesystem.smb;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0004\b\u0007\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0005\u001a\u00020\u0006H\u0007J\b\u0010\u0007\u001a\u00020\u0006H\u0007J\b\u0010\b\u001a\u00020\u0006H\u0007J\b\u0010\t\u001a\u00020\u0006H\u0007R\u0010\u0010\u0003\u001a\u0004\u0018\u00010\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u0006\n"}, d2 = {"Lcom/amaze/filemanager/filesystem/smb/SmbHybridFileTest;", "", "()V", "ctx", "Landroid/content/Context;", "setUp", "", "tearDown", "testDeleteAccessDenied", "testDeleteOk", "app_fdroidDebug"})
@org.robolectric.annotation.LooperMode(value = org.robolectric.annotation.LooperMode.Mode.PAUSED)
@org.robolectric.annotation.Config(shadows = {com.amaze.filemanager.shadows.ShadowSmbUtil.class, com.amaze.filemanager.shadows.ShadowMultiDex.class}, sdk = {16, 19, 28})
@org.junit.runner.RunWith(value = androidx.test.ext.junit.runners.AndroidJUnit4.class)
public final class SmbHybridFileTest {
    private android.content.Context ctx;
    
    public SmbHybridFileTest() {
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
     * Close database on test finished.
     */
    @org.junit.After()
    public final void tearDown() {
    }
    
    /**
     * Test case to verify delete SMB file success scenario.
     *
     * @see HybridFile.delete
     */
    @org.junit.Test()
    public final void testDeleteOk() {
    }
    
    /**
     * Test case to verify delete SMB file failure scenario.
     *
     * @see HybridFile.delete
     */
    @org.junit.Test(expected = jcifs.smb.SmbException.class)
    public final void testDeleteAccessDenied() {
    }
}