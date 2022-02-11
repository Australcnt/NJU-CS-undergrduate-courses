package com.amaze.filemanager.utils;

import java.lang.System;

/**
 * This lets BottomBar be independent of the Fragment MainActivity is housing
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\bf\u0018\u00002\u00020\u0001J\u0010\u0010\n\u001a\u00020\u000b2\u0006\u0010\u0002\u001a\u00020\u0003H&R\u0014\u0010\u0002\u001a\u0004\u0018\u00010\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0004\u0010\u0005R\u0014\u0010\u0006\u001a\u00020\u00078gX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\b\u0010\t\u00a8\u0006\f"}, d2 = {"Lcom/amaze/filemanager/utils/BottomBarButtonPath;", "", "path", "", "getPath", "()Ljava/lang/String;", "rootDrawable", "", "getRootDrawable", "()I", "changePath", "", "app_fdroidDebug"})
public abstract interface BottomBarButtonPath {
    
    /**
     * This allows the fragment to change the path represented in the BottomBar directly
     */
    public abstract void changePath(@org.jetbrains.annotations.NotNull()
    java.lang.String path);
    
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.String getPath();
    
    @androidx.annotation.DrawableRes()
    public abstract int getRootDrawable();
}