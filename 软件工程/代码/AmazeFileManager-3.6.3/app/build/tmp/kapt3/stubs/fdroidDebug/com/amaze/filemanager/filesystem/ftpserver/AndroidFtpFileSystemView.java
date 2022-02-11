package com.amaze.filemanager.filesystem.ftpserver;

import java.lang.System;

@androidx.annotation.RequiresApi(value = android.os.Build.VERSION_CODES.KITKAT)
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\t\b\u0007\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0012\u0010\u000b\u001a\u00020\f2\b\u0010\r\u001a\u0004\u0018\u00010\u0005H\u0016J\u0010\u0010\u000e\u001a\u00020\t2\u0006\u0010\u000f\u001a\u00020\u0005H\u0002J\b\u0010\u0010\u001a\u00020\u0011H\u0016J\u0010\u0010\u0012\u001a\u00020\u00132\u0006\u0010\u0014\u001a\u00020\u0005H\u0016J\b\u0010\u0015\u001a\u00020\u0013H\u0016J\u0010\u0010\u0016\u001a\u00020\u00052\u0006\u0010\u0017\u001a\u00020\u0005H\u0002J\b\u0010\u0018\u001a\u00020\u0013H\u0016J\b\u0010\u0019\u001a\u00020\fH\u0016J\u0010\u0010\u001a\u001a\u00020\u00052\u0006\u0010\u000f\u001a\u00020\u0005H\u0002J\u0014\u0010\u001b\u001a\u0004\u0018\u00010\t2\b\u0010\u000f\u001a\u0004\u0018\u00010\u0005H\u0002R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0007\u001a\u0004\u0018\u00010\u0005X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u001c"}, d2 = {"Lcom/amaze/filemanager/filesystem/ftpserver/AndroidFtpFileSystemView;", "Lorg/apache/ftpserver/ftplet/FileSystemView;", "context", "Landroid/content/Context;", "root", "", "(Landroid/content/Context;Ljava/lang/String;)V", "currentPath", "rootDocumentFile", "Landroidx/documentfile/provider/DocumentFile;", "rootPath", "changeWorkingDirectory", "", "dir", "createDocumentFileFrom", "path", "dispose", "", "getFile", "Lorg/apache/ftpserver/ftplet/FtpFile;", "file", "getHomeDirectory", "getParentFrom", "normalizedPath", "getWorkingDirectory", "isRandomAccessible", "normalizePath", "resolveDocumentFileFromRoot", "app_fdroidDebug"})
public final class AndroidFtpFileSystemView implements org.apache.ftpserver.ftplet.FileSystemView {
    private android.content.Context context;
    private final java.lang.String rootPath = null;
    private final androidx.documentfile.provider.DocumentFile rootDocumentFile = null;
    private java.lang.String currentPath = "/";
    
    public AndroidFtpFileSystemView(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String root) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public org.apache.ftpserver.ftplet.FtpFile getHomeDirectory() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public org.apache.ftpserver.ftplet.FtpFile getWorkingDirectory() {
        return null;
    }
    
    @java.lang.Override()
    public boolean changeWorkingDirectory(@org.jetbrains.annotations.Nullable()
    java.lang.String dir) {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public org.apache.ftpserver.ftplet.FtpFile getFile(@org.jetbrains.annotations.NotNull()
    java.lang.String file) {
        return null;
    }
    
    @java.lang.Override()
    public boolean isRandomAccessible() {
        return false;
    }
    
    @java.lang.Override()
    public void dispose() {
    }
    
    private final java.lang.String normalizePath(java.lang.String path) {
        return null;
    }
    
    private final java.lang.String getParentFrom(java.lang.String normalizedPath) {
        return null;
    }
    
    private final androidx.documentfile.provider.DocumentFile createDocumentFileFrom(java.lang.String path) {
        return null;
    }
    
    private final androidx.documentfile.provider.DocumentFile resolveDocumentFileFromRoot(java.lang.String path) {
        return null;
    }
}