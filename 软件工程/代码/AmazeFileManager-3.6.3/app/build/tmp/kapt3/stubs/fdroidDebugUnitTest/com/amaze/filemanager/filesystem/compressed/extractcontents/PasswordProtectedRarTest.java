package com.amaze.filemanager.filesystem.compressed.extractcontents;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0010\u0011\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\b\u0016\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0017\u0010\u0007\u001a\f\u0012\b\u0012\u0006\u0012\u0002\b\u00030\t0\bH\u0014\u00a2\u0006\u0002\u0010\nJ\u0010\u0010\u000b\u001a\n\u0012\u0006\b\u0001\u0012\u00020\f0\tH\u0014R\u0014\u0010\u0003\u001a\u00020\u0004X\u0094D\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006\u00a8\u0006\r"}, d2 = {"Lcom/amaze/filemanager/filesystem/compressed/extractcontents/PasswordProtectedRarTest;", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/AbstractExtractorPasswordProtectedArchivesTest;", "()V", "archiveType", "", "getArchiveType", "()Ljava/lang/String;", "expectedRootExceptionClass", "", "Ljava/lang/Class;", "()[Ljava/lang/Class;", "extractorClass", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor;", "app_fdroidDebug"})
public class PasswordProtectedRarTest extends com.amaze.filemanager.filesystem.compressed.extractcontents.AbstractExtractorPasswordProtectedArchivesTest {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String archiveType = "rar";
    
    public PasswordProtectedRarTest() {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected java.lang.Class<? extends com.amaze.filemanager.filesystem.compressed.extractcontents.Extractor> extractorClass() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected java.lang.Class<?>[] expectedRootExceptionClass() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected java.lang.String getArchiveType() {
        return null;
    }
}