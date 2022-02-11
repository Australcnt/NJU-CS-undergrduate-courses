package com.amaze.filemanager.ui.views.preference;

import java.lang.System;

/**
 * Created by Arpit on 10/18/2015 edited by Emmanuel Messulam <emmanuelbendavid></emmanuelbendavid>@gmail.com>
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B\u0019\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\u0002\u0010\u0006J\u0012\u0010\u0007\u001a\u00020\b2\b\u0010\t\u001a\u0004\u0018\u00010\nH\u0002J\u0012\u0010\u000b\u001a\u00020\b2\b\u0010\f\u001a\u0004\u0018\u00010\rH\u0016\u00a8\u0006\u000e"}, d2 = {"Lcom/amaze/filemanager/ui/views/preference/CheckBox;", "Landroidx/preference/SwitchPreference;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", "clearListenerInViewGroup", "", "viewGroup", "Landroid/view/ViewGroup;", "onBindViewHolder", "holder", "Landroidx/preference/PreferenceViewHolder;", "app_fdroidDebug"})
public final class CheckBox extends androidx.preference.SwitchPreference {
    
    public CheckBox(@org.jetbrains.annotations.Nullable()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs) {
        super(null, null, 0, 0);
    }
    
    @java.lang.Override()
    public void onBindViewHolder(@org.jetbrains.annotations.Nullable()
    androidx.preference.PreferenceViewHolder holder) {
    }
    
    /**
     * Clear listener in Switch for specify ViewGroup.
     *
     * @param viewGroup The ViewGroup that will need to clear the listener.
     */
    private final void clearListenerInViewGroup(android.view.ViewGroup viewGroup) {
    }
}