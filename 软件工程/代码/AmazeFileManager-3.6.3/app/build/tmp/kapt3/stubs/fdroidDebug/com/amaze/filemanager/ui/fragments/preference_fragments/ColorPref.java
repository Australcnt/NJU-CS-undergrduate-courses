package com.amaze.filemanager.ui.fragments.preference_fragments;

import java.lang.System;

/**
 * This class uses two sections, so that there doesn't need to be two different Fragments. For
 * sections info check switchSections() below.
 *
 *
 * Created by Arpit on 21-06-2015 edited by Emmanuel Messulam <emmanuelbendavid></emmanuelbendavid>@gmail.com>
 */
@kotlin.Suppress(names = {"TooManyFunctions"})
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000h\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\f\u0018\u0000 12\u00020\u00012\u00020\u0002:\u00011B\u0005\u00a2\u0006\u0002\u0010\u0003J\b\u0010\u000e\u001a\u00020\u000fH\u0002J\u0010\u0010\u0010\u001a\u00020\u000f2\u0006\u0010\u0011\u001a\u00020\u0012H\u0002J\b\u0010\u0013\u001a\u00020\u0014H\u0002J\u0012\u0010\u0015\u001a\u00020\u000f2\b\u0010\u0016\u001a\u0004\u0018\u00010\u0017H\u0002J\b\u0010\u0018\u001a\u00020\u000fH\u0002J\b\u0010\u0019\u001a\u00020\u000fH\u0002J\b\u0010\u001a\u001a\u00020\u000fH\u0002J\u0006\u0010\u001b\u001a\u00020\u001cJ\u001c\u0010\u001d\u001a\u00020\u000f2\b\u0010\u001e\u001a\u0004\u0018\u00010\u001f2\b\u0010 \u001a\u0004\u0018\u00010\u0012H\u0016J\u0010\u0010!\u001a\u00020\u000f2\u0006\u0010\"\u001a\u00020#H\u0016J\u0010\u0010$\u001a\u00020\u001c2\u0006\u0010%\u001a\u00020&H\u0016J\b\u0010\'\u001a\u00020\u000fH\u0016J\u0010\u0010(\u001a\u00020\u001c2\u0006\u0010\"\u001a\u00020#H\u0016J\u0010\u0010)\u001a\u00020\u000f2\u0006\u0010*\u001a\u00020\u001fH\u0002J\u0010\u0010+\u001a\u00020\u000f2\u0006\u0010,\u001a\u00020\u001fH\u0016J\u0010\u0010-\u001a\u00020\u000f2\u0006\u0010.\u001a\u00020\u0017H\u0002J\b\u0010/\u001a\u00020\u000fH\u0002J\b\u00100\u001a\u00020\u000fH\u0002R\u0014\u0010\u0004\u001a\u00020\u00058BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0006\u0010\u0007R\u000e\u0010\b\u001a\u00020\tX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\n\u001a\u0004\u0018\u00010\u000bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\f\u001a\u0004\u0018\u00010\rX\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u00062"}, d2 = {"Lcom/amaze/filemanager/ui/fragments/preference_fragments/ColorPref;", "Landroidx/preference/PreferenceFragmentCompat;", "Landroidx/preference/Preference$OnPreferenceClickListener;", "()V", "activity", "Lcom/amaze/filemanager/ui/activities/PreferencesActivity;", "getActivity", "()Lcom/amaze/filemanager/ui/activities/PreferencesActivity;", "currentSection", "", "dialog", "Lcom/afollestad/materialdialogs/MaterialDialog;", "sharedPref", "Landroid/content/SharedPreferences;", "checkCustomization", "", "colorChangeDialog", "colorPrefKey", "", "createColorPickerDialogListener", "Lcom/amaze/filemanager/ui/dialogs/ColorPickerDialog$OnAcceptedConfig;", "invalidateColorPreference", "selectedColors", "Lcom/amaze/filemanager/ui/views/preference/SelectedColorsPreference;", "invalidateEverything", "loadSection0", "loadSection1", "onBackPressed", "", "onCreatePreferences", "savedInstanceState", "Landroid/os/Bundle;", "rootKey", "onDisplayPreferenceDialog", "preference", "Landroidx/preference/Preference;", "onOptionsItemSelected", "item", "Landroid/view/MenuItem;", "onPause", "onPreferenceClick", "onRestoreInstanceState", "inState", "onSaveInstanceState", "outState", "openSelectColorDialog", "pref", "reloadListeners", "switchSections", "Companion", "app_fdroidDebug"})
public final class ColorPref extends androidx.preference.PreferenceFragmentCompat implements androidx.preference.Preference.OnPreferenceClickListener {
    private int currentSection = 0;
    private com.afollestad.materialdialogs.MaterialDialog dialog;
    private android.content.SharedPreferences sharedPref;
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.ui.fragments.preference_fragments.ColorPref.Companion Companion = null;
    private static final int SECTION_0 = 0;
    private static final int SECTION_1 = 1;
    private static final java.lang.String KEY_PRESELECTED_CONFIGS = "preselectedconfigs";
    private static final java.lang.String KEY_COLOREDNAV = "colorednavigation";
    private static final java.lang.String KEY_SELECT_COLOR_CONFIG = "selectcolorconfig";
    private static final java.lang.String[] PREFERENCE_KEYS_SECTION_0 = {"colorednavigation", "selectcolorconfig"};
    private static final java.lang.String[] PREFERENCE_KEYS_SECTION_1 = {"preselectedconfigs", "skin", "skin_two", "accent_skin", "icon_skin"};
    private static final java.lang.String KEY_SECTION = "section";
    private static final java.lang.String KEY_CUSTOMIZE = "category";
    
