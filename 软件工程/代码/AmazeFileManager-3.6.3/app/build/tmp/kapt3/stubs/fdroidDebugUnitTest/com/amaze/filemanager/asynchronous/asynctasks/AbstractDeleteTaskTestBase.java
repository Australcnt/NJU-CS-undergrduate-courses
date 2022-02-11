package com.amaze.filemanager.asynchronous.asynctasks;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\b\'\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bH\u0004J\u0010\u0010\t\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bH\u0004J\b\u0010\n\u001a\u00020\u0006H\u0007J\b\u0010\u000b\u001a\u00020\u0006H\u0007R\u0010\u0010\u0003\u001a\u0004\u0018\u00010\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u0006\f"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/AbstractDeleteTaskTestBase;", "", "()V", "ctx", "Landroid/content/Context;", "doTestDeleteFileAccessDenied", "", "file", "Lcom/amaze/filemanager/filesystem/HybridFileParcelable;", "doTestDeleteFileOk", "setUp", "tearDown", "app_fdroidDebug"})
@org.robolectric.annotation.Config(shadows = {com.amaze.filemanager.shadows.ShadowMultiDex.class, com.amaze.filemanager.shadows.ShadowSmbUtil.class, com.amaze.filemanager.test.ShadowTabHandler.class, com.amaze.filemanager.test.ShadowCryptUtil.class}, sdk = {16, 19, 28})
@org.robolectric.annotation.LooperMode(value = org.robolectric.annotation.LooperMode.Mode.PAUSED)
@org.junit.runner.RunWith(value = androidx.test.ext.junit.runners.AndroidJUnit4.class)
public abstract class AbstractDeleteTaskTestBase {
    private android.content.Context ctx;
    
    public AbstractDeleteTaskTestBase() {
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
    
    protected final void doTestDeleteFileOk(@org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.filesystem.HybridFileParcelable file) {
    }
    
    protected final void doTestDeleteFileAccessDenied(@org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.filesystem.HybridFileParcelable file) {
    }
}