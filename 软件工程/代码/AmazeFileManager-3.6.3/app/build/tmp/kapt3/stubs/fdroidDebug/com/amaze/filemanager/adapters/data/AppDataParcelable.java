package com.amaze.filemanager.adapters.data;

import java.lang.System;

@kotlin.Suppress(names = {"LongParameterList"})
@kotlinx.parcelize.Parcelize()
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u001b\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0007\u0018\u00002\u00020\u0001BO\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0003\u0012\u0006\u0010\u0006\u001a\u00020\u0003\u0012\u0006\u0010\u0007\u001a\u00020\u0003\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\t\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\b\u0010\r\u001a\u0004\u0018\u00010\u000e\u00a2\u0006\u0002\u0010\u000fJ\t\u0010)\u001a\u00020*H\u00d6\u0001J\u0019\u0010+\u001a\u00020,2\u0006\u0010-\u001a\u00020.2\u0006\u0010/\u001a\u00020*H\u00d6\u0001R\u001a\u0010\u0006\u001a\u00020\u0003X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0010\u0010\u0011\"\u0004\b\u0012\u0010\u0013R\u001a\u0010\u0007\u001a\u00020\u0003X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0014\u0010\u0011\"\u0004\b\u0015\u0010\u0013R\u001a\u0010\u000b\u001a\u00020\fX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\u0016\"\u0004\b\u0017\u0010\u0018R\u001a\u0010\u0002\u001a\u00020\u0003X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0019\u0010\u0011\"\u0004\b\u001a\u0010\u0013R\u001a\u0010\n\u001a\u00020\tX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001b\u0010\u001c\"\u0004\b\u001d\u0010\u001eR\u001c\u0010\r\u001a\u0004\u0018\u00010\u000eX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001f\u0010 \"\u0004\b!\u0010\"R\u001a\u0010\u0005\u001a\u00020\u0003X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b#\u0010\u0011\"\u0004\b$\u0010\u0013R\u001a\u0010\u0004\u001a\u00020\u0003X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b%\u0010\u0011\"\u0004\b&\u0010\u0013R\u001a\u0010\b\u001a\u00020\tX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\'\u0010\u001c\"\u0004\b(\u0010\u001e\u00a8\u00060"}, d2 = {"Lcom/amaze/filemanager/adapters/data/AppDataParcelable;", "Landroid/os/Parcelable;", "label", "", "path", "packageName", "data", "fileSize", "size", "", "lastModification", "isSystemApp", "", "openFileParcelable", "Lcom/amaze/filemanager/adapters/data/OpenFileParcelable;", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;JJZLcom/amaze/filemanager/adapters/data/OpenFileParcelable;)V", "getData", "()Ljava/lang/String;", "setData", "(Ljava/lang/String;)V", "getFileSize", "setFileSize", "()Z", "setSystemApp", "(Z)V", "getLabel", "setLabel", "getLastModification", "()J", "setLastModification", "(J)V", "getOpenFileParcelable", "()Lcom/amaze/filemanager/adapters/data/OpenFileParcelable;", "setOpenFileParcelable", "(Lcom/amaze/filemanager/adapters/data/OpenFileParcelable;)V", "getPackageName", "setPackageName", "getPath", "setPath", "getSize", "setSize", "describeContents", "", "writeToParcel", "", "parcel", "Landroid/os/Parcel;", "flags", "app_fdroidDebug"})
public final class AppDataParcelable implements android.os.Parcelable {
    @org.jetbrains.annotations.NotNull()
    private java.lang.String label;
    @org.jetbrains.annotations.NotNull()
    private java.lang.String path;
    @org.jetbrains.annotations.NotNull()
    private java.lang.String packageName;
    @org.jetbrains.annotations.NotNull()
    private java.lang.String data;
    @org.jetbrains.annotations.NotNull()
    private java.lang.String fileSize;
    private long size;
    private long lastModification;
    private boolean isSystemApp;
    @org.jetbrains.annotations.Nullable()
    private com.amaze.filemanager.adapters.data.OpenFileParcelable openFileParcelable;
    public static final android.os.Parcelable.Creator<com.amaze.filemanager.adapters.data.AppDataParcelable> CREATOR = null;
    
    public AppDataParcelable(@org.jetbrains.annotations.NotNull()
    java.lang.String label, @org.jetbrains.annotations.NotNull()
    java.lang.String path, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    java.lang.String data, @org.jetbrains.annotations.NotNull()
    java.lang.String fileSize, long size, long lastModification, boolean isSystemApp, @org.jetbrains.annotations.Nullable()
    com.amaze.filemanager.adapters.data.OpenFileParcelable openFileParcelable) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getLabel() {
        return null;
    }
    
    public final void setLabel(@org.jetbrains.annotations.NotNull()
    java.lang.String p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getPath() {
        return null;
    }
    
    public final void setPath(@org.jetbrains.annotations.NotNull()
    java.lang.String p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getPackageName() {
        return null;
    }
    
    public final void setPackageName(@org.jetbrains.annotations.NotNull()
    java.lang.String p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getData() {
        return null;
    }
    
    public final void setData(@org.jetbrains.annotations.NotNull()
    java.lang.String p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getFileSize() {
        return null;
    }
    
    public final void setFileSize(@org.jetbrains.annotations.NotNull()
    java.lang.String p0) {
    }
    
    public final long getSize() {
        return 0L;
    }
    
    public final void setSize(long p0) {
    }
    
    public final long getLastModification() {
        return 0L;
    }
    
    public final void setLastModification(long p0) {
    }
    
    public final boolean isSystemApp() {
        return false;
    }
    
    public final void setSystemApp(boolean p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.amaze.filemanager.adapters.data.OpenFileParcelable getOpenFileParcelable() {
        return null;
    }
    
    public final void setOpenFileParcelable(@org.jetbrains.annotations.Nullable()
    com.amaze.filemanager.adapters.data.OpenFileParcelable p0) {
    }
    
    @java.lang.Override()
    public int describeContents() {
        return 0;
    }
    
    @java.lang.Override()
    public void writeToParcel(@org.jetbrains.annotations.NotNull()
    android.os.Parcel parcel, int flags) {
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 3)
    public static final class Creator implements android.os.Parcelable.Creator<com.amaze.filemanager.adapters.data.AppDataParcelable> {
        
        public Creator() {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public final com.amaze.filemanager.adapters.data.AppDataParcelable createFromParcel(@org.jetbrains.annotations.NotNull()
        android.os.Parcel in) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public final com.amaze.filemanager.adapters.data.AppDataParcelable[] newArray(int size) {
            return null;
        }
    }
}