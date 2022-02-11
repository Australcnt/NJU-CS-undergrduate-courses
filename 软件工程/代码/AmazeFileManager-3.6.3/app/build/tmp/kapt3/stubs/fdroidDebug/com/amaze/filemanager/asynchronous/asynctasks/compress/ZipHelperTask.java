package com.amaze.filemanager.asynchronous.asynctasks.compress;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000X\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010 \n\u0000\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001BK\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\u0010\u0006\u001a\u0004\u0018\u00010\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\"\u0010\t\u001a\u001e\u0012\u001a\u0012\u0018\u0012\u0014\u0012\u0012\u0012\u0004\u0012\u00020\r0\fj\b\u0012\u0004\u0012\u00020\r`\u000e0\u000b0\n\u00a2\u0006\u0002\u0010\u000fJ \u0010\u0015\u001a\u00020\u00162\u0016\u0010\u0017\u001a\u0012\u0012\u0004\u0012\u00020\r0\fj\b\u0012\u0004\u0012\u00020\r`\u000eH\u0016J\u0016\u0010\u0018\u001a\b\u0012\u0004\u0012\u00020\r0\u00192\u0006\u0010\u001a\u001a\u00020\u001bH\u0002R\u0014\u0010\u0010\u001a\b\u0012\u0004\u0012\u00020\u00030\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0014\u001a\u0004\u0018\u00010\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u001c"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/compress/ZipHelperTask;", "Lcom/amaze/filemanager/asynchronous/asynctasks/compress/CompressedHelperTask;", "c", "Landroid/content/Context;", "realFileDirectory", "", "dir", "goback", "", "l", "Lcom/amaze/filemanager/utils/OnAsyncTaskFinished;", "Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult;", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/adapters/data/CompressedObjectParcelable;", "Lkotlin/collections/ArrayList;", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;ZLcom/amaze/filemanager/utils/OnAsyncTaskFinished;)V", "context", "Ljava/lang/ref/WeakReference;", "fileLocation", "Landroid/net/Uri;", "relativeDirectory", "addElements", "", "elements", "filterValidEntryList", "", "zipFile", "Lnet/lingala/zip4j/ZipFile;", "app_fdroidDebug"})
public final class ZipHelperTask extends com.amaze.filemanager.asynchronous.asynctasks.compress.CompressedHelperTask {
    private final java.lang.ref.WeakReference<android.content.Context> context = null;
    private final android.net.Uri fileLocation = null;
    private final java.lang.String relativeDirectory = null;
    
    public ZipHelperTask(@org.jetbrains.annotations.NotNull()
    android.content.Context c, @org.jetbrains.annotations.NotNull()
    java.lang.String realFileDirectory, @org.jetbrains.annotations.Nullable()
    java.lang.String dir, boolean goback, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.utils.OnAsyncTaskFinished<com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable>>> l) {
        super(false, null);
    }
    
    @kotlin.Suppress(names = {"ComplexMethod", "LongMethod"})
    @java.lang.Override()
    public void addElements(@org.jetbrains.annotations.NotNull()
    java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable> elements) {
    }
    
    private final java.util.List<com.amaze.filemanager.adapters.data.CompressedObjectParcelable> filterValidEntryList(net.lingala.zip4j.ZipFile zipFile) {
        return null;
    }
}