package com.amaze.filemanager.filesystem.compressed.extractcontents.helpers;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B-\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\u0010\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000fH\u0016\u00a8\u0006\u0010"}, d2 = {"Lcom/amaze/filemanager/filesystem/compressed/extractcontents/helpers/TarExtractor;", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/helpers/AbstractCommonsArchiveExtractor;", "context", "Landroid/content/Context;", "filePath", "", "outputPath", "listener", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor$OnUpdate;", "updatePosition", "Lcom/amaze/filemanager/file_operations/utils/UpdatePosition;", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor$OnUpdate;Lcom/amaze/filemanager/file_operations/utils/UpdatePosition;)V", "createFrom", "Lorg/apache/commons/compress/archivers/tar/TarArchiveInputStream;", "inputStream", "Ljava/io/InputStream;", "app_fdroidDebug"})
public final class TarExtractor extends com.amaze.filemanager.filesystem.compressed.extractcontents.helpers.AbstractCommonsArchiveExtractor {
    
    public TarExtractor(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String filePath, @org.jetbrains.annotations.NotNull()
    java.lang.String outputPath, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.filesystem.compressed.extractcontents.Extractor.OnUpdate listener, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.file_operations.utils.UpdatePosition updatePosition) {
        super(null, null, null, null, null);
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public org.apache.commons.compress.archivers.tar.TarArchiveInputStream createFrom(@org.jetbrains.annotations.NotNull()
    java.io.InputStream inputStream) {
        return null;
    }
}