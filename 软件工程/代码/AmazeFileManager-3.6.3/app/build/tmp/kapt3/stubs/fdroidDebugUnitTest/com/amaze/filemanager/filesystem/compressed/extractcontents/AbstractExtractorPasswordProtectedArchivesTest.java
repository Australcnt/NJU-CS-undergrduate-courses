package com.amaze.filemanager.filesystem.compressed.extractcontents;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0018\u0002\n\u0002\b\u0006\b&\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0004J\u0017\u0010\u000b\u001a\f\u0012\b\u0012\u0006\u0012\u0002\b\u00030\r0\fH$\u00a2\u0006\u0002\u0010\u000eJ\b\u0010\u000f\u001a\u00020\bH\u0017J\b\u0010\u0010\u001a\u00020\bH\u0007J\b\u0010\u0011\u001a\u00020\bH\u0007J\b\u0010\u0012\u001a\u00020\bH\u0007R\u0014\u0010\u0003\u001a\u00020\u00048TX\u0094\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0005\u0010\u0006\u00a8\u0006\u0013"}, d2 = {"Lcom/amaze/filemanager/filesystem/compressed/extractcontents/AbstractExtractorPasswordProtectedArchivesTest;", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/AbstractExtractorTest;", "()V", "archiveFile", "Ljava/io/File;", "getArchiveFile", "()Ljava/io/File;", "assertExceptionIsExpected", "", "e", "Ljava/io/IOException;", "expectedRootExceptionClass", "", "Ljava/lang/Class;", "()[Ljava/lang/Class;", "testExtractFiles", "testExtractFilesWithRepeatedWrongPassword", "testExtractFilesWithWrongPassword", "testExtractFilesWithoutPassword", "app_fdroidDebug"})
public abstract class AbstractExtractorPasswordProtectedArchivesTest extends com.amaze.filemanager.filesystem.compressed.extractcontents.AbstractExtractorTest {
    
    public AbstractExtractorPasswordProtectedArchivesTest() {
        super();
    }
    
    /**
     * Test extract files without password.
     */
    @org.junit.Test(expected = java.io.IOException.class)
    public final void testExtractFilesWithoutPassword() throws java.lang.Exception {
    }
    
    /**
     * Test extract fils with wrong password.
     */
    @org.junit.Test(expected = java.io.IOException.class)
    public final void testExtractFilesWithWrongPassword() throws java.lang.Exception {
    }
    
    /**
     * Test extract files with repeatedly wrong password.
     */
    @org.junit.Test(expected = java.io.IOException.class)
    public final void testExtractFilesWithRepeatedWrongPassword() throws java.lang.Exception {
    }
    
    @java.lang.Override()
    @org.junit.Test()
    public void testExtractFiles() throws java.lang.Exception {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected java.io.File getArchiveFile() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    protected abstract java.lang.Class<?>[] expectedRootExceptionClass();
    
    protected final void assertExceptionIsExpected(@org.jetbrains.annotations.NotNull()
    java.io.IOException e) throws java.io.IOException {
    }
}