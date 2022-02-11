package com.amaze.filemanager.ui.fragments;

import java.lang.System;

@kotlin.Suppress(names = {"TooManyFunctions"})
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u00c2\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u000b\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u000f\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u0003\n\u0002\b\u0004\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\f\n\u0002\u0018\u0002\n\u0002\b\u0004\u0018\u0000 x2\u00020\u00012\u00020\u0002:\u0001xB\u0005\u00a2\u0006\u0002\u0010\u0003J\u0012\u0010U\u001a\u00020V2\b\u0010W\u001a\u0004\u0018\u00010XH\u0002J\u0006\u0010Y\u001a\u00020\u0007J\u0010\u0010Z\u001a\u00020V2\u0006\u00109\u001a\u00020:H\u0016J \u0010[\u001a\u00020V2\u000e\u0010\\\u001a\n\u0012\u0004\u0012\u00020^\u0018\u00010]2\u0006\u0010_\u001a\u00020:H\u0002J\u0006\u0010`\u001a\u00020VJ\u0012\u0010a\u001a\u00020\u00072\b\u0010\u001f\u001a\u0004\u0018\u00010:H\u0002J$\u0010b\u001a\u0002062\u0006\u0010c\u001a\u00020d2\b\u0010e\u001a\u0004\u0018\u00010f2\b\u0010g\u001a\u0004\u0018\u00010hH\u0016J\b\u0010i\u001a\u00020VH\u0016J\b\u0010j\u001a\u00020VH\u0016J\u0012\u0010k\u001a\u00020V2\b\u0010g\u001a\u0004\u0018\u00010hH\u0002J\b\u0010l\u001a\u00020VH\u0016J\u0010\u0010m\u001a\u00020V2\u0006\u0010n\u001a\u00020hH\u0016J\u001a\u0010o\u001a\u00020V2\u0006\u0010p\u001a\u0002062\b\u0010g\u001a\u0004\u0018\u00010hH\u0016J\u0010\u0010q\u001a\u00020:2\u0006\u0010r\u001a\u00020:H\u0002J\b\u0010s\u001a\u00020VH\u0002J\u0006\u0010t\u001a\u00020uJ\u0006\u0010v\u001a\u00020VJ\b\u0010w\u001a\u00020VH\u0002R\u0012\u0010\u0004\u001a\u00020\u00058\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\b\u001a\u00020\u00078\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u001c\u0010\t\u001a\u0004\u0018\u00010\nX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\f\"\u0004\b\r\u0010\u000eR\u001a\u0010\u000f\u001a\u00020\u0010X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0011\u0010\u0012\"\u0004\b\u0013\u0010\u0014R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082.\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0017\u001a\u0004\u0018\u00010\u0018X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0019\u001a\u00020\u001aX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001b\u001a\u00020\u0005X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u001c\u001a\n\u0012\u0004\u0012\u00020\u001e\u0018\u00010\u001d8\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001f\u001a\u00020\u0005X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010 \u001a\u00020\u0007X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b!\u0010\"\"\u0004\b#\u0010$R\u0012\u0010%\u001a\u00020\u00058\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010&\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\'\u001a\u00020\u00078\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010(\u001a\u00020\u00078BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b(\u0010\"R\u001c\u0010)\u001a\u0004\u0018\u00010*X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b+\u0010,\"\u0004\b-\u0010.R\u0014\u0010/\u001a\u0004\u0018\u0001008\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u00101\u001a\u0002028\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u00103\u001a\u000204X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u00105\u001a\u0004\u0018\u000106X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u00107\u001a\u000208X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u00109\u001a\u00020:8VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b;\u0010<R\u001a\u0010=\u001a\u00020:X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b>\u0010<\"\u0004\b?\u0010@R\u0014\u0010A\u001a\u00020\u00058VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\bB\u0010CR\u0012\u0010D\u001a\u00020\u00078\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010E\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010F\u001a\u00020\u00078\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010G\u001a\u00020\u00078\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010H\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010I\u001a\u00020JX\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\bK\u0010L\"\u0004\bM\u0010NR\u001b\u0010O\u001a\u00020P8BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\bS\u0010T\u001a\u0004\bQ\u0010R\u00a8\u0006y"}, d2 = {"Lcom/amaze/filemanager/ui/fragments/CompressedExplorerFragment;", "Landroidx/fragment/app/Fragment;", "Lcom/amaze/filemanager/utils/BottomBarButtonPath;", "()V", "accentColor", "", "addheader", "", "coloriseIcons", "compressedExplorerAdapter", "Lcom/amaze/filemanager/adapters/CompressedExplorerAdapter;", "getCompressedExplorerAdapter", "()Lcom/amaze/filemanager/adapters/CompressedExplorerAdapter;", "setCompressedExplorerAdapter", "(Lcom/amaze/filemanager/adapters/CompressedExplorerAdapter;)V", "compressedFile", "Ljava/io/File;", "getCompressedFile", "()Ljava/io/File;", "setCompressedFile", "(Ljava/io/File;)V", "decompressor", "Lcom/amaze/filemanager/filesystem/compressed/showcontents/Decompressor;", "dividerItemDecoration", "Lcom/amaze/filemanager/ui/views/DividerItemDecoration;", "fastScroller", "Lcom/amaze/filemanager/ui/views/FastScroller;", "file", "files", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/filesystem/HybridFileParcelable;", "folder", "gobackitem", "getGobackitem", "()Z", "setGobackitem", "(Z)V", "iconskin", "isCachedCompressedFile", "isOpen", "isRootRelativePath", "listView", "Landroidx/recyclerview/widget/RecyclerView;", "getListView", "()Landroidx/recyclerview/widget/RecyclerView;", "setListView", "(Landroidx/recyclerview/widget/RecyclerView;)V", "mActionMode", "Landroid/view/ActionMode;", "mActionModeCallback", "Landroid/view/ActionMode$Callback;", "mServiceConnection", "Landroid/content/ServiceConnection;", "mToolbarContainer", "Landroid/view/View;", "offsetListenerForToolbar", "Lcom/google/android/material/appbar/AppBarLayout$OnOffsetChangedListener;", "path", "", "getPath", "()Ljava/lang/String;", "relativeDirectory", "getRelativeDirectory", "setRelativeDirectory", "(Ljava/lang/String;)V", "rootDrawable", "getRootDrawable", "()I", "selection", "showDividers", "showLastModified", "showSize", "stopAnims", "swipeRefreshLayout", "Landroidx/swiperefreshlayout/widget/SwipeRefreshLayout;", "getSwipeRefreshLayout", "()Landroidx/swiperefreshlayout/widget/SwipeRefreshLayout;", "setSwipeRefreshLayout", "(Landroidx/swiperefreshlayout/widget/SwipeRefreshLayout;)V", "viewModel", "Lcom/amaze/filemanager/ui/fragments/data/CompressedExplorerFragmentViewModel;", "getViewModel", "()Lcom/amaze/filemanager/ui/fragments/data/CompressedExplorerFragmentViewModel;", "viewModel$delegate", "Lkotlin/Lazy;", "archiveCorruptOrUnsupportedToast", "", "e", "", "canGoBack", "changePath", "createViews", "items", "", "Lcom/amaze/filemanager/adapters/data/CompressedObjectParcelable;", "dir", "goBack", "isRoot", "onCreateView", "inflater", "Landroid/view/LayoutInflater;", "container", "Landroid/view/ViewGroup;", "savedInstanceState", "Landroid/os/Bundle;", "onDestroyView", "onPause", "onRestoreInstanceState", "onResume", "onSaveInstanceState", "outState", "onViewCreated", "view", "prepareCompressedFile", "pathArg", "refresh", "requireMainActivity", "Lcom/amaze/filemanager/ui/activities/MainActivity;", "stopAnim", "updateBottomBar", "Companion", "app_fdroidDebug"})
public final class CompressedExplorerFragment extends androidx.fragment.app.Fragment implements com.amaze.filemanager.utils.BottomBarButtonPath {
    public java.io.File compressedFile;
    private final kotlin.Lazy viewModel$delegate = null;
    
    /**
     * files to be deleted from cache with a Map maintaining key - the root of directory created (for
     * deletion purposes after we exit out of here and value - the path of file to open
     */
    @org.jetbrains.annotations.Nullable()
    public java.util.ArrayList<com.amaze.filemanager.filesystem.HybridFileParcelable> files;
    public boolean selection = false;
    
    /**
     * Normally this would be "/" but for pathing issues it isn't
     */
    @org.jetbrains.annotations.NotNull()
    private java.lang.String relativeDirectory = "";
    @androidx.annotation.ColorInt()
    public int accentColor = 0;
    @androidx.annotation.ColorInt()
    public int iconskin = 0;
    @org.jetbrains.annotations.Nullable()
    private com.amaze.filemanager.adapters.CompressedExplorerAdapter compressedExplorerAdapter;
    @org.jetbrains.annotations.Nullable()
    public android.view.ActionMode mActionMode;
    public boolean coloriseIcons = false;
    public boolean showSize = false;
    public boolean showLastModified = false;
    private boolean gobackitem = false;
    @org.jetbrains.annotations.Nullable()
    private androidx.recyclerview.widget.RecyclerView listView;
    public androidx.swiperefreshlayout.widget.SwipeRefreshLayout swipeRefreshLayout;
    
    /**
     * flag states whether to open file after service extracts it
     */
    public boolean isOpen = false;
    private com.amaze.filemanager.ui.views.FastScroller fastScroller;
    private com.amaze.filemanager.filesystem.compressed.showcontents.Decompressor decompressor;
    private boolean addheader = true;
    private com.amaze.filemanager.ui.views.DividerItemDecoration dividerItemDecoration;
    private boolean showDividers = false;
    private android.view.View mToolbarContainer;
    private boolean stopAnims = true;
    private int file = 0;
    private int folder = 0;
    private boolean isCachedCompressedFile = false;
    private final com.google.android.material.appbar.AppBarLayout.OnOffsetChangedListener offsetListenerForToolbar = null;
    @org.jetbrains.annotations.NotNull()
    public android.view.ActionMode.Callback mActionModeCallback;
    private final android.content.ServiceConnection mServiceConnection = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.ui.fragments.CompressedExplorerFragment.Companion Companion = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String KEY_PATH = "path";
    private static final java.lang.String KEY_CACHE_FILES = "cache_files";
    private static final java.lang.String KEY_URI = "uri";
    private static final java.lang.String KEY_ELEMENTS = "elements";
    private static final java.lang.String KEY_OPEN = "is_open";
    private static final java.lang.String TAG = null;
    
    public CompressedExplorerFragment() {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.io.File getCompressedFile() {
        return null;
    }
    
    public final void setCompressedFile(@org.jetbrains.annotations.NotNull()
    java.io.File p0) {
    }
    
    private final com.amaze.filemanager.ui.fragments.data.CompressedExplorerFragmentViewModel getViewModel() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getRelativeDirectory() {
        return null;
    }
    
    public final void setRelativeDirectory(@org.jetbrains.annotations.NotNull()
    java.lang.String p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.amaze.filemanager.adapters.CompressedExplorerAdapter getCompressedExplorerAdapter() {
        return null;
    }
    
    public final void setCompressedExplorerAdapter(@org.jetbrains.annotations.Nullable()
    com.amaze.filemanager.adapters.CompressedExplorerAdapter p0) {
    }
    
    public final boolean getGobackitem() {
        return false;
    }
    
    public final void setGobackitem(boolean p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final androidx.recyclerview.widget.RecyclerView getListView() {
        return null;
    }
    
    public final void setListView(@org.jetbrains.annotations.Nullable()
    androidx.recyclerview.widget.RecyclerView p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.swiperefreshlayout.widget.SwipeRefreshLayout getSwipeRefreshLayout() {
        return null;
    }
    
    public final void setSwipeRefreshLayout(@org.jetbrains.annotations.NotNull()
    androidx.swiperefreshlayout.widget.SwipeRefreshLayout p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.view.View onCreateView(@org.jetbrains.annotations.NotNull()
    android.view.LayoutInflater inflater, @org.jetbrains.annotations.Nullable()
    android.view.ViewGroup container, @org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
        return null;
    }
    
    /**
     * Stop animation at archive file list view.
     */
    public final void stopAnim() {
    }
    
    @java.lang.Override()
    public void onViewCreated(@org.jetbrains.annotations.NotNull()
    android.view.View view, @org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
    }
    
    private final java.lang.String prepareCompressedFile(java.lang.String pathArg) {
        return null;
    }
    
    @java.lang.Override()
    public void onSaveInstanceState(@org.jetbrains.annotations.NotNull()
    android.os.Bundle outState) {
    }
    
    private final void onRestoreInstanceState(android.os.Bundle savedInstanceState) {
    }
    
    @java.lang.Override()
    public void onDestroyView() {
    }
    
    @java.lang.Override()
    public void onResume() {
    }
    
    @java.lang.Override()
    public void onPause() {
    }
    
    @java.lang.Override()
    public void changePath(@org.jetbrains.annotations.NotNull()
    java.lang.String path) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getPath() {
        return null;
    }
    
    @java.lang.Override()
    public int getRootDrawable() {
        return 0;
    }
    
    private final void refresh() {
    }
    
    private final void updateBottomBar() {
    }
    
    private final void createViews(java.util.List<? extends com.amaze.filemanager.adapters.data.CompressedObjectParcelable> items, java.lang.String dir) {
    }
    
    /**
     * Indicator whether navigation through back button is possible.
     */
    public final boolean canGoBack() {
        return false;
    }
    
    /**
     * Go one level up in the archive hierarchy.
     */
    public final void goBack() {
    }
    
    private final boolean isRootRelativePath() {
        return false;
    }
    
    private final boolean isRoot(java.lang.String folder) {
        return false;
    }
    
    /**
     * Wrapper of requireActivity() to return [MainActivity].
     *
     * @return [MainActivity]
     */
    @org.jetbrains.annotations.NotNull()
    public final com.amaze.filemanager.ui.activities.MainActivity requireMainActivity() {
        return null;
    }
    
    private final void archiveCorruptOrUnsupportedToast(java.lang.Throwable e) {
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0006\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\n"}, d2 = {"Lcom/amaze/filemanager/ui/fragments/CompressedExplorerFragment$Companion;", "", "()V", "KEY_CACHE_FILES", "", "KEY_ELEMENTS", "KEY_OPEN", "KEY_PATH", "KEY_URI", "TAG", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}