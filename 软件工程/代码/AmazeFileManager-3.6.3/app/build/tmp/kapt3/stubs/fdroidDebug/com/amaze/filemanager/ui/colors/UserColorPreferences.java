package com.amaze.filemanager.ui.colors;

import java.lang.System;

@kotlinx.android.parcel.Parcelize()
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u000b\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0007\u0018\u00002\u00020\u0001B-\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0001\u0010\u0004\u001a\u00020\u0003\u0012\b\b\u0001\u0010\u0005\u001a\u00020\u0003\u0012\b\b\u0001\u0010\u0006\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0007J\t\u0010\r\u001a\u00020\u0003H\u00d6\u0001J\u0019\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0003H\u00d6\u0001R\u0011\u0010\u0005\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\tR\u0011\u0010\u0006\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\tR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\tR\u0011\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\t\u00a8\u0006\u0013"}, d2 = {"Lcom/amaze/filemanager/ui/colors/UserColorPreferences;", "Landroid/os/Parcelable;", "primaryFirstTab", "", "primarySecondTab", "accent", "iconSkin", "(IIII)V", "getAccent", "()I", "getIconSkin", "getPrimaryFirstTab", "getPrimarySecondTab", "describeContents", "writeToParcel", "", "parcel", "Landroid/os/Parcel;", "flags", "app_fdroidDebug"})
public final class UserColorPreferences implements android.os.Parcelable {
    private final int primaryFirstTab = 0;
    private final int primarySecondTab = 0;
    private final int accent = 0;
    private final int iconSkin = 0;
    public static final android.os.Parcelable.Creator<com.amaze.filemanager.ui.colors.UserColorPreferences> CREATOR = null;
    
    public UserColorPreferences(@androidx.annotation.ColorInt()
    int primaryFirstTab, @androidx.annotation.ColorInt()
    int primarySecondTab, @androidx.annotation.ColorInt()
    int accent, @androidx.annotation.ColorInt()
    int iconSkin) {
        super();
    }
    
    public final int getPrimaryFirstTab() {
        return 0;
    }
    
    public final int getPrimarySecondTab() {
        return 0;
    }
    
    public final int getAccent() {
        return 0;
    }
    
    public final int getIconSkin() {
        return 0;
    }
    
    @java.lang.Override()
    public int describeContents() {
        return 0;
    }
    
    @java.lang.Override()
    public void writeToParcel(@org.jetbrains.annotations.NotNull()
    android.os.Parcel parcel, int flags) {
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 3)
    public static final class Creator implements android.os.Parcelable.Creator<com.amaze.filemanager.ui.colors.UserColorPreferences> {
        
        public Creator() {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public final com.amaze.filemanager.ui.colors.UserColorPreferences createFromParcel(@org.jetbrains.annotations.NotNull()
        android.os.Parcel in) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public final com.amaze.filemanager.ui.colors.UserColorPreferences[] newArray(int size) {
            return null;
        }
    }
}