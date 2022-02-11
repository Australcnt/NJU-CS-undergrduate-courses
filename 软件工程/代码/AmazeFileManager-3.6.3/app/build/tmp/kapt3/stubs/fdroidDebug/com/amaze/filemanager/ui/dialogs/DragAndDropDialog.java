package com.amaze.filemanager.ui.dialogs;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000N\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\u0018\u0000 $2\u00020\u0001:\u0001$B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0017\u001a\u00020\u0018H\u0016J\u0010\u0010\u0019\u001a\u00020\u001a2\u0006\u0010\u001b\u001a\u00020\u001cH\u0016J\u0012\u0010\u001d\u001a\u00020\u001a2\b\u0010\u001e\u001a\u0004\u0018\u00010\u001fH\u0016J\u0012\u0010 \u001a\u00020!2\b\u0010\u001e\u001a\u0004\u0018\u00010\u001fH\u0016J\u0010\u0010\"\u001a\u00020\u001a2\u0006\u0010#\u001a\u00020\u0018H\u0002R\u001c\u0010\u0003\u001a\u0004\u0018\u00010\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0005\u0010\u0006\"\u0004\b\u0007\u0010\bR.\u0010\t\u001a\u0016\u0012\u0004\u0012\u00020\u000b\u0018\u00010\nj\n\u0012\u0004\u0012\u00020\u000b\u0018\u0001`\fX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\r\u0010\u000e\"\u0004\b\u000f\u0010\u0010R\u001c\u0010\u0011\u001a\u0004\u0018\u00010\u0012X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0013\u0010\u0014\"\u0004\b\u0015\u0010\u0016\u00a8\u0006%"}, d2 = {"Lcom/amaze/filemanager/ui/dialogs/DragAndDropDialog;", "Landroidx/fragment/app/DialogFragment;", "()V", "mainActivity", "Lcom/amaze/filemanager/ui/activities/MainActivity;", "getMainActivity", "()Lcom/amaze/filemanager/ui/activities/MainActivity;", "setMainActivity", "(Lcom/amaze/filemanager/ui/activities/MainActivity;)V", "operationFiles", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/filesystem/HybridFileParcelable;", "Lkotlin/collections/ArrayList;", "getOperationFiles", "()Ljava/util/ArrayList;", "setOperationFiles", "(Ljava/util/ArrayList;)V", "pasteLocation", "", "getPasteLocation", "()Ljava/lang/String;", "setPasteLocation", "(Ljava/lang/String;)V", "isCancelable", "", "onAttach", "", "context", "Landroid/content/Context;", "onCreate", "savedInstanceState", "Landroid/os/Bundle;", "onCreateDialog", "Landroid/app/Dialog;", "rememberDragOperation", "shouldMove", "Companion", "app_fdroidDebug"})
public final class DragAndDropDialog extends androidx.fragment.app.DialogFragment {
    @org.jetbrains.annotations.Nullable()
    private java.lang.String pasteLocation;
    @org.jetbrains.annotations.Nullable()
    private java.util.ArrayList<com.amaze.filemanager.filesystem.HybridFileParcelable> operationFiles;
    @org.jetbrains.annotations.Nullable()
    private com.amaze.filemanager.ui.activities.MainActivity mainActivity;
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.ui.dialogs.DragAndDropDialog.Companion Companion = null;
    private static final java.lang.String KEY_PASTE_LOCATION = "pasteLocation";
    private static final java.lang.String KEY_FILES = "files";
    
    public DragAndDropDialog() {
        super();
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String getPasteLocation() {
        return null;
    }
    
    public final void setPasteLocation(@org.jetbrains.annotations.Nullable()
    java.lang.String p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.util.ArrayList<com.amaze.filemanager.filesystem.HybridFileParcelable> getOperationFiles() {
        return null;
    }
    
    public final void setOperationFiles(@org.jetbrains.annotations.Nullable()
    java.util.ArrayList<com.amaze.filemanager.filesystem.HybridFileParcelable> p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.amaze.filemanager.ui.activities.MainActivity getMainActivity() {
        return null;
    }
    
    public final void setMainActivity(@org.jetbrains.annotations.Nullable()
    com.amaze.filemanager.ui.activities.MainActivity p0) {
    }
    
    @java.lang.Override()
    public void onAttach(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
    }
    
    @java.lang.Override()
    public void onCreate(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.app.Dialog onCreateDialog(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
        return null;
    }
    
    @java.lang.Override()
    public boolean isCancelable() {
        return false;
    }
    
    private final void rememberDragOperation(boolean shouldMove) {
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000@\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J(\u0010\u0006\u001a\u00020\u00072\u0006\u0010\b\u001a\u00020\u00042\u0016\u0010\t\u001a\u0012\u0012\u0004\u0012\u00020\u000b0\nj\b\u0012\u0004\u0012\u00020\u000b`\fH\u0002J.\u0010\r\u001a\u00020\u000e2\u0006\u0010\b\u001a\u00020\u00042\u0016\u0010\t\u001a\u0012\u0012\u0004\u0012\u00020\u000b0\nj\b\u0012\u0004\u0012\u00020\u000b`\f2\u0006\u0010\u000f\u001a\u00020\u0010J8\u0010\u0011\u001a\u00020\u000e2\u0006\u0010\b\u001a\u00020\u00042\u0016\u0010\t\u001a\u0012\u0012\u0004\u0012\u00020\u000b0\nj\b\u0012\u0004\u0012\u00020\u000b`\f2\u0006\u0010\u0012\u001a\u00020\u00132\u0006\u0010\u0014\u001a\u00020\u0010H\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0015"}, d2 = {"Lcom/amaze/filemanager/ui/dialogs/DragAndDropDialog$Companion;", "", "()V", "KEY_FILES", "", "KEY_PASTE_LOCATION", "newInstance", "Lcom/amaze/filemanager/ui/dialogs/DragAndDropDialog;", "pasteLocation", "files", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/filesystem/HybridFileParcelable;", "Lkotlin/collections/ArrayList;", "showDialogOrPerformOperation", "", "activity", "Lcom/amaze/filemanager/ui/activities/MainActivity;", "startCopyOrMoveTask", "move", "", "mainActivity", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
        
        /**
         * Show move / copy dialog on drop or perform the operation directly based on
         * remember preference selected by user previously in this dialog
         */
        public final void showDialogOrPerformOperation(@org.jetbrains.annotations.NotNull()
        java.lang.String pasteLocation, @org.jetbrains.annotations.NotNull()
        java.util.ArrayList<com.amaze.filemanager.filesystem.HybridFileParcelable> files, @org.jetbrains.annotations.NotNull()
        com.amaze.filemanager.ui.activities.MainActivity activity) {
        }
        
        private final com.amaze.filemanager.ui.dialogs.DragAndDropDialog newInstance(java.lang.String pasteLocation, java.util.ArrayList<com.amaze.filemanager.filesystem.HybridFileParcelable> files) {
            return null;
        }
        
        private final void startCopyOrMoveTask(java.lang.String pasteLocation, java.util.ArrayList<com.amaze.filemanager.filesystem.HybridFileParcelable> files, boolean move, com.amaze.filemanager.ui.activities.MainActivity mainActivity) {
        }
    }
}