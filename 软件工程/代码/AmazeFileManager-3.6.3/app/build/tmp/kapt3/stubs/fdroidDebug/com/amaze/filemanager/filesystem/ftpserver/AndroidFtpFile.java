package com.amaze.filemanager.filesystem.ftpserver;

import java.lang.System;

@kotlin.Suppress(names = {"TooManyFunctions"})
@androidx.annotation.RequiresApi(value = android.os.Build.VERSION_CODES.KITKAT)
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000Z\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u0000\n\u0002\b\b\n\u0002\u0010!\n\u0002\b\u0006\b\u0007\u0018\u00002\u00020\u0001B\'\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\u0010\u0006\u001a\u0004\u0018\u00010\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\tJ\u0012\u0010\u000e\u001a\u0004\u0018\u00010\u000f2\u0006\u0010\u0010\u001a\u00020\u0011H\u0016J\u0012\u0010\u0012\u001a\u0004\u0018\u00010\u00132\u0006\u0010\u0010\u001a\u00020\u0011H\u0016J\b\u0010\u0014\u001a\u00020\u0015H\u0016J\b\u0010\u0016\u001a\u00020\u0015H\u0016J\b\u0010\u0017\u001a\u00020\bH\u0016J\b\u0010\u0018\u001a\u00020\bH\u0016J\b\u0010\u0019\u001a\u00020\u0011H\u0016J\b\u0010\u001a\u001a\u00020\u001bH\u0016J\b\u0010\u001c\u001a\u00020\bH\u0016J\b\u0010\u001d\u001a\u00020\bH\u0016J\b\u0010\u001e\u001a\u00020\u001fH\u0016J\b\u0010 \u001a\u00020\u0011H\u0016J\b\u0010!\u001a\u00020\u0015H\u0016J\b\u0010\"\u001a\u00020\u0015H\u0016J\b\u0010#\u001a\u00020\u0015H\u0016J\b\u0010$\u001a\u00020\u0015H\u0016J\b\u0010%\u001a\u00020\u0015H\u0016J\b\u0010&\u001a\u00020\u0015H\u0016J\u0010\u0010\'\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00010(H\u0016J\b\u0010)\u001a\u00020\u0015H\u0016J\u0010\u0010*\u001a\u00020\u00152\u0006\u0010+\u001a\u00020\u0001H\u0016J\u0010\u0010,\u001a\u00020\u00152\u0006\u0010-\u001a\u00020\u0011H\u0016R\u0014\u0010\n\u001a\b\u0012\u0004\u0012\u00020\u00030\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0006\u001a\u0004\u0018\u00010\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0002\u001a\u00020\u00038BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\f\u0010\rR\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006."}, d2 = {"Lcom/amaze/filemanager/filesystem/ftpserver/AndroidFtpFile;", "Lorg/apache/ftpserver/ftplet/FtpFile;", "context", "Landroid/content/Context;", "parentDocument", "Landroidx/documentfile/provider/DocumentFile;", "backingDocument", "path", "", "(Landroid/content/Context;Landroidx/documentfile/provider/DocumentFile;Landroidx/documentfile/provider/DocumentFile;Ljava/lang/String;)V", "_context", "Ljava/lang/ref/WeakReference;", "getContext", "()Landroid/content/Context;", "createInputStream", "Ljava/io/InputStream;", "offset", "", "createOutputStream", "Ljava/io/OutputStream;", "delete", "", "doesExist", "getAbsolutePath", "getGroupName", "getLastModified", "getLinkCount", "", "getName", "getOwnerName", "getPhysicalFile", "", "getSize", "isDirectory", "isFile", "isHidden", "isReadable", "isRemovable", "isWritable", "listFiles", "", "mkdir", "move", "destination", "setLastModified", "time", "app_fdroidDebug"})
public final class AndroidFtpFile implements org.apache.ftpserver.ftplet.FtpFile {
    private final androidx.documentfile.provider.DocumentFile parentDocument = null;
    private final androidx.documentfile.provider.DocumentFile backingDocument = null;
    private final java.lang.String path = null;
    private final java.lang.ref.WeakReference<android.content.Context> _context = null;
    
