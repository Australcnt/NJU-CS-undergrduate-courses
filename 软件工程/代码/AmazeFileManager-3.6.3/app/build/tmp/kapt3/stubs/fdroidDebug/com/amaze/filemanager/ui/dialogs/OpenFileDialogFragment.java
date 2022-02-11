package com.amaze.filemanager.ui.dialogs;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0084\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\u0018\u0000 42\u00020\u00012\b\u0012\u0004\u0012\u00020\u00030\u0002:\u00014B\u0005\u00a2\u0006\u0002\u0010\u0004J\u0018\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u00032\u0006\u0010\u001a\u001a\u00020\u001bH\u0016J\u0016\u0010\u001c\u001a\b\u0012\u0004\u0012\u00020\u001e0\u001d2\u0006\u0010\u001f\u001a\u00020 H\u0002J(\u0010!\u001a\u0004\u0018\u00010\u001e2\u000e\u0010\"\u001a\n\u0012\u0004\u0012\u00020\n\u0018\u00010#2\f\u0010$\u001a\b\u0012\u0004\u0012\u00020\u001e0\u001dH\u0002J\u0010\u0010%\u001a\u00020\u00182\u0006\u0010&\u001a\u00020\u001eH\u0002J\u0012\u0010\'\u001a\u00020\u00182\b\u0010(\u001a\u0004\u0018\u00010)H\u0016J&\u0010*\u001a\u0004\u0018\u00010+2\u0006\u0010,\u001a\u00020-2\b\u0010.\u001a\u0004\u0018\u00010/2\b\u0010(\u001a\u0004\u0018\u00010)H\u0016J\b\u00100\u001a\u00020\u0018H\u0016J\b\u00101\u001a\u00020\u0018H\u0016J\u001a\u00102\u001a\u00020\u00182\u0006\u00103\u001a\u00020+2\b\u0010(\u001a\u0004\u0018\u00010)H\u0016R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082.\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0007\u001a\u0004\u0018\u00010\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\t\u001a\u0004\u0018\u00010\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082.\u00a2\u0006\u0002\n\u0000R\u0010\u0010\r\u001a\u0004\u0018\u00010\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u000f\u001a\u0004\u0018\u00010\u0010X\u0082\u000e\u00a2\u0006\u0004\n\u0002\u0010\u0011R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082.\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0014\u001a\u00020\b8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0015\u0010\u0016\u00a8\u00065"}, d2 = {"Lcom/amaze/filemanager/ui/dialogs/OpenFileDialogFragment;", "Lcom/amaze/filemanager/ui/base/BaseBottomSheetFragment;", "Lcom/amaze/filemanager/ui/fragments/AdjustListViewForTv;", "Lcom/amaze/filemanager/adapters/holders/AppHolder;", "()V", "adapter", "Lcom/amaze/filemanager/adapters/AppsRecyclerAdapter;", "fragmentOpenFileDialogBinding", "Lcom/amaze/filemanager/databinding/FragmentOpenFileDialogBinding;", "mimeType", "", "sharedPreferences", "Landroid/content/SharedPreferences;", "uri", "Landroid/net/Uri;", "useNewStack", "", "Ljava/lang/Boolean;", "utilsProvider", "Lcom/amaze/filemanager/ui/provider/UtilitiesProvider;", "viewBinding", "getViewBinding", "()Lcom/amaze/filemanager/databinding/FragmentOpenFileDialogBinding;", "adjustListViewForTv", "", "viewHolder", "mainActivity", "Lcom/amaze/filemanager/ui/activities/MainActivity;", "initAppDataParcelableList", "", "Lcom/amaze/filemanager/adapters/data/AppDataParcelable;", "intent", "Landroid/content/Intent;", "initLastAppData", "lastClassAndPackage", "", "appDataParcelableList", "loadViews", "lastAppData", "onCreate", "savedInstanceState", "Landroid/os/Bundle;", "onCreateView", "Landroid/view/View;", "inflater", "Landroid/view/LayoutInflater;", "container", "Landroid/view/ViewGroup;", "onDestroyView", "onPause", "onViewCreated", "view", "Companion", "app_fdroidDebug"})
public final class OpenFileDialogFragment extends com.amaze.filemanager.ui.base.BaseBottomSheetFragment implements com.amaze.filemanager.ui.fragments.AdjustListViewForTv<com.amaze.filemanager.adapters.holders.AppHolder> {
    private android.net.Uri uri;
    private java.lang.String mimeType;
    private java.lang.Boolean useNewStack;
    private com.amaze.filemanager.databinding.FragmentOpenFileDialogBinding fragmentOpenFileDialogBinding;
    private com.amaze.filemanager.adapters.AppsRecyclerAdapter adapter;
    private com.amaze.filemanager.ui.provider.UtilitiesProvider utilsProvider;
    private android.content.SharedPreferences sharedPreferences;
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.ui.dialogs.OpenFileDialogFragment.Companion Companion = null;
    private static final java.lang.String TAG = null;
    private static final java.lang.String KEY_URI = "uri";
    private static final java.lang.String KEY_MIME_TYPE = "mime_type";
    private static final java.lang.String KEY_USE_NEW_STACK = "use_new_stack";
    private static final java.lang.String KEY_PREFERENCES_DEFAULT = "_DEFAULT";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String KEY_PREFERENCES_LAST = "_LAST";
    
