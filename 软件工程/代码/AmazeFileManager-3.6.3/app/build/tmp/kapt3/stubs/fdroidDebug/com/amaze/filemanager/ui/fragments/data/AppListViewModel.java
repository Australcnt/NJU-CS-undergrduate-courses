package com.amaze.filemanager.ui.fragments.data;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u00008\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0010\b\n\u0002\b\u0003\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002R1\u0010\u0003\u001a\u0018\u0012\u0014\u0012\u0012\u0012\u0004\u0012\u00020\u00060\u0005j\b\u0012\u0004\u0012\u00020\u0006`\u00070\u00048FX\u0086\u0084\u0002\u00a2\u0006\f\n\u0004\b\n\u0010\u000b\u001a\u0004\b\b\u0010\tR\u0014\u0010\f\u001a\u00020\rX\u0086D\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\u000eR\u001c\u0010\u000f\u001a\u0004\u0018\u00010\u0010X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0011\u0010\u0012\"\u0004\b\u0013\u0010\u0014R\u0014\u0010\u0015\u001a\u00020\rX\u0086D\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u000eR\u0014\u0010\u0017\u001a\u00020\u0018X\u0086D\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0019\u0010\u001a\u00a8\u0006\u001b"}, d2 = {"Lcom/amaze/filemanager/ui/fragments/data/AppListViewModel;", "Landroidx/lifecycle/ViewModel;", "()V", "appDataParcelable", "Landroidx/lifecycle/MutableLiveData;", "Ljava/util/ArrayList;", "Lcom/amaze/filemanager/adapters/data/AppDataParcelable;", "Lkotlin/collections/ArrayList;", "getAppDataParcelable", "()Landroidx/lifecycle/MutableLiveData;", "appDataParcelable$delegate", "Lkotlin/Lazy;", "isAscending", "", "()Z", "recyclerViewState", "Landroid/os/Parcelable;", "getRecyclerViewState", "()Landroid/os/Parcelable;", "setRecyclerViewState", "(Landroid/os/Parcelable;)V", "showSystemApps", "getShowSystemApps", "sortby", "", "getSortby", "()I", "app_fdroidDebug"})
public final class AppListViewModel extends androidx.lifecycle.ViewModel {
    @org.jetbrains.annotations.Nullable()
    private android.os.Parcelable recyclerViewState;
    private final boolean isAscending = false;
    private final int sortby = 0;
    private final boolean showSystemApps = true;
    @org.jetbrains.annotations.NotNull()
    private final kotlin.Lazy appDataParcelable$delegate = null;
    
    public AppListViewModel() {
        super();
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.os.Parcelable getRecyclerViewState() {
        return null;
    }
    
    public final void setRecyclerViewState(@org.jetbrains.annotations.Nullable()
    android.os.Parcelable p0) {
    }
    
    public final boolean isAscending() {
        return false;
    }
    
    public final int getSortby() {
        return 0;
    }
    
    public final boolean getShowSystemApps() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.lifecycle.MutableLiveData<java.util.ArrayList<com.amaze.filemanager.adapters.data.AppDataParcelable>> getAppDataParcelable() {
        return null;
    }
}