package com.amaze.filemanager.filesystem.compressed.extractcontents.helpers;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000B\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\b&\u0018\u00002\u00020\u0001B-\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\u0010\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u0012H\u0016J\u0010\u0010\u0013\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u000e0\u0014H&R\u0016\u0010\f\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u000e0\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0015"}, d2 = {"Lcom/amaze/filemanager/filesystem/compressed/extractcontents/helpers/AbstractCompressedTarArchiveExtractor;", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/helpers/AbstractCommonsArchiveExtractor;", "context", "Landroid/content/Context;", "filePath", "", "outputPath", "listener", "Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor$OnUpdate;", "updatePosition", "Lcom/amaze/filemanager/file_operations/utils/UpdatePosition;", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;Lcom/amaze/filemanager/filesystem/compressed/extractcontents/Extractor$OnUpdate;Lcom/amaze/filemanager/file_operations/utils/UpdatePosition;)V", "compressorInputStreamConstructor", "Ljava/lang/reflect/Constructor;", "Lorg/apache/commons/compress/compressors/CompressorInputStream;", "createFrom", "Lorg/apache/commons/compress/archivers/tar/TarArchiveInputStream;", "inputStream", "Ljava/io/InputStream;", "getCompressorInputStreamClass", "Ljava/lang/Class;", "app_fdroidDebug"})
public abstract class AbstractCompressedTarArchiveExtractor extends com.amaze.filemanager.filesystem.compressed.extractcontents.helpers.AbstractCommonsArchiveExtractor {
    private final java.lang.reflect.Constructor<? extends org.apache.commons.compress.compressors.CompressorInputStream> compressorInputStreamConstructor = null;
    
    public AbstractCompressedTarArchiveExtractor(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String filePath, @org.jetbrains.annotations.NotNull()
    java.lang.String outputPath, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.filesystem.compressed.extractcontents.Extractor.OnUpdate listener, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.file_operations.utils.UpdatePosition updatePosition) {
        super(null, null, null, null, null);
    }
    
    /**
     * Subclasses implement this method to specify the [CompressorInputStream] class to be used. It
     * will be used to create the backing inputstream beneath [TarArchiveInputStream] in
     * [createFrom].
     *
     * @return Class representing the implementation will be handling
     */
    @org.jetbrains.annotations.NotNull()
    public abstract java.lang.Class<? extends org.apache.commons.compress.compressors.CompressorInputStream> getCompressorInputStreamClass();
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public org.apache.commons.compress.archivers.tar.TarArchiveInputStream createFrom(@org.jetbrains.annotations.NotNull()
    java.io.InputStream inputStream) {
        return null;
    }
}