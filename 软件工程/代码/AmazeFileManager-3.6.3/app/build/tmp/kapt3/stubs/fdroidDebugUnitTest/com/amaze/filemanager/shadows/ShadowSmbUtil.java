package com.amaze.filemanager.shadows;

import java.lang.System;

@kotlin.Suppress(names = {})
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\f\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0003\b\u0007\u0018\u0000 \u00032\u00020\u0001:\u0001\u0003B\u0005\u00a2\u0006\u0002\u0010\u0002\u00a8\u0006\u0004"}, d2 = {"Lcom/amaze/filemanager/shadows/ShadowSmbUtil;", "", "()V", "Companion", "app_fdroidDebug"})
@org.robolectric.annotation.Implements(value = com.amaze.filemanager.utils.SmbUtil.class)
public final class ShadowSmbUtil {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.shadows.ShadowSmbUtil.Companion Companion = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PATH_CANNOT_DELETE_FILE = "smb://user:password@1.2.3.4/access/denied.file";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PATH_CANNOT_MOVE_FILE = "smb://user:password@1.2.3.4/cannot/move.file";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PATH_CANNOT_RENAME_OLDFILE = "smb://user:password@1.2.3.4/cannot/rename.file.old";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PATH_CAN_RENAME_OLDFILE = "smb://user:password@1.2.3.4/rename/old.file";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PATH_CAN_RENAME_NEWFILE = "smb://user:password@1.2.3.4/rename/new.file";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PATH_DOESNT_EXIST = "smb://user:password@5.6.7.8/newfolder/DummyFolder";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PATH_NOT_A_FOLDER = "smb://user:password@5.6.7.8/newfolder/resume.doc";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PATH_EXIST = "smb://user:password@5.6.7.8/newfolder/Documents";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PATH_INVOKE_SMBEXCEPTION_ON_EXISTS = "smb://user:password@5.6.7.8/newfolder/wirebroken.log";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PATH_INVOKE_SMBEXCEPTION_ON_ISFOLDER = "smb://user:password@5.6.7.8/newfolder/failcheck";
    @org.jetbrains.annotations.Nullable()
    private static jcifs.smb.SmbFile mockDeleteAccessDenied;
    @org.jetbrains.annotations.Nullable()
    private static jcifs.smb.SmbFile mockDeleteDifferentNetwork;
    @org.jetbrains.annotations.Nullable()
    private static jcifs.smb.SmbFile mockCannotRenameOld;
    @org.jetbrains.annotations.Nullable()
    private static jcifs.smb.SmbFile mockCanRename;
    @org.jetbrains.annotations.Nullable()
    private static jcifs.smb.SmbFile mockPathDoesNotExist;
    @org.jetbrains.annotations.Nullable()
    private static jcifs.smb.SmbFile mockPathNotAFolder;
    @org.jetbrains.annotations.Nullable()
    private static jcifs.smb.SmbFile mockPathExist;
    @org.jetbrains.annotations.Nullable()
    private static jcifs.smb.SmbFile mockSmbExceptionOnExists;
    @org.jetbrains.annotations.Nullable()
    private static jcifs.smb.SmbFile mockSmbExceptionOnIsFolder;
    
    public ShadowSmbUtil() {
        super();
    }
    
    /**
     * Delegate to [SmbUtil.getSmbEncryptedPath].
     */
    @org.jetbrains.annotations.NotNull()
    @org.robolectric.annotation.Implementation()
    public static final java.lang.String getSmbEncryptedPath(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String path) {
        return null;
    }
    
    /**
     * Delegate to [SmbUtil.getSmbDecryptedPath].
     */
    @org.jetbrains.annotations.NotNull()
    @org.robolectric.annotation.Implementation()
    public static final java.lang.String getSmbDecryptedPath(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String path) {
        return null;
    }
    
    /**
     * Delegate to [SmbUtil.checkFolder].
     */
    @org.robolectric.annotation.Implementation()
    public static final int checkFolder(@org.jetbrains.annotations.NotNull()
    java.lang.String path) {
        return 0;
    }
    
