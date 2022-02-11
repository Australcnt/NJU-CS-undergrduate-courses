package com.amaze.filemanager.asynchronous.asynctasks.compress;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0010\u0011\n\u0002\b\u0004\b&\u0018\u00002 \u0012\u0004\u0012\u00020\u0002\u0012\u0004\u0012\u00020\u0003\u0012\u0010\u0012\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00060\u00050\u00040\u0001B)\b\u0000\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0018\u0010\t\u001a\u0014\u0012\u0010\u0012\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00060\u00050\u00040\n\u00a2\u0006\u0002\u0010\u000bJ\u0016\u0010\f\u001a\u00020\r2\f\u0010\u000e\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005H$J-\u0010\u000f\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00060\u00050\u00042\u0012\u0010\u0010\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00020\u0011\"\u00020\u0002H\u0016\u00a2\u0006\u0002\u0010\u0012J\u001c\u0010\u0013\u001a\u00020\r2\u0012\u0010\u0014\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00060\u00050\u0004H\u0014R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R \u0010\t\u001a\u0014\u0012\u0010\u0012\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00060\u00050\u00040\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0015"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/compress/CompressedHelperTask;", "Landroid/os/AsyncTask;", "Ljava/lang/Void;", "Ljava/io/IOException;", "Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult;", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/adapters/data/CompressedObjectParcelable;", "createBackItem", "", "onFinish", "Lcom/amaze/filemanager/utils/OnAsyncTaskFinished;", "(ZLcom/amaze/filemanager/utils/OnAsyncTaskFinished;)V", "addElements", "", "elements", "doInBackground", "voids", "", "([Ljava/lang/Void;)Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult;", "onPostExecute", "zipEntries", "app_fdroidDebug"})
public abstract class CompressedHelperTask extends android.os.AsyncTask<java.lang.Void, java.io.IOException, com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable>>> {
    private final boolean createBackItem = false;
    private final com.amaze.filemanager.utils.OnAsyncTaskFinished<com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable>>> onFinish = null;
    
    public CompressedHelperTask(boolean createBackItem, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.utils.OnAsyncTaskFinished<com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable>>> onFinish) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable>> doInBackground(@org.jetbrains.annotations.NotNull()
    java.lang.Void... voids) {
        return null;
    }
    
    @java.lang.Override()
    protected void onPostExecute(@org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable>> zipEntries) {
    }
    
    protected abstract void addElements(@org.jetbrains.annotations.NotNull()
    java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable> elements);
}