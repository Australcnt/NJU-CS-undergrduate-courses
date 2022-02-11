package com.amaze.filemanager.filesystem.compressed.showcontents.helpers;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u00008\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\u0018\u0000 \u00122\u00020\u0001:\u0001\u0012B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J2\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\u0018\u0010\u000b\u001a\u0014\u0012\u0010\u0012\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000f0\u000e0\r0\fH\u0016J\u0010\u0010\u0010\u001a\u00020\b2\u0006\u0010\u0011\u001a\u00020\bH\u0014\u00a8\u0006\u0013"}, d2 = {"Lcom/amaze/filemanager/filesystem/compressed/showcontents/helpers/RarDecompressor;", "Lcom/amaze/filemanager/filesystem/compressed/showcontents/Decompressor;", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "changePath", "Lcom/amaze/filemanager/asynchronous/asynctasks/compress/RarHelperTask;", "path", "", "addGoBackItem", "", "onFinish", "Lcom/amaze/filemanager/utils/OnAsyncTaskFinished;", "Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult;", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/adapters/data/CompressedObjectParcelable;", "realRelativeDirectory", "dir", "Companion", "app_fdroidDebug"})
public final class RarDecompressor extends com.amaze.filemanager.filesystem.compressed.showcontents.Decompressor {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.compressed.showcontents.helpers.RarDecompressor.Companion Companion = null;
    
    public RarDecompressor(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super(null);
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.amaze.filemanager.asynchronous.asynctasks.compress.RarHelperTask changePath(@org.jetbrains.annotations.NotNull()
    java.lang.String path, boolean addGoBackItem, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.utils.OnAsyncTaskFinished<com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable>>> onFinish) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected java.lang.String realRelativeDirectory(@org.jetbrains.annotations.NotNull()
    java.lang.String dir) {
        return null;
    }
    
    /**
     * Helper method to convert RAR [FileHeader] entries containing backslashes back to slashes.
     *
     * @param file RAR entry as [FileHeader] object
     */
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String convertName(@org.jetbrains.annotations.NotNull()
    com.github.junrar.rarfile.FileHeader file) {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0007\u00a8\u0006\u0007"}, d2 = {"Lcom/amaze/filemanager/filesystem/compressed/showcontents/helpers/RarDecompressor$Companion;", "", "()V", "convertName", "", "file", "Lcom/github/junrar/rarfile/FileHeader;", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
        
        /**
         * Helper method to convert RAR [FileHeader] entries containing backslashes back to slashes.
         *
         * @param file RAR entry as [FileHeader] object
         */
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String convertName(@org.jetbrains.annotations.NotNull()
        com.github.junrar.rarfile.FileHeader file) {
            return null;
        }
    }
}