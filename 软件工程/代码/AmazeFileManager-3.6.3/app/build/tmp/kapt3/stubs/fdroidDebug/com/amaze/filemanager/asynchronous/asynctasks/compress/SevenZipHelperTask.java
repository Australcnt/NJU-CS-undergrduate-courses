package com.amaze.filemanager.asynchronous.asynctasks.compress;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000@\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0010\u0011\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u00002\u00020\u0001B7\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0018\u0010\u0007\u001a\u0014\u0012\u0010\u0012\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000b0\n0\t0\b\u00a2\u0006\u0002\u0010\fJ\u0016\u0010\u000e\u001a\u00020\u000f2\f\u0010\u0010\u001a\b\u0012\u0004\u0012\u00020\u000b0\nH\u0014J!\u0010\u0011\u001a\u00020\u000f2\u0012\u0010\u0012\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00140\u0013\"\u00020\u0014H\u0014\u00a2\u0006\u0002\u0010\u0015R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0016"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/compress/SevenZipHelperTask;", "Lcom/amaze/filemanager/asynchronous/asynctasks/compress/CompressedHelperTask;", "filePath", "", "relativePath", "goBack", "", "l", "Lcom/amaze/filemanager/utils/OnAsyncTaskFinished;", "Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult;", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/adapters/data/CompressedObjectParcelable;", "(Ljava/lang/String;Ljava/lang/String;ZLcom/amaze/filemanager/utils/OnAsyncTaskFinished;)V", "paused", "addElements", "", "elements", "onProgressUpdate", "values", "", "Ljava/io/IOException;", "([Ljava/io/IOException;)V", "app_fdroidDebug"})
public final class SevenZipHelperTask extends com.amaze.filemanager.asynchronous.asynctasks.compress.CompressedHelperTask {
    private final java.lang.String filePath = null;
    private final java.lang.String relativePath = null;
    private boolean paused = false;
    
    public SevenZipHelperTask(@org.jetbrains.annotations.NotNull()
    java.lang.String filePath, @org.jetbrains.annotations.NotNull()
    java.lang.String relativePath, boolean goBack, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.utils.OnAsyncTaskFinished<com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable>>> l) {
        super(false, null);
    }
    
    @java.lang.Override()
    protected void addElements(@org.jetbrains.annotations.NotNull()
    java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable> elements) {
    }
    
    @java.lang.Override()
    protected void onProgressUpdate(@org.jetbrains.annotations.NotNull()
    java.io.IOException... values) {
    }
}