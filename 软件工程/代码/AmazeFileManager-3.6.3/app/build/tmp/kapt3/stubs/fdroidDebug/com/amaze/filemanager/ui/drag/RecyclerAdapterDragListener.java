package com.amaze.filemanager.ui.drag;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B\'\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u001c\u0010\r\u001a\u00020\u000e2\b\u0010\u000f\u001a\u0004\u0018\u00010\u00102\b\u0010\u0011\u001a\u0004\u0018\u00010\u0012H\u0016R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0004\u001a\u0004\u0018\u00010\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0013"}, d2 = {"Lcom/amaze/filemanager/ui/drag/RecyclerAdapterDragListener;", "Landroid/view/View$OnDragListener;", "adapter", "Lcom/amaze/filemanager/adapters/RecyclerAdapter;", "holder", "Lcom/amaze/filemanager/adapters/holders/ItemViewHolder;", "dragAndDropPref", "", "mainFragment", "Lcom/amaze/filemanager/ui/fragments/MainFragment;", "(Lcom/amaze/filemanager/adapters/RecyclerAdapter;Lcom/amaze/filemanager/adapters/holders/ItemViewHolder;ILcom/amaze/filemanager/ui/fragments/MainFragment;)V", "TAG", "", "onDrag", "", "p0", "Landroid/view/View;", "p1", "Landroid/view/DragEvent;", "app_fdroidDebug"})
public final class RecyclerAdapterDragListener implements android.view.View.OnDragListener {
    private final com.amaze.filemanager.adapters.RecyclerAdapter adapter = null;
    private final com.amaze.filemanager.adapters.holders.ItemViewHolder holder = null;
    private final int dragAndDropPref = 0;
    private final com.amaze.filemanager.ui.fragments.MainFragment mainFragment = null;
    private final java.lang.String TAG = null;
    
    public RecyclerAdapterDragListener(@org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.adapters.RecyclerAdapter adapter, @org.jetbrains.annotations.Nullable()
    com.amaze.filemanager.adapters.holders.ItemViewHolder holder, int dragAndDropPref, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.ui.fragments.MainFragment mainFragment) {
        super();
    }
    
    @java.lang.Override()
    public boolean onDrag(@org.jetbrains.annotations.Nullable()
    android.view.View p0, @org.jetbrains.annotations.Nullable()
    android.view.DragEvent p1) {
        return false;
    }
}