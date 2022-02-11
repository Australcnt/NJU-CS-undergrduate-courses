package com.amaze.filemanager.ui.fragments.preference_fragments;

import java.lang.System;

/**
 * @author Emmanuel on 17/4/2017, at 23:17.
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0011\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u0000 \u00132\u00020\u00012\u00020\u0002:\u0001\u0013B\u0005\u00a2\u0006\u0002\u0010\u0003J\u001c\u0010\n\u001a\u00020\u000b2\b\u0010\f\u001a\u0004\u0018\u00010\r2\b\u0010\u000e\u001a\u0004\u0018\u00010\u000fH\u0016J\u0010\u0010\u0010\u001a\u00020\u00062\u0006\u0010\u0011\u001a\u00020\u0012H\u0016R\u0018\u0010\u0004\u001a\n\u0012\u0004\u0012\u00020\u0006\u0018\u00010\u0005X\u0082\u000e\u00a2\u0006\u0004\n\u0002\u0010\u0007R\u0010\u0010\b\u001a\u0004\u0018\u00010\tX\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0014"}, d2 = {"Lcom/amaze/filemanager/ui/fragments/preference_fragments/QuickAccessPref;", "Landroidx/preference/PreferenceFragmentCompat;", "Landroidx/preference/Preference$OnPreferenceClickListener;", "()V", "currentValue", "", "", "[Ljava/lang/Boolean;", "preferences", "Landroid/content/SharedPreferences;", "onCreatePreferences", "", "savedInstanceState", "Landroid/os/Bundle;", "rootKey", "", "onPreferenceClick", "preference", "Landroidx/preference/Preference;", "Companion", "app_fdroidDebug"})
public final class QuickAccessPref extends androidx.preference.PreferenceFragmentCompat implements androidx.preference.Preference.OnPreferenceClickListener {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.ui.fragments.preference_fragments.QuickAccessPref.Companion Companion = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String KEY = "quick access array";
    @org.jetbrains.annotations.NotNull()
    private static final java.lang.String[] KEYS = {"fastaccess", "recent", "image", "video", "audio", "documents", "apks"};
    @org.jetbrains.annotations.NotNull()
    private static final java.lang.Boolean[] DEFAULT = {true, true, true, true, true, true, true};
    private static java.util.Map<java.lang.String, java.lang.Integer> prefPos;
    private android.content.SharedPreferences preferences;
    private java.lang.Boolean[] currentValue;
    
    public QuickAccessPref() {
        super();
    }
    
    @java.lang.Override()
    public void onCreatePreferences(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState, @org.jetbrains.annotations.Nullable()
    java.lang.String rootKey) {
    }
    
    @java.lang.Override()
    public boolean onPreferenceClick(@org.jetbrains.annotations.NotNull()
    androidx.preference.Preference preference) {
        return false;
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0011\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0010$\n\u0002\u0010\b\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u0019\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004\u00a2\u0006\n\n\u0002\u0010\b\u001a\u0004\b\u0006\u0010\u0007R\u000e\u0010\t\u001a\u00020\nX\u0086T\u00a2\u0006\u0002\n\u0000R\u0019\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\n0\u0004\u00a2\u0006\n\n\u0002\u0010\u000e\u001a\u0004\b\f\u0010\rR\u001a\u0010\u000f\u001a\u000e\u0012\u0004\u0012\u00020\n\u0012\u0004\u0012\u00020\u00110\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0012"}, d2 = {"Lcom/amaze/filemanager/ui/fragments/preference_fragments/QuickAccessPref$Companion;", "", "()V", "DEFAULT", "", "", "getDEFAULT", "()[Ljava/lang/Boolean;", "[Ljava/lang/Boolean;", "KEY", "", "KEYS", "getKEYS", "()[Ljava/lang/String;", "[Ljava/lang/String;", "prefPos", "", "", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String[] getKEYS() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.Boolean[] getDEFAULT() {
            return null;
        }
    }
}