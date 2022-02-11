package com.amaze.filemanager.adapters;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000z\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010 \n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001B9\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\f\u0010\t\u001a\b\u0012\u0004\u0012\u00020\u000b0\n\u0012\f\u0010\f\u001a\b\u0012\u0004\u0012\u00020\u000e0\r\u00a2\u0006\u0002\u0010\u000fJ\b\u0010\u0016\u001a\u00020\u0017H\u0016J\u0018\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u00022\u0006\u0010\u001b\u001a\u00020\u0017H\u0016J\u0018\u0010\u001c\u001a\u00020\u00022\u0006\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020\u0017H\u0016J\u0010\u0010 \u001a\u00020\u00192\u0006\u0010!\u001a\u00020\u000eH\u0002J\u0010\u0010\"\u001a\u00020\u00192\u0006\u0010!\u001a\u00020\u000eH\u0002J\u0010\u0010#\u001a\u00020\u00192\u0006\u0010!\u001a\u00020\u000eH\u0002J \u0010$\u001a\u00020\u00192\u0006\u0010!\u001a\u00020\u000e2\u0006\u0010%\u001a\u00020&2\u0006\u0010\'\u001a\u00020\u0017H\u0002J \u0010(\u001a\u00020\u00192\u0006\u0010!\u001a\u00020\u000e2\u0006\u0010%\u001a\u00020&2\u0006\u0010\'\u001a\u00020\u0017H\u0002J\u001c\u0010)\u001a\u00020\u00192\f\u0010*\u001a\b\u0012\u0004\u0012\u00020\u000e0+2\u0006\u0010,\u001a\u00020\bJ \u0010-\u001a\u00020\u00192\u0006\u0010%\u001a\u00020&2\u0006\u0010\'\u001a\u00020\u00172\u0006\u0010.\u001a\u00020/H\u0002J\u001a\u00100\u001a\u00020\u00192\u0006\u00101\u001a\u0002022\b\u00103\u001a\u0004\u0018\u00010\u000eH\u0002J\u0012\u00104\u001a\u00020\u00192\b\u00103\u001a\u0004\u0018\u00010\u000eH\u0002R\u0014\u0010\t\u001a\b\u0012\u0004\u0012\u00020\u000b0\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\f\u001a\b\u0012\u0004\u0012\u00020\u000e0\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0010\u001a\u00020\u00118BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0012\u0010\u0013R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u00065"}, d2 = {"Lcom/amaze/filemanager/adapters/AppsRecyclerAdapter;", "Landroidx/recyclerview/widget/RecyclerView$Adapter;", "Landroidx/recyclerview/widget/RecyclerView$ViewHolder;", "fragment", "Landroidx/fragment/app/Fragment;", "modelProvider", "Lcom/amaze/filemanager/adapters/glide/AppsAdapterPreloadModel;", "isBottomSheet", "", "adjustListViewCallback", "Lcom/amaze/filemanager/ui/fragments/AdjustListViewForTv;", "Lcom/amaze/filemanager/adapters/holders/AppHolder;", "appDataParcelableList", "", "Lcom/amaze/filemanager/adapters/data/AppDataParcelable;", "(Landroidx/fragment/app/Fragment;Lcom/amaze/filemanager/adapters/glide/AppsAdapterPreloadModel;ZLcom/amaze/filemanager/ui/fragments/AdjustListViewForTv;Ljava/util/List;)V", "mInflater", "Landroid/view/LayoutInflater;", "getMInflater", "()Landroid/view/LayoutInflater;", "myChecked", "Landroid/util/SparseBooleanArray;", "getItemCount", "", "onBindViewHolder", "", "holder", "position", "onCreateViewHolder", "parent", "Landroid/view/ViewGroup;", "viewType", "popupBackup", "appDataParcelable", "popupOpen", "popupPlay", "popupShare", "themedActivity", "Lcom/amaze/filemanager/ui/activities/superclasses/ThemedActivity;", "colorAccent", "popupUninstall", "setData", "data", "", "showSystemApps", "showDeleteSystemAppDialog", "f1", "Lcom/amaze/filemanager/filesystem/HybridFileParcelable;", "showPopup", "v", "Landroid/view/View;", "rowItem", "startActivityForRowItem", "app_fdroidDebug"})
public final class AppsRecyclerAdapter extends androidx.recyclerview.widget.RecyclerView.Adapter<androidx.recyclerview.widget.RecyclerView.ViewHolder> {
    private final androidx.fragment.app.Fragment fragment = null;
    private final com.amaze.filemanager.adapters.glide.AppsAdapterPreloadModel modelProvider = null;
    private final boolean isBottomSheet = false;
    private final com.amaze.filemanager.ui.fragments.AdjustListViewForTv<com.amaze.filemanager.adapters.holders.AppHolder> adjustListViewCallback = null;
    private final java.util.List<com.amaze.filemanager.adapters.data.AppDataParcelable> appDataParcelableList = null;
    private final android.util.SparseBooleanArray myChecked = null;
    
    public AppsRecyclerAdapter(@org.jetbrains.annotations.NotNull()
    androidx.fragment.app.Fragment fragment, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.adapters.glide.AppsAdapterPreloadModel modelProvider, boolean isBottomSheet, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.ui.fragments.AdjustListViewForTv<? super com.amaze.filemanager.adapters.holders.AppHolder> adjustListViewCallback, @org.jetbrains.annotations.NotNull()
    java.util.List<com.amaze.filemanager.adapters.data.AppDataParcelable> appDataParcelableList) {
        super();
    }
    
    private final android.view.LayoutInflater getMInflater() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public androidx.recyclerview.widget.RecyclerView.ViewHolder onCreateViewHolder(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup parent, int viewType) {
        return null;
    }
    
    @java.lang.Override()
    public void onBindViewHolder(@org.jetbrains.annotations.NotNull()
    androidx.recyclerview.widget.RecyclerView.ViewHolder holder, int position) {
    }
    
    @java.lang.Override()
    public int getItemCount() {
        return 0;
    }
    
    /**
     * Set list elements
     * @param showSystemApps whether to filter system apps or not
     */
    public final void setData(@org.jetbrains.annotations.NotNull()
    java.util.List<com.amaze.filemanager.adapters.data.AppDataParcelable> data, boolean showSystemApps) {
    }
    
    private final void startActivityForRowItem(com.amaze.filemanager.adapters.data.AppDataParcelable rowItem) {
    }
    
    private final void showPopup(android.view.View v, com.amaze.filemanager.adapters.data.AppDataParcelable rowItem) {
    }
    
    private final void popupOpen(com.amaze.filemanager.adapters.data.AppDataParcelable appDataParcelable) {
    }
    
    private final void popupShare(com.amaze.filemanager.adapters.data.AppDataParcelable appDataParcelable, com.amaze.filemanager.ui.activities.superclasses.ThemedActivity themedActivity, int colorAccent) {
    }
    
    private final void popupUninstall(com.amaze.filemanager.adapters.data.AppDataParcelable appDataParcelable, com.amaze.filemanager.ui.activities.superclasses.ThemedActivity themedActivity, int colorAccent) {
    }
    
    private final void popupPlay(com.amaze.filemanager.adapters.data.AppDataParcelable appDataParcelable) {
    }
    
    private final void popupBackup(com.amaze.filemanager.adapters.data.AppDataParcelable appDataParcelable) {
    }
    
    private final void showDeleteSystemAppDialog(com.amaze.filemanager.ui.activities.superclasses.ThemedActivity themedActivity, int colorAccent, com.amaze.filemanager.filesystem.HybridFileParcelable f1) {
    }
}