package com.amaze.filemanager.filesystem.smb;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0000\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u000b\u001a\u00020\fH\u0007J\u001a\u0010\r\u001a\u00020\b2\u0006\u0010\u000e\u001a\u00020\u00042\b\u0010\u000f\u001a\u0004\u0018\u00010\nH\u0007J\u0018\u0010\u0010\u001a\u00020\b2\u0006\u0010\u000e\u001a\u00020\u00042\u0006\u0010\u0011\u001a\u00020\u0012H\u0007R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0006\u001a\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\b0\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0013"}, d2 = {"Lcom/amaze/filemanager/filesystem/smb/CifsContexts;", "", "()V", "SMB_URI_PREFIX", "", "TAG", "contexts", "", "Ljcifs/context/BaseContext;", "defaultProperties", "Ljava/util/Properties;", "clearBaseContexts", "", "create", "basePath", "extraProperties", "createWithDisableIpcSigningCheck", "disableIpcSigningCheck", "", "app_fdroidDebug"})
public final class CifsContexts {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.smb.CifsContexts INSTANCE = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String SMB_URI_PREFIX = "smb://";
    private static final java.lang.String TAG = null;
    private static final java.util.Properties defaultProperties = null;
    private static final java.util.Map<java.lang.String, jcifs.context.BaseContext> contexts = null;
    
    private CifsContexts() {
        super();
    }
    
    public static final void clearBaseContexts() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final jcifs.context.BaseContext createWithDisableIpcSigningCheck(@org.jetbrains.annotations.NotNull()
    java.lang.String basePath, boolean disableIpcSigningCheck) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final jcifs.context.BaseContext create(@org.jetbrains.annotations.NotNull()
    java.lang.String basePath, @org.jetbrains.annotations.Nullable()
    java.util.Properties extraProperties) {
        return null;
    }
}