package com.amaze.filemanager.adapters.data;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u000b\u0018\u0000 \u00102\n\u0012\u0006\u0012\u0004\u0018\u00010\u00020\u0001:\u0001\u0010B\u0015\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\u001c\u0010\r\u001a\u00020\u00042\b\u0010\u000e\u001a\u0004\u0018\u00010\u00022\b\u0010\u000f\u001a\u0004\u0018\u00010\u0002H\u0016R\u000e\u0010\b\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0003\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\t\u0010\n\"\u0004\b\u000b\u0010\f\u00a8\u0006\u0011"}, d2 = {"Lcom/amaze/filemanager/adapters/data/AppDataSorter;", "Ljava/util/Comparator;", "Lcom/amaze/filemanager/adapters/data/AppDataParcelable;", "sort", "", "isAscending", "", "(IZ)V", "asc", "getSort", "()I", "setSort", "(I)V", "compare", "file1", "file2", "Companion", "app_fdroidDebug"})
public final class AppDataSorter implements java.util.Comparator<com.amaze.filemanager.adapters.data.AppDataParcelable> {
    private int sort;
    private final int asc = 0;
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.adapters.data.AppDataSorter.Companion Companion = null;
    public static final int SORT_NAME = 0;
    public static final int SORT_MODIF = 1;
    public static final int SORT_SIZE = 2;
    
    public AppDataSorter(int sort, boolean isAscending) {
        super();
    }
    
    public final int getSort() {
        return 0;
    }
    
    public final void setSort(int p0) {
    }
    
    /**
     * Compares two elements and return negative, zero and positive integer if first argument is
     * less than, equal to or greater than second
     */
    @java.lang.Override()
    public int compare(@org.jetbrains.annotations.Nullable()
    com.amaze.filemanager.adapters.data.AppDataParcelable file1, @org.jetbrains.annotations.Nullable()
    com.amaze.filemanager.adapters.data.AppDataParcelable file2) {
        return 0;
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0007"}, d2 = {"Lcom/amaze/filemanager/adapters/data/AppDataSorter$Companion;", "", "()V", "SORT_MODIF", "", "SORT_NAME", "SORT_SIZE", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}