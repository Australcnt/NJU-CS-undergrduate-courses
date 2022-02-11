package com.amaze.filemanager.filesystem.compressed.extractcontents.helpers;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B-\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\u0010\u0010\f\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u000e0\rH\u0016\u00a8\u0006\u000f"}, d2 = {"Lcom/amaze/filemanager/filesystem/compressed/extractcontents/helpers/Bzip2Extractor;", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/helpers/AbstractCompressedTarArchiveExtractor;", "context", "Landroid/content/Context;", "filePath", "", "outputPath", "listener", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor$OnUpdate;", "updatePosition", "Lcom/amaze/filemanager/file_operations/utils/UpdatePosition;", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor$OnUpdate;Lcom/amaze/filemanager/file_operations/utils/UpdatePosition;)V", "getCompressorInputStreamClass", "Ljava/lang/Class;", "Lorg/apache/commons/compress/compressors/CompressorInputStream;", "app_fdroidDebug"})
public final class Bzip2Extractor extends com.amaze.filemanager.filesystem.compressed.extractcontents.helpers.AbstractCompressedTarArchiveExtractor {
    
    public Bzip2Extractor(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String filePath, @org.jetbrains.annotations.NotNull()
    java.lang.String outputPath, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.filesystem.compressed.extractcontents.Extractor.OnUpdate listener, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.file_operations.utils.UpdatePosition updatePosition) {
        super(null, null, null, null, null);
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.Class<? extends org.apache.commons.compress.compressors.CompressorInputStream> getCompressorInputStreamClass() {
        return null;
    }
}