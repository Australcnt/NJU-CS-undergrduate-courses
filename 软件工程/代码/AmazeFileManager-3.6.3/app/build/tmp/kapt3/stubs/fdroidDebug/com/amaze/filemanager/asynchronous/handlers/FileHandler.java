package com.amaze.filemanager.asynchronous.handlers;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B\u001d\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u0010\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\rH\u0016R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00030\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u000e"}, d2 = {"Lcom/amaze/filemanager/asynchronous/handlers/FileHandler;", "Landroid/os/Handler;", "mainFragment", "Lcom/amaze/filemanager/ui/fragments/MainFragment;", "listView", "Landroidx/recyclerview/widget/RecyclerView;", "useThumbs", "", "(Lcom/amaze/filemanager/ui/fragments/MainFragment;Landroidx/recyclerview/widget/RecyclerView;Z)V", "Ljava/lang/ref/WeakReference;", "handleMessage", "", "msg", "Landroid/os/Message;", "app_fdroidDebug"})
public final class FileHandler extends android.os.Handler {
    private final androidx.recyclerview.widget.RecyclerView listView = null;
    private final boolean useThumbs = false;
    private final java.lang.ref.WeakReference<com.amaze.filemanager.ui.fragments.MainFragment> mainFragment = null;
    
    public FileHandler(@org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.ui.fragments.MainFragment mainFragment, @org.jetbrains.annotations.NotNull()
    androidx.recyclerview.widget.RecyclerView listView, boolean useThumbs) {
        super();
    }
    
    @java.lang.Override()
    public void handleMessage(@org.jetbrains.annotations.NotNull()
    android.os.Message msg) {
    }
}