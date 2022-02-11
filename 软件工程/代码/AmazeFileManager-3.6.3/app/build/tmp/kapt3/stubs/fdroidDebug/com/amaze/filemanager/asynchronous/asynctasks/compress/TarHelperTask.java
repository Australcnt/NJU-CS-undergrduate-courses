package com.amaze.filemanager.asynchronous.asynctasks.compress;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B?\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0018\u0010\t\u001a\u0014\u0012\u0010\u0012\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\r0\f0\u000b0\n\u00a2\u0006\u0002\u0010\u000eJ\u0010\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u0012H\u0016\u00a8\u0006\u0013"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/compress/TarHelperTask;", "Lcom/amaze/filemanager/asynchronous/asynctasks/compress/AbstractCommonsArchiveHelperTask;", "context", "Landroid/content/Context;", "filePath", "", "relativePath", "goBack", "", "l", "Lcom/amaze/filemanager/utils/OnAsyncTaskFinished;", "Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult;", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/adapters/data/CompressedObjectParcelable;", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;ZLcom/amaze/filemanager/utils/OnAsyncTaskFinished;)V", "createFrom", "Lorg/apache/commons/compress/archivers/ArchiveInputStream;", "inputStream", "Ljava/io/InputStream;", "app_fdroidDebug"})
public final class TarHelperTask extends com.amaze.filemanager.asynchronous.asynctasks.compress.AbstractCommonsArchiveHelperTask {
    
    public TarHelperTask(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String filePath, @org.jetbrains.annotations.NotNull()
    java.lang.String relativePath, boolean goBack, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.utils.OnAsyncTaskFinished<com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable>>> l) {
        super(null, null, null, false, null);
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public org.apache.commons.compress.archivers.ArchiveInputStream createFrom(@org.jetbrains.annotations.NotNull()
    java.io.InputStream inputStream) {
        return null;
    }
}