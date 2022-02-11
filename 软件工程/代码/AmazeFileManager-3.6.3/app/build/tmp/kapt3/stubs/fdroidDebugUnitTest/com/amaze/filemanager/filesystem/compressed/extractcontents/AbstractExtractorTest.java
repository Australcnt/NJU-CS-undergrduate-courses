package com.amaze.filemanager.filesystem.compressed.extractcontents;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0006\b\'\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\r\u001a\u00020\u000eH\u0002J\b\u0010\u000f\u001a\u00020\u000eH\u0004J\u0010\u0010\u0010\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00120\u0011H$J\b\u0010\u0013\u001a\u00020\u000eH\u0007J\b\u0010\u0014\u001a\u00020\u000eH\u0007J\b\u0010\u0015\u001a\u00020\u000eH\u0017J\b\u0010\u0016\u001a\u00020\u000eH\u0007J\b\u0010\u0017\u001a\u00020\u000eH\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0005\u001a\u00020\u00068TX\u0094\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0007\u0010\bR\u0012\u0010\t\u001a\u00020\nX\u00a4\u0004\u00a2\u0006\u0006\u001a\u0004\b\u000b\u0010\f\u00a8\u0006\u0018"}, d2 = {"Lcom/amaze/filemanager/filesystem/compressed/extractcontents/AbstractExtractorTest;", "", "()V", "EXPECTED_TIMESTAMP", "", "archiveFile", "Ljava/io/File;", "getArchiveFile", "()Ljava/io/File;", "archiveType", "", "getArchiveType", "()Ljava/lang/String;", "copyArchivesToStorage", "", "doTestExtractFiles", "extractorClass", "Ljava/lang/Class;", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor;", "setUp", "tearDown", "testExtractFiles", "testFixEntryName", "verifyExtractedArchiveContents", "app_fdroidDebug"})
@org.robolectric.annotation.Config(shadows = {com.amaze.filemanager.shadows.ShadowMultiDex.class}, sdk = {16, 19, 28})
@org.junit.runner.RunWith(value = androidx.test.ext.junit.runners.AndroidJUnit4.class)
public abstract class AbstractExtractorTest {
    private final long EXPECTED_TIMESTAMP = 0L;
    
    public AbstractExtractorTest() {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    protected abstract java.lang.Class<? extends com.amaze.filemanager.filesystem.compressed.extractcontents.Extractor> extractorClass();
    
    @org.jetbrains.annotations.NotNull()
    protected abstract java.lang.String getArchiveType();
    
    /**
     * Test setup, copy archives to storage space
     */
    @org.junit.Before()
    public final void setUp() throws java.lang.Exception {
    }
    
    /**
     * Post test clean up
     */
    @org.junit.After()
    public final void tearDown() throws java.lang.Exception {
    }
    
    /**
     * Test extractor ability to correct problematic archive entries for security
     */
    @kotlin.Suppress(names = {"StringLiteralDuplication"})
    @org.junit.Test()
    public final void testFixEntryName() {
    }
    
    /**
     * Test extractor ability to extract files
     */
    @org.junit.Test()
    public void testExtractFiles() throws java.lang.Exception {
    }
    
    protected final void doTestExtractFiles() throws java.lang.Exception {
    }
    
    private final void verifyExtractedArchiveContents() throws java.io.IOException {
    }
    
    private final void copyArchivesToStorage() {
    }
    
    @org.jetbrains.annotations.NotNull()
    protected java.io.File getArchiveFile() {
        return null;
    }
}