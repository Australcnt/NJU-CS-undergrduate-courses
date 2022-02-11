package com.amaze.filemanager.asynchronous.asynctasks;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0003\u001a\u00020\u0004H\u0002J\b\u0010\u0005\u001a\u00020\u0006H\u0007J\b\u0010\u0007\u001a\u00020\u0006H\u0007\u00a8\u0006\b"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/SshDeleteTaskTest;", "Lcom/amaze/filemanager/asynchronous/asynctasks/AbstractDeleteTaskTestBase;", "()V", "createSshHybridFileParcelable", "Lcom/amaze/filemanager/filesystem/HybridFileParcelable;", "testDeleteSshFileAccessDenied", "", "testDeleteSshFileOk", "app_fdroidDebug"})
public final class SshDeleteTaskTest extends com.amaze.filemanager.asynchronous.asynctasks.AbstractDeleteTaskTestBase {
    
    public SshDeleteTaskTest() {
        super();
    }
    
    /**
     * Test case to verify delete SSH file success scenario.
     *
     * @see AbstractDeleteTaskTestBase.doTestDeleteFileOk
     */
    @org.junit.Test()
    public final void testDeleteSshFileOk() {
    }
    
    /**
     * Test case to verify delete SSH file failure scenario.
     *
     * @see AbstractDeleteTaskTestBase.doTestDeleteFileAccessDenied
     */
    @org.junit.Test()
    public final void testDeleteSshFileAccessDenied() {
    }
    
    private final com.amaze.filemanager.filesystem.HybridFileParcelable createSshHybridFileParcelable() {
        return null;
    }
}