package com.amaze.filemanager.filesystem.ftpserver;

import java.lang.System;

@androidx.annotation.RequiresApi(value = android.os.Build.VERSION_CODES.KITKAT)
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\b\u0007\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0012\u0010\u0005\u001a\u00020\u00062\b\u0010\u0007\u001a\u0004\u0018\u00010\bH\u0016R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\t"}, d2 = {"Lcom/amaze/filemanager/filesystem/ftpserver/AndroidFileSystemFactory;", "Lorg/apache/ftpserver/ftplet/FileSystemFactory;", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "createFileSystemView", "Lorg/apache/ftpserver/ftplet/FileSystemView;", "user", "Lorg/apache/ftpserver/ftplet/User;", "app_fdroidDebug"})
public final class AndroidFileSystemFactory implements org.apache.ftpserver.ftplet.FileSystemFactory {
    private final android.content.Context context = null;
    
    public AndroidFileSystemFactory(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public org.apache.ftpserver.ftplet.FileSystemView createFileSystemView(@org.jetbrains.annotations.Nullable()
    org.apache.ftpserver.ftplet.User user) {
        return null;
    }
}