    /**
     * Shadows SmbUtil.create()
     *
     * @see SmbUtil.create
     */
    @org.jetbrains.annotations.NotNull()
    @org.robolectric.annotation.Implementation()
    public static final jcifs.smb.SmbFile create(@org.jetbrains.annotations.NotNull()
    java.lang.String path) {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\n\n\u0002\u0018\u0002\n\u0002\b\u001d\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010,\u001a\u00020-2\u0006\u0010.\u001a\u00020\u0004H\u0007J\u0010\u0010/\u001a\u00020\u000f2\u0006\u0010.\u001a\u00020\u0004H\u0007J\u0010\u00100\u001a\u00020\u000f2\u0006\u0010.\u001a\u00020\u0004H\u0002J\u0018\u00101\u001a\u00020\u00042\u0006\u00102\u001a\u0002032\u0006\u0010.\u001a\u00020\u0004H\u0007J\u0018\u00104\u001a\u00020\u00042\u0006\u00102\u001a\u0002032\u0006\u0010.\u001a\u00020\u0004H\u0007R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u001c\u0010\u000e\u001a\u0004\u0018\u00010\u000fX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0010\u0010\u0011\"\u0004\b\u0012\u0010\u0013R\u001c\u0010\u0014\u001a\u0004\u0018\u00010\u000fX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0015\u0010\u0011\"\u0004\b\u0016\u0010\u0013R\u001c\u0010\u0017\u001a\u0004\u0018\u00010\u000fX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0018\u0010\u0011\"\u0004\b\u0019\u0010\u0013R\u001c\u0010\u001a\u001a\u0004\u0018\u00010\u000fX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001b\u0010\u0011\"\u0004\b\u001c\u0010\u0013R\u001c\u0010\u001d\u001a\u0004\u0018\u00010\u000fX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001e\u0010\u0011\"\u0004\b\u001f\u0010\u0013R\u001c\u0010 \u001a\u0004\u0018\u00010\u000fX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b!\u0010\u0011\"\u0004\b\"\u0010\u0013R\u001c\u0010#\u001a\u0004\u0018\u00010\u000fX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b$\u0010\u0011\"\u0004\b%\u0010\u0013R\u001c\u0010&\u001a\u0004\u0018\u00010\u000fX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\'\u0010\u0011\"\u0004\b(\u0010\u0013R\u001c\u0010)\u001a\u0004\u0018\u00010\u000fX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b*\u0010\u0011\"\u0004\b+\u0010\u0013\u00a8\u00065"}, d2 = {"Lcom/amaze/filemanager/shadows/ShadowSmbUtil$Companion;", "", "()V", "PATH_CANNOT_DELETE_FILE", "", "PATH_CANNOT_MOVE_FILE", "PATH_CANNOT_RENAME_OLDFILE", "PATH_CAN_RENAME_NEWFILE", "PATH_CAN_RENAME_OLDFILE", "PATH_DOESNT_EXIST", "PATH_EXIST", "PATH_INVOKE_SMBEXCEPTION_ON_EXISTS", "PATH_INVOKE_SMBEXCEPTION_ON_ISFOLDER", "PATH_NOT_A_FOLDER", "mockCanRename", "Ljcifs/smb/SmbFile;", "getMockCanRename", "()Ljcifs/smb/SmbFile;", "setMockCanRename", "(Ljcifs/smb/SmbFile;)V", "mockCannotRenameOld", "getMockCannotRenameOld", "setMockCannotRenameOld", "mockDeleteAccessDenied", "getMockDeleteAccessDenied", "setMockDeleteAccessDenied", "mockDeleteDifferentNetwork", "getMockDeleteDifferentNetwork", "setMockDeleteDifferentNetwork", "mockPathDoesNotExist", "getMockPathDoesNotExist", "setMockPathDoesNotExist", "mockPathExist", "getMockPathExist", "setMockPathExist", "mockPathNotAFolder", "getMockPathNotAFolder", "setMockPathNotAFolder", "mockSmbExceptionOnExists", "getMockSmbExceptionOnExists", "setMockSmbExceptionOnExists", "mockSmbExceptionOnIsFolder", "getMockSmbExceptionOnIsFolder", "setMockSmbExceptionOnIsFolder", "checkFolder", "", "path", "create", "createInternal", "getSmbDecryptedPath", "context", "Landroid/content/Context;", "getSmbEncryptedPath", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
        
        @org.jetbrains.annotations.Nullable()
        public final jcifs.smb.SmbFile getMockDeleteAccessDenied() {
            return null;
        }
        
        public final void setMockDeleteAccessDenied(@org.jetbrains.annotations.Nullable()
        jcifs.smb.SmbFile p0) {
        }
        
        @org.jetbrains.annotations.Nullable()
        public final jcifs.smb.SmbFile getMockDeleteDifferentNetwork() {
            return null;
        }
        
        public final void setMockDeleteDifferentNetwork(@org.jetbrains.annotations.Nullable()
        jcifs.smb.SmbFile p0) {
        }
        
        @org.jetbrains.annotations.Nullable()
        public final jcifs.smb.SmbFile getMockCannotRenameOld() {
            return null;
        }
        
        public final void setMockCannotRenameOld(@org.jetbrains.annotations.Nullable()
        jcifs.smb.SmbFile p0) {
        }
        
        @org.jetbrains.annotations.Nullable()
        public final jcifs.smb.SmbFile getMockCanRename() {
            return null;
        }
        
        public final void setMockCanRename(@org.jetbrains.annotations.Nullable()
        jcifs.smb.SmbFile p0) {
        }
        
        @org.jetbrains.annotations.Nullable()
        public final jcifs.smb.SmbFile getMockPathDoesNotExist() {
            return null;
        }
        
        public final void setMockPathDoesNotExist(@org.jetbrains.annotations.Nullable()
        jcifs.smb.SmbFile p0) {
        }
        
        @org.jetbrains.annotations.Nullable()
        public final jcifs.smb.SmbFile getMockPathNotAFolder() {
            return null;
        }
        
        public final void setMockPathNotAFolder(@org.jetbrains.annotations.Nullable()
        jcifs.smb.SmbFile p0) {
        }
        
        @org.jetbrains.annotations.Nullable()
        public final jcifs.smb.SmbFile getMockPathExist() {
            return null;
        }
        
        public final void setMockPathExist(@org.jetbrains.annotations.Nullable()
        jcifs.smb.SmbFile p0) {
        }
        
        @org.jetbrains.annotations.Nullable()
        public final jcifs.smb.SmbFile getMockSmbExceptionOnExists() {
            return null;
        }
        
        public final void setMockSmbExceptionOnExists(@org.jetbrains.annotations.Nullable()
        jcifs.smb.SmbFile p0) {
        }
        
        @org.jetbrains.annotations.Nullable()
        public final jcifs.smb.SmbFile getMockSmbExceptionOnIsFolder() {
            return null;
        }
        
        public final void setMockSmbExceptionOnIsFolder(@org.jetbrains.annotations.Nullable()
        jcifs.smb.SmbFile p0) {
        }
        
        /**
         * Delegate to [SmbUtil.getSmbEncryptedPath].
         */
        @org.jetbrains.annotations.NotNull()
        @org.robolectric.annotation.Implementation()
        public final java.lang.String getSmbEncryptedPath(@org.jetbrains.annotations.NotNull()
        android.content.Context context, @org.jetbrains.annotations.NotNull()
        java.lang.String path) {
            return null;
        }
        
        /**
         * Delegate to [SmbUtil.getSmbDecryptedPath].
         */
        @org.jetbrains.annotations.NotNull()
        @org.robolectric.annotation.Implementation()
        public final java.lang.String getSmbDecryptedPath(@org.jetbrains.annotations.NotNull()
        android.content.Context context, @org.jetbrains.annotations.NotNull()
        java.lang.String path) {
            return null;
        }
        
        /**
         * Delegate to [SmbUtil.checkFolder].
         */
        @org.robolectric.annotation.Implementation()
        public final int checkFolder(@org.jetbrains.annotations.NotNull()
        java.lang.String path) {
            return 0;
        }
        
        /**
         * Shadows SmbUtil.create()
         *
         * @see SmbUtil.create
         */
        @org.jetbrains.annotations.NotNull()
        @org.robolectric.annotation.Implementation()
        public final jcifs.smb.SmbFile create(@org.jetbrains.annotations.NotNull()
        java.lang.String path) {
            return null;
        }
        
        private final jcifs.smb.SmbFile createInternal(java.lang.String path) {
            return null;
        }
    }
}