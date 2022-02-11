package com.amaze.filemanager.asynchronous.asynctasks.compress;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000J\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\b&\u0018\u00002\u00020\u0001B?\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0018\u0010\t\u001a\u0014\u0012\u0010\u0012\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\r0\f0\u000b0\n\u00a2\u0006\u0002\u0010\u000eJ\u0016\u0010\u0010\u001a\u00020\u00112\f\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\r0\fH\u0016J\u0010\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0016H&R\u0014\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00030\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0017"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/compress/AbstractCommonsArchiveHelperTask;", "Lcom/amaze/filemanager/asynchronous/asynctasks/compress/CompressedHelperTask;", "context", "Landroid/content/Context;", "filePath", "", "relativePath", "goBack", "", "l", "Lcom/amaze/filemanager/utils/OnAsyncTaskFinished;", "Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult;", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/adapters/data/CompressedObjectParcelable;", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;ZLcom/amaze/filemanager/utils/OnAsyncTaskFinished;)V", "Ljava/lang/ref/WeakReference;", "addElements", "", "elements", "createFrom", "Lorg/apache/commons/compress/archivers/ArchiveInputStream;", "inputStream", "Ljava/io/InputStream;", "app_fdroidDebug"})
public abstract class AbstractCommonsArchiveHelperTask extends com.amaze.filemanager.asynchronous.asynctasks.compress.CompressedHelperTask {
    private final java.lang.String filePath = null;
    private final java.lang.String relativePath = null;
    private final java.lang.ref.WeakReference<android.content.Context> context = null;
    
    public AbstractCommonsArchiveHelperTask(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String filePath, @org.jetbrains.annotations.NotNull()
    java.lang.String relativePath, boolean goBack, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.utils.OnAsyncTaskFinished<com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable>>> l) {
        super(false, null);
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
    
    @kotlin.Suppress(names = {"LabeledExpression"})
    @java.lang.Override()
    public void addElements(@org.jetbrains.annotations.NotNull()
    java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable> elements) {
    }
}