package com.amaze.filemanager.utils;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\b\n\u0002\b\n\n\u0002\u0010\u0007\n\u0002\b\u0004\u0018\u0000 \u00192\u00020\u0001:\u0001\u0019B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u000e\u0010\u0014\u001a\u00020\u000b2\u0006\u0010\u0015\u001a\u00020\u0016J\u000e\u0010\u0017\u001a\u00020\u000b2\u0006\u0010\u0018\u001a\u00020\u0016R\u0014\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00030\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0007\u001a\u0004\u0018\u00010\u00038BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\b\u0010\tR\u0011\u0010\n\u001a\u00020\u000b8F\u00a2\u0006\u0006\u001a\u0004\b\f\u0010\rR\u0014\u0010\u000e\u001a\u00020\u000b8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u000f\u0010\rR\u0011\u0010\u0010\u001a\u00020\u000b8F\u00a2\u0006\u0006\u001a\u0004\b\u0011\u0010\rR\u0014\u0010\u0012\u001a\u00020\u000b8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0013\u0010\r\u00a8\u0006\u001a"}, d2 = {"Lcom/amaze/filemanager/utils/ScreenUtils;", "", "act", "Landroid/app/Activity;", "(Landroid/app/Activity;)V", "_activity", "Ljava/lang/ref/WeakReference;", "activity", "getActivity", "()Landroid/app/Activity;", "screeHeightInDb", "", "getScreeHeightInDb", "()I", "screenHeightInPx", "getScreenHeightInPx", "screenWidthInDp", "getScreenWidthInDp", "screenWidthInPx", "getScreenWidthInPx", "convertDbToPx", "dp", "", "convertPxToDb", "px", "Companion", "app_fdroidDebug"})
public final class ScreenUtils {
    private final java.lang.ref.WeakReference<android.app.Activity> _activity = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.utils.ScreenUtils.Companion Companion = null;
    public static final int TOOLBAR_HEIGHT_IN_DP = 128;
    
    public ScreenUtils(@org.jetbrains.annotations.NotNull()
    android.app.Activity act) {
        super();
    }
    
    private final android.app.Activity getActivity() {
        return null;
    }
    
    /**
     * Converts Density Pixels to real Pixels in screen
     * It uses context to retrieve the density.
     */
    public final int convertDbToPx(float dp) {
        return 0;
    }
    
    /**
     * Converts real Pixels in screen to Density Pixels
     * It uses context to retrieve the density.
     */
    public final int convertPxToDb(float px) {
        return 0;
    }
    
    private final int getScreenWidthInPx() {
        return 0;
    }
    
    private final int getScreenHeightInPx() {
        return 0;
    }
    
    public final int getScreenWidthInDp() {
        return 0;
    }
    
    public final int getScreeHeightInDb() {
        return 0;
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0005"}, d2 = {"Lcom/amaze/filemanager/utils/ScreenUtils$Companion;", "", "()V", "TOOLBAR_HEIGHT_IN_DP", "", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}