package com.amaze.filemanager.filesystem.compressed.extractcontents;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0012\u0010\u0007\u001a\f\u0012\b\b\u0001\u0012\u0004\u0018\u00010\t0\bH\u0014J\b\u0010\n\u001a\u00020\u000bH\u0007R\u0014\u0010\u0003\u001a\u00020\u0004X\u0094D\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006\u00a8\u0006\f"}, d2 = {"Lcom/amaze/filemanager/filesystem/compressed/extractcontents/RarExtractorTest;", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/AbstractExtractorTest;", "()V", "archiveType", "", "getArchiveType", "()Ljava/lang/String;", "extractorClass", "Ljava/lang/Class;", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor;", "testTryExtractSmallestFileInArchive", "", "app_fdroidDebug"})
public final class RarExtractorTest extends com.amaze.filemanager.filesystem.compressed.extractcontents.AbstractExtractorTest {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String archiveType = "rar";
    
    public RarExtractorTest() {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected java.lang.String getArchiveType() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected java.lang.Class<? extends com.amaze.filemanager.filesystem.compressed.extractcontents.Extractor> extractorClass() {
        return null;
    }
    
    /**
     * Test [RarExtractor.tryExtractSmallestFileInArchive].
     *
     * test-archive-sizes.rar contains files of different sizes,
     * with 1 being the smallest = 2 bytes. tryExtractSmallestFileInArchive should extract this
     * file.
     */
    @org.junit.Test()
    public final void testTryExtractSmallestFileInArchive() {
    }
}