    public OpenFileDialogFragment() {
        super();
    }
    
    private final com.amaze.filemanager.databinding.FragmentOpenFileDialogBinding getViewBinding() {
        return null;
    }
    
    @java.lang.Override()
    public void onCreate(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public android.view.View onCreateView(@org.jetbrains.annotations.NotNull()
    android.view.LayoutInflater inflater, @org.jetbrains.annotations.Nullable()
    android.view.ViewGroup container, @org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
        return null;
    }
    
    @java.lang.Override()
    public void onDestroyView() {
    }
    
    @java.lang.Override()
    public void onViewCreated(@org.jetbrains.annotations.NotNull()
    android.view.View view, @org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
    }
    
    @java.lang.Override()
    public void onPause() {
    }
    
    private final void loadViews(com.amaze.filemanager.adapters.data.AppDataParcelable lastAppData) {
    }
    
    private final java.util.List<com.amaze.filemanager.adapters.data.AppDataParcelable> initAppDataParcelableList(android.content.Intent intent) {
        return null;
    }
    
    private final com.amaze.filemanager.adapters.data.AppDataParcelable initLastAppData(java.util.List<java.lang.String> lastClassAndPackage, java.util.List<com.amaze.filemanager.adapters.data.AppDataParcelable> appDataParcelableList) {
        return null;
    }
    
    @java.lang.Override()
    public void adjustListViewForTv(@org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.adapters.holders.AppHolder viewHolder, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.ui.activities.MainActivity mainActivity) {
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000V\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J2\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u00042\u0006\u0010\u000f\u001a\u00020\u00102\b\u0010\u0011\u001a\u0004\u0018\u00010\u00042\b\u0010\u0012\u001a\u0004\u0018\u00010\u0004J\u0018\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u000e\u001a\u00020\u00042\u0006\u0010\u0015\u001a\u00020\u0016H\u0002J\u000e\u0010\u0017\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0016J(\u0010\u0018\u001a\u00020\u00102\u0006\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u00042\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0019\u001a\u00020\u001aH\u0002J \u0010\u001b\u001a\u00020\u001c2\u0006\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u00042\u0006\u0010\u000f\u001a\u00020\u0010H\u0002J.\u0010\u001d\u001a\u00020\u00142\u0006\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u00042\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0019\u001a\u00020\u001a2\u0006\u0010\u001e\u001a\u00020\u0010J\u0018\u0010\u001f\u001a\u00020\u00142\u0006\u0010 \u001a\u00020!2\u0006\u0010\"\u001a\u00020\u001aH\u0002J\u0016\u0010#\u001a\u00020\u00142\u0006\u0010 \u001a\u00020!2\u0006\u0010\"\u001a\u00020\u001aJ\u0018\u0010$\u001a\u00020\u00142\u0006\u0010%\u001a\u00020&2\u0006\u0010\'\u001a\u00020\u000bH\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006("}, d2 = {"Lcom/amaze/filemanager/ui/dialogs/OpenFileDialogFragment$Companion;", "", "()V", "KEY_MIME_TYPE", "", "KEY_PREFERENCES_DEFAULT", "KEY_PREFERENCES_LAST", "KEY_URI", "KEY_USE_NEW_STACK", "TAG", "buildIntent", "Landroid/content/Intent;", "uri", "Landroid/net/Uri;", "mimeType", "useNewStack", "", "className", "packageName", "clearMimeTypePreference", "", "sharedPreferences", "Landroid/content/SharedPreferences;", "clearPreferences", "getPreferenceAndStartActivity", "activity", "Lcom/amaze/filemanager/ui/activities/superclasses/PreferenceActivity;", "newInstance", "Lcom/amaze/filemanager/ui/dialogs/OpenFileDialogFragment;", "openFileOrShow", "forceChooser", "setDefaultOpenedApp", "appDataParcelable", "Lcom/amaze/filemanager/adapters/data/AppDataParcelable;", "preferenceActivity", "setLastOpenedApp", "startActivity", "context", "Landroid/content/Context;", "intent", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
        
        /**
         * Opens the file using previously set default app or shows a bottom sheet dialog
         */
        public final void openFileOrShow(@org.jetbrains.annotations.NotNull()
        android.net.Uri uri, @org.jetbrains.annotations.NotNull()
        java.lang.String mimeType, boolean useNewStack, @org.jetbrains.annotations.NotNull()
        com.amaze.filemanager.ui.activities.superclasses.PreferenceActivity activity, boolean forceChooser) {
        }
        
        private final com.amaze.filemanager.ui.dialogs.OpenFileDialogFragment newInstance(android.net.Uri uri, java.lang.String mimeType, boolean useNewStack) {
            return null;
        }
        
        private final void startActivity(android.content.Context context, android.content.Intent intent) {
        }
        
        /**
         * Builds an intent which necessary permission flags for external apps to open uri file
         */
        @org.jetbrains.annotations.NotNull()
        public final android.content.Intent buildIntent(@org.jetbrains.annotations.NotNull()
        android.net.Uri uri, @org.jetbrains.annotations.NotNull()
        java.lang.String mimeType, boolean useNewStack, @org.jetbrains.annotations.Nullable()
        java.lang.String className, @org.jetbrains.annotations.Nullable()
        java.lang.String packageName) {
            return null;
        }
        
        private final boolean getPreferenceAndStartActivity(android.net.Uri uri, java.lang.String mimeType, boolean useNewStack, com.amaze.filemanager.ui.activities.superclasses.PreferenceActivity activity) {
            return false;
        }
        
        /**
         * Sets last open app preference for bottom sheet file chooser.
         * Next time same mime type comes, this app will be shown on top of the list if present
         */
        public final void setLastOpenedApp(@org.jetbrains.annotations.NotNull()
        com.amaze.filemanager.adapters.data.AppDataParcelable appDataParcelable, @org.jetbrains.annotations.NotNull()
        com.amaze.filemanager.ui.activities.superclasses.PreferenceActivity preferenceActivity) {
        }
        
        /**
         * Sets default app for mime type selected using 'Always' button from bottom sheet
         */
        private final void setDefaultOpenedApp(com.amaze.filemanager.adapters.data.AppDataParcelable appDataParcelable, com.amaze.filemanager.ui.activities.superclasses.PreferenceActivity preferenceActivity) {
        }
        
        /**
         * Clears all default apps set preferences for mime types
         */
        public final void clearPreferences(@org.jetbrains.annotations.NotNull()
        android.content.SharedPreferences sharedPreferences) {
        }
        
        private final void clearMimeTypePreference(java.lang.String mimeType, android.content.SharedPreferences sharedPreferences) {
        }
    }
}