    public AndroidFtpFile(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    androidx.documentfile.provider.DocumentFile parentDocument, @org.jetbrains.annotations.Nullable()
    androidx.documentfile.provider.DocumentFile backingDocument, @org.jetbrains.annotations.NotNull()
    java.lang.String path) {
        super();
    }
    
    private final android.content.Context getContext() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getAbsolutePath() {
        return null;
    }
    
    /**
     * @see FtpFile.getName
     * @see DocumentFile.getName
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getName() {
        return null;
    }
    
    /**
     * @see FtpFile.isHidden
     */
    @java.lang.Override()
    public boolean isHidden() {
        return false;
    }
    
    /**
     * @see FtpFile.isDirectory
     * @see DocumentFile.isDirectory
     */
    @java.lang.Override()
    public boolean isDirectory() {
        return false;
    }
    
    /**
     * @see FtpFile.isFile
     * @see DocumentFile.isFile
     */
    @java.lang.Override()
    public boolean isFile() {
        return false;
    }
    
    /**
     * @see FtpFile.doesExist
     * @see DocumentFile.exists
     */
    @java.lang.Override()
    public boolean doesExist() {
        return false;
    }
    
    /**
     * @see FtpFile.isReadable
     * @see DocumentFile.canRead
     */
    @java.lang.Override()
    public boolean isReadable() {
        return false;
    }
    
    /**
     * @see FtpFile.isWritable
     * @see DocumentFile.canWrite
     */
    @java.lang.Override()
    public boolean isWritable() {
        return false;
    }
    
    /**
     * @see FtpFile.isRemovable
     * @see DocumentFile.canWrite
     */
    @java.lang.Override()
    public boolean isRemovable() {
        return false;
    }
    
    /**
     * @see FtpFile.getOwnerName
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getOwnerName() {
        return null;
    }
    
    /**
     * @see FtpFile.getGroupName
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getGroupName() {
        return null;
    }
    
    /**
     * @see FtpFile.getLinkCount
     */
    @java.lang.Override()
    public int getLinkCount() {
        return 0;
    }
    
    /**
     * @see FtpFile.getLastModified
     * @see DocumentFile.lastModified
     */
    @java.lang.Override()
    public long getLastModified() {
        return 0L;
    }
    
    /**
     * @see FtpFile.setLastModified
     * @see DocumentsContract.Document.COLUMN_LAST_MODIFIED
     * @see ContentResolver.update
     */
    @java.lang.Override()
    public boolean setLastModified(long time) {
        return false;
    }
    
    /**
     * @see FtpFile.getSize
     * @see DocumentFile.length
     */
    @java.lang.Override()
    public long getSize() {
        return 0L;
    }
    
    /**
     * @see FtpFile.getPhysicalFile
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.Object getPhysicalFile() {
        return null;
    }
    
    /**
     * @see FtpFile.mkdir
     * @see DocumentFile.createDirectory
     */
    @java.lang.Override()
    public boolean mkdir() {
        return false;
    }
    
    /**
     * @see FtpFile.delete
     * @see DocumentFile.delete
     */
    @java.lang.Override()
    public boolean delete() {
        return false;
    }
    
    /**
     * @see FtpFile.move
     * @see DocumentFile.renameTo
     */
    @java.lang.Override()
    public boolean move(@org.jetbrains.annotations.NotNull()
    org.apache.ftpserver.ftplet.FtpFile destination) {
        return false;
    }
    
    /**
     * @see FtpFile.listFiles
     * @see DocumentFile.listFiles
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.util.List<? extends org.apache.ftpserver.ftplet.FtpFile> listFiles() {
        return null;
    }
    
    /**
     * @see FtpFile.createOutputStream
     * @see ContentResolver.openOutputStream
     */
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.io.OutputStream createOutputStream(long offset) {
        return null;
    }
    
    /**
     * @see FtpFile.createInputStream
     * @see ContentResolver.openInputStream
     */
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.io.InputStream createInputStream(long offset) {
        return null;
    }
}