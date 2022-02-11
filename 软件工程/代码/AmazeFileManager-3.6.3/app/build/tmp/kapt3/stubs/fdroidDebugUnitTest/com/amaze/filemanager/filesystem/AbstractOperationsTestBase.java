package com.amaze.filemanager.filesystem;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\b\'\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\r\u001a\u00020\u000eH\u0007J\b\u0010\u000f\u001a\u00020\u000eH\u0007J \u0010\u0010\u001a\u00020\u000e2\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0014H\u0004R\u0014\u0010\u0003\u001a\u00020\u0004X\u0084\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006R\u001c\u0010\u0007\u001a\u0004\u0018\u00010\bX\u0084\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\t\u0010\n\"\u0004\b\u000b\u0010\f\u00a8\u0006\u0016"}, d2 = {"Lcom/amaze/filemanager/filesystem/AbstractOperationsTestBase;", "", "()V", "blankCallback", "Lcom/amaze/filemanager/filesystem/Operations$ErrorCallBack;", "getBlankCallback", "()Lcom/amaze/filemanager/filesystem/Operations$ErrorCallBack;", "ctx", "Landroid/content/Context;", "getCtx", "()Landroid/content/Context;", "setCtx", "(Landroid/content/Context;)V", "setUp", "", "tearDown", "testRenameFileAccessDenied", "fileMode", "Lcom/amaze/filemanager/file_operations/filesystem/OpenMode;", "oldFilePath", "", "newFilePath", "app_fdroidDebug"})
@org.robolectric.annotation.Config(shadows = {com.amaze.filemanager.shadows.ShadowSmbUtil.class, com.amaze.filemanager.shadows.ShadowMultiDex.class, com.amaze.filemanager.test.ShadowTabHandler.class, com.amaze.filemanager.test.ShadowCryptUtil.class}, sdk = {16, 19, 28})
@org.robolectric.annotation.LooperMode(value = org.robolectric.annotation.LooperMode.Mode.PAUSED)
@org.junit.runner.RunWith(value = androidx.test.ext.junit.runners.AndroidJUnit4.class)
public abstract class AbstractOperationsTestBase {
    @org.jetbrains.annotations.Nullable()
    private android.content.Context ctx;
    @org.jetbrains.annotations.NotNull()
    private final com.amaze.filemanager.filesystem.Operations.ErrorCallBack blankCallback = null;
    
    public AbstractOperationsTestBase() {
        super();
    }
    
    @org.jetbrains.annotations.Nullable()
    protected final android.content.Context getCtx() {
        return null;
    }
    
    protected final void setCtx(@org.jetbrains.annotations.Nullable()
    android.content.Context p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    protected final com.amaze.filemanager.filesystem.Operations.ErrorCallBack getBlankCallback() {
        return null;
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
    
    protected final void testRenameFileAccessDenied(@org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.file_operations.filesystem.OpenMode fileMode, @org.jetbrains.annotations.NotNull()
    java.lang.String oldFilePath, @org.jetbrains.annotations.NotNull()
    java.lang.String newFilePath) {
    }
}