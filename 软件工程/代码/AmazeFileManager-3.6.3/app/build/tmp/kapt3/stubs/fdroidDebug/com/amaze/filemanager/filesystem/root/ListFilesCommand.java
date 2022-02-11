package com.amaze.filemanager.filesystem.root;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000H\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\b\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J2\u0010\u0005\u001a\u0014\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00040\u0007\u0012\u0004\u0012\u00020\b0\u00062\u0006\u0010\t\u001a\u00020\u00042\u0006\u0010\n\u001a\u00020\b2\b\b\u0002\u0010\u000b\u001a\u00020\bJ<\u0010\f\u001a\u0012\u0012\u0004\u0012\u00020\u000e0\rj\b\u0012\u0004\u0012\u00020\u000e`\u000f2\u0006\u0010\t\u001a\u00020\u00042\u0006\u0010\n\u001a\u00020\b2\u0012\u0010\u0010\u001a\u000e\u0012\u0004\u0012\u00020\u000e\u0012\u0004\u0012\u00020\u00120\u0011H\u0002J\u0010\u0010\u0013\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\u000eH\u0002Jd\u0010\u0014\u001a\u00020\u00122\u0006\u0010\t\u001a\u00020\u00042\u0006\u0010\u0015\u001a\u00020\b2\u0006\u0010\n\u001a\u00020\b2!\u0010\u0016\u001a\u001d\u0012\u0013\u0012\u00110\u0017\u00a2\u0006\f\b\u0018\u0012\b\b\u0019\u0012\u0004\b\b(\u001a\u0012\u0004\u0012\u00020\u00120\u00112!\u0010\u001b\u001a\u001d\u0012\u0013\u0012\u00110\u000e\u00a2\u0006\f\b\u0018\u0012\b\b\u0019\u0012\u0004\b\b(\u001c\u0012\u0004\u0012\u00020\u00120\u0011J\"\u0010\u001d\u001a\u0004\u0018\u00010\u000e2\u0006\u0010\u001e\u001a\u00020\u00042\u0006\u0010\t\u001a\u00020\u00042\u0006\u0010\u001f\u001a\u00020\bH\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006 "}, d2 = {"Lcom/amaze/filemanager/filesystem/root/ListFilesCommand;", "Lcom/amaze/filemanager/filesystem/root/base/IRootCommand;", "()V", "TAG", "", "executeRootCommand", "Lkotlin/Pair;", "", "", "path", "showHidden", "retryWithLs", "getFilesList", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/filesystem/HybridFileParcelable;", "Lkotlin/collections/ArrayList;", "listener", "Lkotlin/Function1;", "", "isDirectory", "listFiles", "root", "openModeCallback", "Lcom/amaze/filemanager/file_operations/filesystem/OpenMode;", "Lkotlin/ParameterName;", "name", "openMode", "onFileFoundCallback", "file", "parseStringForHybridFile", "rawFile", "isStat", "app_fdroidDebug"})
public final class ListFilesCommand extends com.amaze.filemanager.filesystem.root.base.IRootCommand {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.root.ListFilesCommand INSTANCE = null;
    private static final java.lang.String TAG = null;
    
    private ListFilesCommand() {
        super();
    }
    
    /**
     * list files in given directory and invoke callback
     */
    public final void listFiles(@org.jetbrains.annotations.NotNull()
    java.lang.String path, boolean root, boolean showHidden, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super com.amaze.filemanager.file_operations.filesystem.OpenMode, kotlin.Unit> openModeCallback, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super com.amaze.filemanager.filesystem.HybridFileParcelable, kotlin.Unit> onFileFoundCallback) {
    }
    
    /**
     * executes list files root command directory and return each line item
     * returns pair with first denoting the result array and second if run with ls (true) or stat (false)
     */
    @org.jetbrains.annotations.NotNull()
    public final kotlin.Pair<java.util.List<java.lang.String>, java.lang.Boolean> executeRootCommand(@org.jetbrains.annotations.NotNull()
    java.lang.String path, boolean showHidden, boolean retryWithLs) {
        return null;
    }
    
    private final boolean isDirectory(com.amaze.filemanager.filesystem.HybridFileParcelable path) {
        return false;
    }
    
    /**
     * Loads files in a path using basic filesystem callbacks
     *
     * @param path the path
     */
    private final java.util.ArrayList<com.amaze.filemanager.filesystem.HybridFileParcelable> getFilesList(java.lang.String path, boolean showHidden, kotlin.jvm.functions.Function1<? super com.amaze.filemanager.filesystem.HybridFileParcelable, kotlin.Unit> listener) {
        return null;
    }
    
    /**
     * Parses listing command result for HybridFile
     */
    private final com.amaze.filemanager.filesystem.HybridFileParcelable parseStringForHybridFile(java.lang.String rawFile, java.lang.String path, boolean isStat) {
        return null;
    }
}