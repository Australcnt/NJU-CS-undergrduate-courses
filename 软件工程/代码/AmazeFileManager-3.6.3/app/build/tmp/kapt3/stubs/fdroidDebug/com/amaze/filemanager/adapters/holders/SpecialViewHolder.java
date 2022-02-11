package com.amaze.filemanager.adapters.holders;

import java.lang.System;

/**
 * Check [com.amaze.filemanager.adapters.RecyclerAdapter]'s doc.
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\u0018\u0000 \u000f2\u00020\u0001:\u0001\u000fB%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nR\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000e\u00a8\u0006\u0010"}, d2 = {"Lcom/amaze/filemanager/adapters/holders/SpecialViewHolder;", "Landroidx/recyclerview/widget/RecyclerView$ViewHolder;", "c", "Landroid/content/Context;", "view", "Landroid/view/View;", "utilsProvider", "Lcom/amaze/filemanager/ui/provider/UtilitiesProvider;", "type", "", "(Landroid/content/Context;Landroid/view/View;Lcom/amaze/filemanager/ui/provider/UtilitiesProvider;I)V", "txtTitle", "Landroid/widget/TextView;", "getType", "()I", "Companion", "app_fdroidDebug"})
public final class SpecialViewHolder extends androidx.recyclerview.widget.RecyclerView.ViewHolder {
    private final int type = 0;
    private final android.widget.TextView txtTitle = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.adapters.holders.SpecialViewHolder.Companion Companion = null;
    public static final int HEADER_FILES = 0;
    public static final int HEADER_FOLDERS = 1;
    
    public SpecialViewHolder(@org.jetbrains.annotations.NotNull()
    android.content.Context c, @org.jetbrains.annotations.NotNull()
    android.view.View view, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.ui.provider.UtilitiesProvider utilsProvider, int type) {
        super(null);
    }
    
    public final int getType() {
        return 0;
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0006"}, d2 = {"Lcom/amaze/filemanager/adapters/holders/SpecialViewHolder$Companion;", "", "()V", "HEADER_FILES", "", "HEADER_FOLDERS", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}