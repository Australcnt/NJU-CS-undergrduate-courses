package com.amaze.filemanager.ui.views.preference;

import java.lang.System;

/**
 * @author Emmanuel on 15/10/2017, at 20:46.
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B\u0019\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\u0002\u0010\u0006J\u0010\u0010\t\u001a\u00020\n2\b\b\u0001\u0010\u000b\u001a\u00020\bJ\u0012\u0010\f\u001a\u00020\n2\b\u0010\r\u001a\u0004\u0018\u00010\u000eH\u0016R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u000f"}, d2 = {"Lcom/amaze/filemanager/ui/views/preference/InvalidablePreferenceCategory;", "Landroidx/preference/PreferenceCategory;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", "titleColor", "", "invalidate", "", "accentColor", "onBindViewHolder", "holder", "Landroidx/preference/PreferenceViewHolder;", "app_fdroidDebug"})
public final class InvalidablePreferenceCategory extends androidx.preference.PreferenceCategory {
    private int titleColor = 0;
    
    public InvalidablePreferenceCategory(@org.jetbrains.annotations.Nullable()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs) {
        super(null, null, 0, 0);
    }
    
    @java.lang.Override()
    public void onBindViewHolder(@org.jetbrains.annotations.Nullable()
    androidx.preference.PreferenceViewHolder holder) {
    }
    
    /**
     * notify change of title colour as necessary
     */
    public final void invalidate(@androidx.annotation.ColorInt()
    int accentColor) {
    }
}