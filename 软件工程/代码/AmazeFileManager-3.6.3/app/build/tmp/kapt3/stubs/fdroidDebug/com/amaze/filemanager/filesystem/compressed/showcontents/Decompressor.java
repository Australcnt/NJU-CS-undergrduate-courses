package com.amaze.filemanager.filesystem.compressed.showcontents;

import java.lang.System;

/**
 * @author Emmanuel on 20/11/2017, at 17:14.
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000J\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\u0011\n\u0002\b\u0004\b&\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J2\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\t2\u0006\u0010\u0011\u001a\u00020\u00122\u0018\u0010\u0013\u001a\u0014\u0012\u0010\u0012\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00170\u00160\u00150\u0014H&J\u000e\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\tJ#\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\t2\u000e\u0010\u001b\u001a\n\u0012\u0006\u0012\u0004\u0018\u00010\t0\u001c\u00a2\u0006\u0002\u0010\u001dJ\u0010\u0010\u001e\u001a\u00020\t2\u0006\u0010\u001f\u001a\u00020\tH\u0014R\u001a\u0010\u0002\u001a\u00020\u0003X\u0084\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0005\u0010\u0006\"\u0004\b\u0007\u0010\u0004R\u001c\u0010\b\u001a\u0004\u0018\u00010\tX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\n\u0010\u000b\"\u0004\b\f\u0010\r\u00a8\u0006 "}, d2 = {"Lcom/amaze/filemanager/filesystem/compressed/showcontents/Decompressor;", "", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "getContext", "()Landroid/content/Context;", "setContext", "filePath", "", "getFilePath", "()Ljava/lang/String;", "setFilePath", "(Ljava/lang/String;)V", "changePath", "Lcom/amaze/filemanager/asynchronous/asynctasks/compress/CompressedHelperTask;", "path", "addGoBackItem", "", "onFinish", "Lcom/amaze/filemanager/utils/OnAsyncTaskFinished;", "Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult;", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/adapters/data/CompressedObjectParcelable;", "decompress", "", "whereToDecompress", "subDirectories", "", "(Ljava/lang/String;[Ljava/lang/String;)V", "realRelativeDirectory", "dir", "app_fdroidDebug"})
public abstract class Decompressor {
    @org.jetbrains.annotations.NotNull()
    private android.content.Context context;
    @org.jetbrains.annotations.Nullable()
    private java.lang.String filePath;
    
    public Decompressor(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    protected final android.content.Context getContext() {
        return null;
    }
    
    protected final void setContext(@org.jetbrains.annotations.NotNull()
    android.content.Context p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String getFilePath() {
        return null;
    }
    
    public final void setFilePath(@org.jetbrains.annotations.Nullable()
    java.lang.String p0) {
    }
    
    /**
     * Separator must be "/"
     *
     * @param path end with "/" if it is a directory, does not if it's a file
     */
    @org.jetbrains.annotations.NotNull()
    public abstract com.amaze.filemanager.asynchronous.asynctasks.compress.CompressedHelperTask changePath(@org.jetbrains.annotations.NotNull()
    java.lang.String path, boolean addGoBackItem, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.utils.OnAsyncTaskFinished<com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.util.ArrayList<com.amaze.filemanager.adapters.data.CompressedObjectParcelable>>> onFinish);
    
    /**
     * Decompress a file somewhere
     */
    public final void decompress(@org.jetbrains.annotations.NotNull()
    java.lang.String whereToDecompress) {
    }
    
    /**
     * Decompress files or dirs inside the compressed file.
     *
     * @param subDirectories separator is "/", ended with "/" if it is a directory, does not if it's a
     * file
     */
    public final void decompress(@org.jetbrains.annotations.NotNull()
    java.lang.String whereToDecompress, @org.jetbrains.annotations.NotNull()
    java.lang.String[] subDirectories) {
    }
    
    /**
     * Get the real relative directory path (useful if you converted the separator or something)
     */
    @org.jetbrains.annotations.NotNull()
    protected java.lang.String realRelativeDirectory(@org.jetbrains.annotations.NotNull()
    java.lang.String dir) {
        return null;
    }
}