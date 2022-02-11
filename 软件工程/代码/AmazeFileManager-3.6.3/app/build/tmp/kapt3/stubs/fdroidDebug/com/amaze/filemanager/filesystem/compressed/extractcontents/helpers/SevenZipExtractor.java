package com.amaze.filemanager.filesystem.compressed.extractcontents.helpers;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000@\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B-\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ(\u0010\f\u001a\u00020\r2\u0006\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0005H\u0002J\u0010\u0010\u0013\u001a\u00020\r2\u0006\u0010\u0014\u001a\u00020\u0015H\u0014\u00a8\u0006\u0016"}, d2 = {"Lcom/amaze/filemanager/filesystem/compressed/extractcontents/helpers/SevenZipExtractor;", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor;", "context", "Landroid/content/Context;", "filePath", "", "outputPath", "listener", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor$OnUpdate;", "updatePosition", "Lcom/amaze/filemanager/file_operations/utils/UpdatePosition;", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor$OnUpdate;Lcom/amaze/filemanager/file_operations/utils/UpdatePosition;)V", "extractEntry", "", "sevenzFile", "Lcom/amaze/filemanager/filesystem/compressed/sevenz/SevenZFile;", "entry", "Lcom/amaze/filemanager/filesystem/compressed/sevenz/SevenZArchiveEntry;", "outputDir", "extractWithFilter", "filter", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor$Filter;", "app_fdroidDebug"})
public final class SevenZipExtractor extends com.amaze.filemanager.filesystem.compressed.extractcontents.Extractor {
    
    public SevenZipExtractor(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String filePath, @org.jetbrains.annotations.NotNull()
    java.lang.String outputPath, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.filesystem.compressed.extractcontents.Extractor.OnUpdate listener, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.file_operations.utils.UpdatePosition updatePosition) {
        super(null, null, null, null, null);
    }
    
    @java.lang.Override()
    protected void extractWithFilter(@org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.filesystem.compressed.extractcontents.Extractor.Filter filter) throws java.io.IOException {
    }
    
    private final void extractEntry(android.content.Context context, com.amaze.filemanager.filesystem.compressed.sevenz.SevenZFile sevenzFile, com.amaze.filemanager.filesystem.compressed.sevenz.SevenZArchiveEntry entry, java.lang.String outputDir) throws java.io.IOException {
    }
}