package com.amaze.filemanager.asynchronous.asynctasks.compress;

import java.lang.System;

@kotlin.Suppress(names = {"TooManyFunctions", "StringLiteralDuplication"})
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000:\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0004\b\'\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\f\u001a\u00020\rH\u0002J\u0010\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u0011H$J\b\u0010\u0012\u001a\u00020\rH\u0007J\b\u0010\u0013\u001a\u00020\rH\u0017J\b\u0010\u0014\u001a\u00020\rH\u0017R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R&\u0010\u0005\u001a\u0014\u0012\u0010\u0012\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\t0\b0\u00070\u0006X\u0084\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000b\u00a8\u0006\u0015"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/compress/AbstractCompressedHelperTaskTest;", "", "()V", "EXPECTED_TIMESTAMP", "", "emptyCallback", "Lcom/amaze/filemanager/utils/OnAsyncTaskFinished;", "Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult;", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/adapters/data/CompressedObjectParcelable;", "getEmptyCallback", "()Lcom/amaze/filemanager/utils/OnAsyncTaskFinished;", "copyArchivesToStorage", "", "createTask", "Lcom/amaze/filemanager/asynchronous/asynctasks/compress/CompressedHelperTask;", "relativePath", "", "setUp", "testRoot", "testSublevels", "app_fdroidDebug"})
@org.robolectric.annotation.Config(shadows = {com.amaze.filemanager.shadows.ShadowMultiDex.class}, sdk = {16, 19, 28})
@org.junit.runner.RunWith(value = androidx.test.ext.junit.runners.AndroidJUnit4.class)
public abstract class AbstractCompressedHelperTaskTest {
    private final long EXPECTED_TIMESTAMP = 0L;
    @org.jetbrains.annotations.NotNull()
    private final com.amaze.filemanager.utils.OnAsyncTaskFinished<com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable>>> emptyCallback = null;
    
    public AbstractCompressedHelperTaskTest() {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    protected final com.amaze.filemanager.utils.OnAsyncTaskFinished<com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable>>> getEmptyCallback() {
        return null;
    }
    
    /**
     * Test setup.
     */
    @org.junit.Before()
    public final void setUp() {
    }
    
    /**
     * Test browse archive top level.
     */
    @org.junit.Test()
    public void testRoot() {
    }
    
    /**
     * Test browse archive sub levels.
     */
    @org.junit.Test()
    public void testSublevels() {
    }
    
    @org.jetbrains.annotations.NotNull()
    protected abstract com.amaze.filemanager.asynchronous.asynctasks.compress.CompressedHelperTask createTask(@org.jetbrains.annotations.NotNull()
    java.lang.String relativePath);
    
    private final void copyArchivesToStorage() {
    }
}