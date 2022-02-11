package com.amaze.filemanager.asynchronous.asynctasks.compress;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0014J\b\u0010\u0007\u001a\u00020\bH\u0007J\b\u0010\t\u001a\u00020\bH\u0007\u00a8\u0006\n"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/compress/ZipHelperTaskTest;", "Lcom/amaze/filemanager/asynchronous/asynctasks/compress/AbstractCompressedHelperTaskTest;", "()V", "createTask", "Lcom/amaze/filemanager/asynchronous/asynctasks/compress/CompressedHelperTask;", "relativePath", "", "testInvalidFileUriShouldThrowArchiveException", "", "testVariableYAssignment", "app_fdroidDebug"})
public final class ZipHelperTaskTest extends com.amaze.filemanager.asynchronous.asynctasks.compress.AbstractCompressedHelperTaskTest {
    
    public ZipHelperTaskTest() {
        super();
    }
    
    /**
     * Verification on logic in [ZipHelperTask] assigning zip entry path.
     *
     * @see ZipHelperTask.addElements
     */
    @org.junit.Test()
    public final void testVariableYAssignment() {
    }
    
    /**
     * Test behaviour when URI that cannot be recognized as file is passed into ZipHelperTask.
     */
    @org.junit.Test(expected = org.apache.commons.compress.archivers.ArchiveException.class)
    public final void testInvalidFileUriShouldThrowArchiveException() {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected com.amaze.filemanager.asynchronous.asynctasks.compress.CompressedHelperTask createTask(@org.jetbrains.annotations.NotNull()
    java.lang.String relativePath) {
        return null;
    }
}