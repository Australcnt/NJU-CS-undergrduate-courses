package com.amaze.filemanager.utils;

import java.lang.System;

/**
 * Utility methods for working with animations.
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0014\u0010\u0005\u001a\u0004\u0018\u00010\u00042\b\u0010\u0006\u001a\u0004\u0018\u00010\u0007H\u0007J\u0018\u0010\b\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\rH\u0007R\u0010\u0010\u0003\u001a\u0004\u0018\u00010\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u000e"}, d2 = {"Lcom/amaze/filemanager/utils/AnimUtils;", "", "()V", "fastOutSlowIn", "Landroid/view/animation/Interpolator;", "getFastOutSlowInInterpolator", "context", "Landroid/content/Context;", "marqueeAfterDelay", "", "delayInMillis", "", "marqueeView", "Lcom/amaze/filemanager/ui/views/ThemedTextView;", "app_fdroidDebug"})
public final class AnimUtils {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.utils.AnimUtils INSTANCE = null;
    private static android.view.animation.Interpolator fastOutSlowIn;
    
    private AnimUtils() {
        super();
    }
    
    @org.jetbrains.annotations.Nullable()
    public static final android.view.animation.Interpolator getFastOutSlowInInterpolator(@org.jetbrains.annotations.Nullable()
    android.content.Context context) {
        return null;
    }
    
    /**
     * Animates filenames textview to marquee after a delay. Make sure to set [ ][TextView.setSelected] to false in order to stop the marquee later
     */
    public static final void marqueeAfterDelay(int delayInMillis, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.ui.views.ThemedTextView marqueeView) {
    }
}