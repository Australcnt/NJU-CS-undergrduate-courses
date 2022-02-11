package com.amaze.filemanager.filesystem.compressed.extractcontents.helpers;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\b&\u0018\u00002\u00020\u0001B-\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\u0010\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000fH&J(\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u000e\u001a\u00020\r2\u0006\u0010\u0012\u001a\u00020\u00132\u0006\u0010\u0014\u001a\u00020\u0005H\u0004J\u0010\u0010\u0015\u001a\u00020\u00112\u0006\u0010\u0016\u001a\u00020\u0017H\u0014\u00a8\u0006\u0018"}, d2 = {"Lcom/amaze/filemanager/filesystem/compressed/extractcontents/helpers/AbstractCommonsArchiveExtractor;", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor;", "context", "Landroid/content/Context;", "filePath", "", "outputPath", "listener", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor$OnUpdate;", "updatePosition", "Lcom/amaze/filemanager/file_operations/utils/UpdatePosition;", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor$OnUpdate;Lcom/amaze/filemanager/file_operations/utils/UpdatePosition;)V", "createFrom", "Lorg/apache/commons/compress/archivers/ArchiveInputStream;", "inputStream", "Ljava/io/InputStream;", "extractEntry", "", "entry", "Lorg/apache/commons/compress/archivers/ArchiveEntry;", "outputDir", "extractWithFilter", "filter", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor$Filter;", "app_fdroidDebug"})
public abstract class AbstractCommonsArchiveExtractor extends com.amaze.filemanager.filesystem.compressed.extractcontents.Extractor {
    
    public AbstractCommonsArchiveExtractor(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String filePath, @org.jetbrains.annotations.NotNull()
    java.lang.String outputPath, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.filesystem.compressed.extractcontents.Extractor.OnUpdate listener, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.file_operations.utils.UpdatePosition updatePosition) {
        super(null, null, null, null, null);
    }
    
    /**
     * Subclasses implement this method to create [ArchiveInputStream] instances with given archive
     * as [InputStream].
     *
     * @param inputStream archive as [InputStream]
     */
    @org.jetbrains.annotations.NotNull()
    public abstract org.apache.commons.compress.archivers.ArchiveInputStream createFrom(@org.jetbrains.annotations.NotNull()
    java.io.InputStream inputStream);
    
    @kotlin.Suppress(names = {"EmptyWhileBlock"})
    @java.lang.Override()
    protected void extractWithFilter(@org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.filesystem.compressed.extractcontents.Extractor.Filter filter) throws java.io.IOException {
    }
    
    protected final void extractEntry(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    org.apache.commons.compress.archivers.ArchiveInputStream inputStream, @org.jetbrains.annotations.NotNull()
    org.apache.commons.compress.archivers.ArchiveEntry entry, @org.jetbrains.annotations.NotNull()
    java.lang.String outputDir) throws java.io.IOException {
    }
}