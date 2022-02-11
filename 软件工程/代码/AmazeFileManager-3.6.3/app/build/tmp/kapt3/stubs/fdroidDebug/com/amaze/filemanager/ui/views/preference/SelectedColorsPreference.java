package com.amaze.filemanager.ui.views.preference;

import java.lang.System;

/**
 * This is the external notification that shows some text and a CircularColorsView.
 *
 * @author Emmanuel on 6/10/2017, at 15:36.
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000P\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u0015\n\u0002\b\u0003\n\u0002\u0010\r\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\t\u0018\u00002\u00020\u0001B\u0019\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\u0002\u0010\u0006J\b\u0010\r\u001a\u00020\u000eH\u0016J\u0006\u0010\u000f\u001a\u00020\u0010J\u0012\u0010\u0011\u001a\u00020\u00102\b\u0010\u0012\u001a\u0004\u0018\u00010\u0013H\u0016J\u001a\u0010\u0014\u001a\u00020\u00152\b\u0010\u0016\u001a\u0004\u0018\u00010\u00172\u0006\u0010\u0018\u001a\u00020\bH\u0014J\u0012\u0010\u0019\u001a\u00020\u00102\b\u0010\u001a\u001a\u0004\u0018\u00010\u001bH\u0014J\b\u0010\u001c\u001a\u00020\u001bH\u0014J&\u0010\u001d\u001a\u00020\u00102\u0006\u0010\u001e\u001a\u00020\b2\u0006\u0010\u001f\u001a\u00020\b2\u0006\u0010 \u001a\u00020\b2\u0006\u0010!\u001a\u00020\bJ\u000e\u0010\"\u001a\u00020\u00102\u0006\u0010\f\u001a\u00020\bJ\u000e\u0010#\u001a\u00020\u00102\u0006\u0010\u001e\u001a\u00020\bR\u000e\u0010\u0007\u001a\u00020\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u0006$"}, d2 = {"Lcom/amaze/filemanager/ui/views/preference/SelectedColorsPreference;", "Landroidx/preference/DialogPreference;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", "backgroundColor", "", "colors", "", "selectedIndex", "visibility", "getSummary", "", "invalidateColors", "", "onBindViewHolder", "holder", "Landroidx/preference/PreferenceViewHolder;", "onGetDefaultValue", "", "a", "Landroid/content/res/TypedArray;", "index", "onRestoreInstanceState", "state", "Landroid/os/Parcelable;", "onSaveInstanceState", "setColors", "color", "color1", "color2", "color3", "setColorsVisibility", "setDividerColor", "app_fdroidDebug"})
public final class SelectedColorsPreference extends androidx.preference.DialogPreference {
    private int[] colors = {0, 0, 0, 0};
    private int backgroundColor = 0;
    private int visibility = android.view.View.VISIBLE;
    private int selectedIndex = -1;
    
    public SelectedColorsPreference(@org.jetbrains.annotations.Nullable()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs) {
        super(null, null, 0, 0);
    }
    
    @java.lang.Override()
    public void onBindViewHolder(@org.jetbrains.annotations.Nullable()
    androidx.preference.PreferenceViewHolder holder) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.CharSequence getSummary() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected java.lang.Object onGetDefaultValue(@org.jetbrains.annotations.Nullable()
    android.content.res.TypedArray a, int index) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected android.os.Parcelable onSaveInstanceState() {
        return null;
    }
    
    @java.lang.Override()
    protected void onRestoreInstanceState(@org.jetbrains.annotations.Nullable()
    android.os.Parcelable state) {
    }
    
    /**
     * Set colours' visibility.
     */
    public final void setColorsVisibility(int visibility) {
    }
    
    /**
     * Sets the divider's colour.
     */
    public final void setDividerColor(int color) {
    }
    
    /**
     * set colours to specified and notify colour changed.
     */
    public final void setColors(int color, int color1, int color2, int color3) {
    }
    
    /**
     * notify colour changed.
     */
    public final void invalidateColors() {
    }
}