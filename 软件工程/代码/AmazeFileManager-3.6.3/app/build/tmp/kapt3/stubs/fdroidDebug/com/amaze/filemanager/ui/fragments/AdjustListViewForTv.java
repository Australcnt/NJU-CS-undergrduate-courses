package com.amaze.filemanager.ui.fragments;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\bf\u0018\u0000*\n\b\u0000\u0010\u0001 \u0000*\u00020\u00022\u00020\u0003J\u001d\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00028\u00002\u0006\u0010\u0007\u001a\u00020\bH&\u00a2\u0006\u0002\u0010\t\u00a8\u0006\n"}, d2 = {"Lcom/amaze/filemanager/ui/fragments/AdjustListViewForTv;", "T", "Landroidx/recyclerview/widget/RecyclerView$ViewHolder;", "", "adjustListViewForTv", "", "viewHolder", "mainActivity", "Lcom/amaze/filemanager/ui/activities/MainActivity;", "(Landroidx/recyclerview/widget/RecyclerView$ViewHolder;Lcom/amaze/filemanager/ui/activities/MainActivity;)V", "app_fdroidDebug"})
public abstract interface AdjustListViewForTv<T extends androidx.recyclerview.widget.RecyclerView.ViewHolder> {
    
    /**
     * Adjust list view focus scroll when using dpad.
     * Scroll few more elements up / down so that it's easier for user to see list
     */
    public abstract void adjustListViewForTv(@org.jetbrains.annotations.NotNull()
    T viewHolder, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.ui.activities.MainActivity mainActivity);
}