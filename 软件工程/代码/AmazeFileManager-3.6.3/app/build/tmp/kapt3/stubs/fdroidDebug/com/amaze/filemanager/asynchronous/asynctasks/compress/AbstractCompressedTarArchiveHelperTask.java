package com.amaze.filemanager.asynchronous.asynctasks.compress;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000N\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\b&\u0018\u00002\u00020\u0001B?\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0018\u0010\t\u001a\u0014\u0012\u0010\u0012\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\r0\f0\u000b0\n\u00a2\u0006\u0002\u0010\u000eJ\u0010\u0010\u0012\u001a\u00020\u00132\u0006\u0010\u0014\u001a\u00020\u0015H\u0016J\u0010\u0010\u0016\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00110\u0017H&R\u0016\u0010\u000f\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00110\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0018"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/compress/AbstractCompressedTarArchiveHelperTask;", "Lcom/amaze/filemanager/asynchronous/asynctasks/compress/AbstractCommonsArchiveHelperTask;", "context", "Landroid/content/Context;", "filePath", "", "relativePath", "goBack", "", "l", "Lcom/amaze/filemanager/utils/OnAsyncTaskFinished;", "Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult;", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/adapters/data/CompressedObjectParcelable;", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;ZLcom/amaze/filemanager/utils/OnAsyncTaskFinished;)V", "compressorInputStreamConstructor", "Ljava/lang/reflect/Constructor;", "Lorg/apache/commons/compress/compressors/CompressorInputStream;", "createFrom", "Lorg/apache/commons/compress/archivers/tar/TarArchiveInputStream;", "inputStream", "Ljava/io/InputStream;", "getCompressorInputStreamClass", "Ljava/lang/Class;", "app_fdroidDebug"})
public abstract class AbstractCompressedTarArchiveHelperTask extends com.amaze.filemanager.asynchronous.asynctasks.compress.AbstractCommonsArchiveHelperTask {
    private final java.lang.reflect.Constructor<? extends org.apache.commons.compress.compressors.CompressorInputStream> compressorInputStreamConstructor = null;
    
    public AbstractCompressedTarArchiveHelperTask(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String filePath, @org.jetbrains.annotations.NotNull()
    java.lang.String relativePath, boolean goBack, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.utils.OnAsyncTaskFinished<com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable>>> l) {
        super(null, null, null, false, null);
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