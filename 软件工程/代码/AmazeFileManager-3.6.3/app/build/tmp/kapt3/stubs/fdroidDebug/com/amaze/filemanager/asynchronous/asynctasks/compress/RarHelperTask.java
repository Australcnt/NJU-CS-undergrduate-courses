package com.amaze.filemanager.asynchronous.asynctasks.compress;

import java.lang.System;

/**
 * AsyncTask to load RAR file items.
 *
 * @param realFileDirectory the location of the zip file
 * @param dir relativeDirectory to access inside the zip file
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0002\u0018\u00002\u00020\u0001B7\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0018\u0010\u0007\u001a\u0014\u0012\u0010\u0012\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000b0\n0\t0\b\u00a2\u0006\u0002\u0010\fJ\u0016\u0010\r\u001a\u00020\u000e2\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u000b0\nH\u0014R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0010"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/compress/RarHelperTask;", "Lcom/amaze/filemanager/asynchronous/asynctasks/compress/CompressedHelperTask;", "fileLocation", "", "relativeDirectory", "goBack", "", "l", "Lcom/amaze/filemanager/utils/OnAsyncTaskFinished;", "Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult;", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/adapters/data/CompressedObjectParcelable;", "(Ljava/lang/String;Ljava/lang/String;ZLcom/amaze/filemanager/utils/OnAsyncTaskFinished;)V", "addElements", "", "elements", "app_fdroidDebug"})
public final class RarHelperTask extends com.amaze.filemanager.asynchronous.asynctasks.compress.CompressedHelperTask {
    private final java.lang.String fileLocation = null;
    private final java.lang.String relativeDirectory = null;
    
    public RarHelperTask(@org.jetbrains.annotations.NotNull()
    java.lang.String fileLocation, @org.jetbrains.annotations.NotNull()
    java.lang.String relativeDirectory, boolean goBack, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.utils.OnAsyncTaskFinished<com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable>>> l) {
        super(false, null);
    }
    
    @java.lang.Override()
    protected void addElements(@org.jetbrains.annotations.NotNull()
    java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable> elements) {
    }
}