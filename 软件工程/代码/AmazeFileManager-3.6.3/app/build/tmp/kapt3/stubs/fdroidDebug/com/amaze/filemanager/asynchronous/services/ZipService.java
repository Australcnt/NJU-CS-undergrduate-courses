package com.amaze.filemanager.asynchronous.services;

import java.lang.System;

@kotlin.Suppress(names = {"TooManyFunctions"})
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000~\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u000b\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\n\u0018\u0000 92\u00020\u0001:\u00029:B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u001b\u001a\u00020\u001cH\u0014J\u0018\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020 2\u0006\u0010!\u001a\u00020\"H\u0002J\u0010\u0010#\u001a\u00020\"2\u0006\u0010!\u001a\u00020\"H\u0002J\u000e\u0010$\u001a\b\u0012\u0004\u0012\u00020\f0\u000bH\u0014J\b\u0010%\u001a\u00020\u0010H\u0014J\b\u0010&\u001a\u00020\bH\u0014J\b\u0010\'\u001a\u00020\bH\u0014J\b\u0010(\u001a\u00020\u0004H\u0014J\b\u0010)\u001a\u00020\u0012H\u0014J\b\u0010*\u001a\u00020\u0014H\u0014J\b\u0010+\u001a\u00020\u0016H\u0016J\u0010\u0010,\u001a\u00020\u00042\u0006\u0010-\u001a\u00020.H\u0015J\u0010\u0010/\u001a\u00020\u000e2\u0006\u00100\u001a\u000201H\u0016J\b\u00102\u001a\u00020\u001cH\u0016J\b\u00103\u001a\u00020\u001cH\u0016J \u00104\u001a\u00020\u00042\u0006\u00105\u001a\u0002012\u0006\u00106\u001a\u00020\u00042\u0006\u00107\u001a\u00020\u0004H\u0016J\u0010\u00108\u001a\u00020\u001c2\u0006\u0010\u0015\u001a\u00020\u0016H\u0016R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0005\u001a\b\u0018\u00010\u0006R\u00020\u0000X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0007\u001a\u0004\u0018\u00010\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\t\u001a\u0004\u0018\u00010\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000f\u001a\u0004\u0018\u00010\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0011\u001a\u0004\u0018\u00010\u0012X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0015\u001a\u0004\u0018\u00010\u0016X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0017\u001a\u00020\u0018X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0019\u001a\u0004\u0018\u00010\u001aX\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u0006;"}, d2 = {"Lcom/amaze/filemanager/asynchronous/services/ZipService;", "Lcom/amaze/filemanager/asynchronous/services/AbstractProgressiveService;", "()V", "accentColor", "", "asyncTask", "Lcom/amaze/filemanager/asynchronous/services/ZipService$CompressAsyncTask;", "customBigContentViews", "Landroid/widget/RemoteViews;", "customSmallContentViews", "dataPackages", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/utils/DatapointParcelable;", "mBinder", "Landroid/os/IBinder;", "mBuilder", "Landroidx/core/app/NotificationCompat$Builder;", "mNotifyManager", "Landroid/app/NotificationManager;", "progressHandler", "Lcom/amaze/filemanager/utils/ProgressHandler;", "progressListener", "Lcom/amaze/filemanager/asynchronous/services/AbstractProgressiveService$ProgressListener;", "receiver1", "Landroid/content/BroadcastReceiver;", "sharedPreferences", "Landroid/content/SharedPreferences;", "clearDataPackages", "", "createZipEntry", "Ljava/util/zip/ZipEntry;", "file", "Ljava/io/File;", "path", "", "createZipEntryPrefixWith", "getDataPackages", "getNotificationBuilder", "getNotificationCustomViewBig", "getNotificationCustomViewSmall", "getNotificationId", "getNotificationManager", "getProgressHandler", "getProgressListener", "getTitle", "move", "", "onBind", "arg0", "Landroid/content/Intent;", "onCreate", "onDestroy", "onStartCommand", "intent", "flags", "startId", "setProgressListener", "Companion", "CompressAsyncTask", "app_fdroidDebug"})
public final class ZipService extends com.amaze.filemanager.asynchronous.services.AbstractProgressiveService {
    private final android.os.IBinder mBinder = null;
    private com.amaze.filemanager.asynchronous.services.ZipService.CompressAsyncTask asyncTask;
    private android.app.NotificationManager mNotifyManager;
    private androidx.core.app.NotificationCompat.Builder mBuilder;
    private final com.amaze.filemanager.utils.ProgressHandler progressHandler = null;
    private com.amaze.filemanager.asynchronous.services.AbstractProgressiveService.ProgressListener progressListener;
    private final java.util.ArrayList<com.amaze.filemanager.utils.DatapointParcelable> dataPackages = null;
    private int accentColor = 0;
    private android.content.SharedPreferences sharedPreferences;
    private android.widget.RemoteViews customSmallContentViews;
    private android.widget.RemoteViews customBigContentViews;
    private final android.content.BroadcastReceiver receiver1 = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.asynchronous.services.ZipService.Companion Companion = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String KEY_COMPRESS_PATH = "zip_path";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String KEY_COMPRESS_FILES = "zip_files";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String KEY_COMPRESS_BROADCAST_CANCEL = "zip_cancel";
    
    public ZipService() {
        super();
    }
    
    @java.lang.Override()
    public void onCreate() {
    }
    
    @java.lang.Override()
    public int onStartCommand(@org.jetbrains.annotations.NotNull()
    android.content.Intent intent, int flags, int startId) {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected android.app.NotificationManager getNotificationManager() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected androidx.core.app.NotificationCompat.Builder getNotificationBuilder() {
        return null;
    }
    
    @java.lang.Override()
    protected int getNotificationId() {
        return 0;
    }
    
    @androidx.annotation.StringRes()
    @java.lang.Override()
    protected int getTitle(boolean move) {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected android.widget.RemoteViews getNotificationCustomViewSmall() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected android.widget.RemoteViews getNotificationCustomViewBig() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.amaze.filemanager.asynchronous.services.AbstractProgressiveService.ProgressListener getProgressListener() {
        return null;
    }
    
    @java.lang.Override()
    public void setProgressListener(@org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.asynchronous.services.AbstractProgressiveService.ProgressListener progressListener) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected java.util.ArrayList<com.amaze.filemanager.utils.DatapointParcelable> getDataPackages() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected com.amaze.filemanager.utils.ProgressHandler getProgressHandler() {
        return null;
    }
    
    @java.lang.Override()
    protected void clearDataPackages() {
    }
    
    private final java.lang.String createZipEntryPrefixWith(java.lang.String path) {
        return null;
    }
    
    private final java.util.zip.ZipEntry createZipEntry(java.io.File file, java.lang.String path) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.os.IBinder onBind(@org.jetbrains.annotations.NotNull()
    android.content.Intent arg0) {
        return null;
    }
    
    @java.lang.Override()
    public void onDestroy() {
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000V\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0011\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0004\b\u0086\u0004\u0018\u00002\u0018\u0012\u0004\u0012\u00020\u0002\u0012\u0006\u0012\u0004\u0018\u00010\u0002\u0012\u0006\u0012\u0004\u0018\u00010\u00020\u0001B#\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u0018\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\tH\u0002J#\u0010\u0016\u001a\u0004\u0018\u00010\u00022\u0012\u0010\u0017\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00020\u0018\"\u00020\u0002H\u0014\u00a2\u0006\u0002\u0010\u0019J&\u0010\u001a\u001a\u00020\u00122\u0006\u0010\u001b\u001a\u00020\u001c2\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00140\u00062\b\u0010\b\u001a\u0004\u0018\u00010\tJ\b\u0010\u001d\u001a\u00020\u0012H\u0014J\u0012\u0010\u001e\u001a\u00020\u00122\b\u0010\u001f\u001a\u0004\u0018\u00010\u0002H\u0016R\u0014\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\r\u001a\u0004\u0018\u00010\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000f\u001a\u0004\u0018\u00010\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u0006 "}, d2 = {"Lcom/amaze/filemanager/asynchronous/services/ZipService$CompressAsyncTask;", "Landroid/os/AsyncTask;", "Ljava/lang/Void;", "zipService", "Lcom/amaze/filemanager/asynchronous/services/ZipService;", "baseFiles", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/filesystem/HybridFileParcelable;", "zipPath", "", "(Lcom/amaze/filemanager/asynchronous/services/ZipService;Lcom/amaze/filemanager/asynchronous/services/ZipService;Ljava/util/ArrayList;Ljava/lang/String;)V", "totalBytes", "", "watcherUtil", "Lcom/amaze/filemanager/asynchronous/management/ServiceWatcherUtil;", "zos", "Ljava/util/zip/ZipOutputStream;", "compressFile", "", "file", "Ljava/io/File;", "path", "doInBackground", "p1", "", "([Ljava/lang/Void;)Ljava/lang/Void;", "execute", "context", "Landroid/content/Context;", "onCancelled", "onPostExecute", "a", "app_fdroidDebug"})
    public final class CompressAsyncTask extends android.os.AsyncTask<java.lang.Void, java.lang.Void, java.lang.Void> {
        private final com.amaze.filemanager.asynchronous.services.ZipService zipService = null;
        private final java.util.ArrayList<com.amaze.filemanager.filesystem.HybridFileParcelable> baseFiles = null;
        private final java.lang.String zipPath = null;
        private java.util.zip.ZipOutputStream zos;
        private com.amaze.filemanager.asynchronous.management.ServiceWatcherUtil watcherUtil;
        private long totalBytes = 0L;
        
        public CompressAsyncTask(@org.jetbrains.annotations.NotNull()
        com.amaze.filemanager.asynchronous.services.ZipService zipService, @org.jetbrains.annotations.NotNull()
        java.util.ArrayList<com.amaze.filemanager.filesystem.HybridFileParcelable> baseFiles, @org.jetbrains.annotations.NotNull()
        java.lang.String zipPath) {
            super();
        }
        
        @org.jetbrains.annotations.Nullable()
        @java.lang.Override()
        protected java.lang.Void doInBackground(@org.jetbrains.annotations.NotNull()
        java.lang.Void... p1) {
            return null;
        }
        
        @java.lang.Override()
        protected void onCancelled() {
        }
        
        @java.lang.Override()
        public void onPostExecute(@org.jetbrains.annotations.Nullable()
        java.lang.Void a) {
        }
        
        /**
         * Main logic for zipping specified files.
         */
        public final void execute(@org.jetbrains.annotations.NotNull()
        android.content.Context context, @org.jetbrains.annotations.NotNull()
        java.util.ArrayList<java.io.File> baseFiles, @org.jetbrains.annotations.Nullable()
        java.lang.String zipPath) {
        }
        
        private final void compressFile(java.io.File file, java.lang.String path) throws java.io.IOException, java.lang.NullPointerException, java.util.zip.ZipException {
        }
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0007"}, d2 = {"Lcom/amaze/filemanager/asynchronous/services/ZipService$Companion;", "", "()V", "KEY_COMPRESS_BROADCAST_CANCEL", "", "KEY_COMPRESS_FILES", "KEY_COMPRESS_PATH", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}