    public ColorPref() {
        super();
    }
    
    private final com.amaze.filemanager.ui.activities.PreferencesActivity getActivity() {
        return null;
    }
    
    @java.lang.Override()
    public void onCreatePreferences(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState, @org.jetbrains.annotations.Nullable()
    java.lang.String rootKey) {
    }
    
    @java.lang.Override()
    public void onPause() {
    }
    
    /**
     * Deal with the "up" button going to last fragment, instead of section 0.
     */
    @java.lang.Override()
    public boolean onOptionsItemSelected(@org.jetbrains.annotations.NotNull()
    android.view.MenuItem item) {
        return false;
    }
    
    /**
     * Handle back button behaviour, returns to first section of colour preferences as necessary
     */
    public final boolean onBackPressed() {
        return false;
    }
    
    @java.lang.Override()
    public boolean onPreferenceClick(@org.jetbrains.annotations.NotNull()
    androidx.preference.Preference preference) {
        return false;
    }
    
    @java.lang.Override()
    public void onDisplayPreferenceDialog(@org.jetbrains.annotations.NotNull()
    androidx.preference.Preference preference) {
    }
    
    private final void colorChangeDialog(java.lang.String colorPrefKey) {
    }
    
    private final void switchSections() {
    }
    
    private final void loadSection0() {
    }
    
    private final void loadSection1() {
    }
    
    private final void openSelectColorDialog(com.amaze.filemanager.ui.views.preference.SelectedColorsPreference pref) {
    }
    
    private final com.amaze.filemanager.ui.dialogs.ColorPickerDialog.OnAcceptedConfig createColorPickerDialogListener() {
        return null;
    }
    
    private final void checkCustomization() {
    }
    
    private final void reloadListeners() {
    }
    
    private final void invalidateEverything() {
    }
    
    private final void invalidateColorPreference(com.amaze.filemanager.ui.views.preference.SelectedColorsPreference selectedColors) {
    }
    
    @java.lang.Override()
    public void onSaveInstanceState(@org.jetbrains.annotations.NotNull()
    android.os.Bundle outState) {
    }
    
    private final void onRestoreInstanceState(android.os.Bundle inState) {
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0010\u0011\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u0016\u0010\t\u001a\b\u0012\u0004\u0012\u00020\u00040\nX\u0082\u0004\u00a2\u0006\u0004\n\u0002\u0010\u000bR\u0016\u0010\f\u001a\b\u0012\u0004\u0012\u00020\u00040\nX\u0082\u0004\u00a2\u0006\u0004\n\u0002\u0010\u000bR\u000e\u0010\r\u001a\u00020\u000eX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u000eX\u0082T\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0010"}, d2 = {"Lcom/amaze/filemanager/ui/fragments/preference_fragments/ColorPref$Companion;", "", "()V", "KEY_COLOREDNAV", "", "KEY_CUSTOMIZE", "KEY_PRESELECTED_CONFIGS", "KEY_SECTION", "KEY_SELECT_COLOR_CONFIG", "PREFERENCE_KEYS_SECTION_0", "", "[Ljava/lang/String;", "PREFERENCE_KEYS_SECTION_1", "SECTION_0", "", "SECTION_1", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}