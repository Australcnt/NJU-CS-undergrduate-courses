package com.amaze.filemanager.utils;

import java.lang.System;

/**
 * Created by Vishal on 27-04-2017.
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\\\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\"\u0010\u000b\u001a\u0004\u0018\u00010\f2\u0006\u0010\r\u001a\u00020\u00042\u0006\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u0011H\u0007J2\u0010\u000b\u001a\u0004\u0018\u00010\f2\u0006\u0010\r\u001a\u00020\u00042\u0006\u0010\u0012\u001a\u00020\u00132\u0006\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0014\u001a\u00020\u00152\u0006\u0010\u0010\u001a\u00020\u0011H\u0007J0\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u00132\u0006\u0010\r\u001a\u00020\u00042\u0006\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0014\u001a\u00020\u00152\u0006\u0010\u0019\u001a\u00020\u001aH\u0007J \u0010\u0016\u001a\u00020\u00172\u0006\u0010\r\u001a\u00020\u00042\u0006\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0019\u001a\u00020\u001aH\u0007J(\u0010\u001b\u001a\u0012\u0012\u0004\u0012\u00020\u001d0\u001cj\b\u0012\u0004\u0012\u00020\u001d`\u001e2\u0006\u0010\r\u001a\u00020\u00042\u0006\u0010\u000e\u001a\u00020\u000fH\u0007J\u0016\u0010\u001f\u001a\b\u0012\u0004\u0012\u00020!0 2\u0006\u0010\u000e\u001a\u00020\u000fH\u0007J\u0012\u0010\"\u001a\u00020\u00112\b\u0010\u000e\u001a\u0004\u0018\u00010\u000fH\u0007R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006#"}, d2 = {"Lcom/amaze/filemanager/utils/OTGUtil;", "", "()V", "PATH_ELEMENT_DOCUMENT", "", "PATH_SEPARATOR_ENCODED", "PREFIX_DOCUMENT_FILE", "PREFIX_MEDIA_REMOVABLE", "PREFIX_OTG", "PRIMARY_STORAGE_PREFIX", "TAG", "getDocumentFile", "Landroidx/documentfile/provider/DocumentFile;", "path", "context", "Landroid/content/Context;", "createRecursive", "", "rootUri", "Landroid/net/Uri;", "openMode", "Lcom/amaze/filemanager/file_operations/filesystem/OpenMode;", "getDocumentFiles", "", "rootUriString", "fileFound", "Lcom/amaze/filemanager/utils/OnFileFound;", "getDocumentFilesList", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/filesystem/HybridFileParcelable;", "Lkotlin/collections/ArrayList;", "getMassStorageDevicesConnected", "", "Lcom/amaze/filemanager/file_operations/filesystem/usb/UsbOtgRepresentation;", "isUsbUriAccessible", "app_fdroidDebug"})
public final class OTGUtil {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.utils.OTGUtil INSTANCE = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PREFIX_OTG = "otg:/";
    private static final java.lang.String PREFIX_DOCUMENT_FILE = "content:/";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PREFIX_MEDIA_REMOVABLE = "/mnt/media_rw";
    private static final java.lang.String TAG = null;
    private static final java.lang.String PATH_SEPARATOR_ENCODED = "%2F";
    private static final java.lang.String PRIMARY_STORAGE_PREFIX = "primary%3AA";
    private static final java.lang.String PATH_ELEMENT_DOCUMENT = "document";
    
    private OTGUtil() {
        super();
    }
    
    /**
     * Returns an array of list of files at a specific path in OTG
     *
     * @param path the path to the directory tree, starts with prefix 'otg:/' Independent of URI (or
     * mount point) for the OTG
     * @param context context for loading
     * @return an array of list of files at the path
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Deprecated()
    public static final java.util.ArrayList<com.amaze.filemanager.filesystem.HybridFileParcelable> getDocumentFilesList(@org.jetbrains.annotations.NotNull()
    java.lang.String path, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return null;
    }
    
    /**
     * Get the files at a specific path in OTG
     *
     * @param path the path to the directory tree, starts with prefix 'otg:/' Independent of URI (or
     * mount point) for the OTG
     * @param context context for loading
     */
    public static final void getDocumentFiles(@org.jetbrains.annotations.NotNull()
    java.lang.String path, @org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.utils.OnFileFound fileFound) {
    }
    
    public static final void getDocumentFiles(@org.jetbrains.annotations.NotNull()
    android.net.Uri rootUriString, @org.jetbrains.annotations.NotNull()
    java.lang.String path, @org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.file_operations.filesystem.OpenMode openMode, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.utils.OnFileFound fileFound) {
    }
    
    /**
     * Traverse to a specified path in OTG
     *
     * @param createRecursive flag used to determine whether to create new file while traversing to
     * path, in case path is not present. Notably useful in opening an output stream.
     */
    @org.jetbrains.annotations.Nullable()
    public static final androidx.documentfile.provider.DocumentFile getDocumentFile(@org.jetbrains.annotations.NotNull()
    java.lang.String path, @org.jetbrains.annotations.NotNull()
    android.content.Context context, boolean createRecursive) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public static final androidx.documentfile.provider.DocumentFile getDocumentFile(@org.jetbrains.annotations.NotNull()
    java.lang.String path, @org.jetbrains.annotations.NotNull()
    android.net.Uri rootUri, @org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.file_operations.filesystem.OpenMode openMode, boolean createRecursive) {
        return null;
    }
    
    /**
     * Check if the usb uri is still accessible
     */
    @androidx.annotation.RequiresApi(api = android.os.Build.VERSION_CODES.KITKAT)
    public static final boolean isUsbUriAccessible(@org.jetbrains.annotations.Nullable()
    android.content.Context context) {
        return false;
    }
    
    /**
     * Checks if there is at least one USB device connected with class MASS STORAGE.
     */
    @org.jetbrains.annotations.NotNull()
    public static final java.util.List<com.amaze.filemanager.file_operations.filesystem.usb.UsbOtgRepresentation> getMassStorageDevicesConnected(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return null;
    }
}