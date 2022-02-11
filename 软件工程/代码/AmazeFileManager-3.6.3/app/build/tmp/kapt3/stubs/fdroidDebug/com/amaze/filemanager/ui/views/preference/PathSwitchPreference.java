package com.amaze.filemanager.ui.views.preference;

import java.lang.System;

/**
 * @author Emmanuel on 17/4/2017, at 22:22.
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\u0018\u0000 \u00142\u00020\u0001:\u0001\u0014B\u000f\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u00a2\u0006\u0002\u0010\u0004J\u0012\u0010\n\u001a\u00020\u000b2\b\u0010\f\u001a\u0004\u0018\u00010\rH\u0016J$\u0010\u000e\u001a\u00020\u000f2\b\u0010\u0010\u001a\u0004\u0018\u00010\u00112\b\b\u0001\u0010\u0012\u001a\u00020\u00062\u0006\u0010\u0013\u001a\u00020\u0006H\u0002R\u001e\u0010\u0007\u001a\u00020\u00062\u0006\u0010\u0005\u001a\u00020\u0006@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\t\u00a8\u0006\u0015"}, d2 = {"Lcom/amaze/filemanager/ui/views/preference/PathSwitchPreference;", "Landroidx/preference/Preference;", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "<set-?>", "", "lastItemClicked", "getLastItemClicked", "()I", "onBindViewHolder", "", "holder", "Landroidx/preference/PreferenceViewHolder;", "setListener", "Landroid/view/View$OnClickListener;", "v", "Landroid/view/View;", "id", "elem", "Companion", "app_fdroidDebug"})
public final class PathSwitchPreference extends androidx.preference.Preference {
    private int lastItemClicked = -1;
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.ui.views.preference.PathSwitchPreference.Companion Companion = null;
    public static final int EDIT = 0;
    public static final int DELETE = 1;
    
    public PathSwitchPreference(@org.jetbrains.annotations.Nullable()
    android.content.Context context) {
        super(null, null, 0, 0);
    }
    
    public final int getLastItemClicked() {
        return 0;
    }
    
    @java.lang.Override()
    public void onBindViewHolder(@org.jetbrains.annotations.Nullable()
    androidx.preference.PreferenceViewHolder holder) {
    }
    
    private final android.view.View.OnClickListener setListener(android.view.View v, @androidx.annotation.IdRes()
    int id, int elem) {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0006"}, d2 = {"Lcom/amaze/filemanager/ui/views/preference/PathSwitchPreference$Companion;", "", "()V", "DELETE", "", "EDIT", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}