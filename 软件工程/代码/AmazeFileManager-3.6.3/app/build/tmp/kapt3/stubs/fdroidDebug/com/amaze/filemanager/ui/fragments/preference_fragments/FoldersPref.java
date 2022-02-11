package com.amaze.filemanager.ui.fragments.preference_fragments;

import java.lang.System;

/**
 * @author Emmanuel on 17/4/2017, at 22:49.
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000p\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010%\n\u0002\u0018\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\u0018\u00002\u00020\u00012\u00020\u0002B\u0005\u00a2\u0006\u0002\u0010\u0003J\u0018\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u001a2\u0006\u0010\u001b\u001a\u00020\u001cH\u0002J\u0018\u0010\u001d\u001a\u00020\u00182\u0006\u0010\u001e\u001a\u00020\u001a2\u0006\u0010\u001b\u001a\u00020\u001cH\u0002J\b\u0010\u001f\u001a\u00020\u0018H\u0002J\u0010\u0010 \u001a\u00020\u00182\u0006\u0010!\u001a\u00020\"H\u0002J\u0010\u0010#\u001a\u00020\u00182\u0006\u0010!\u001a\u00020\"H\u0002J\u001c\u0010$\u001a\u00020\u00182\b\u0010%\u001a\u0004\u0018\u00010&2\b\u0010\'\u001a\u0004\u0018\u00010(H\u0016J\u0010\u0010)\u001a\u00020*2\u0006\u0010+\u001a\u00020\u0011H\u0016J\b\u0010,\u001a\u00020\u0018H\u0016R\u0010\u0010\u0004\u001a\u0004\u0018\u00010\u0005X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0006\u001a\u0004\u0018\u00010\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\b\u001a\u00020\u00058BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\t\u0010\nR\u0014\u0010\u000b\u001a\u00020\f8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\r\u0010\u000eR\u001a\u0010\u000f\u001a\u000e\u0012\u0004\u0012\u00020\u0011\u0012\u0004\u0012\u00020\u00120\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0013\u001a\u0004\u0018\u00010\u0014X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0015\u001a\u0004\u0018\u00010\u0016X\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u0006-"}, d2 = {"Lcom/amaze/filemanager/ui/fragments/preference_fragments/FoldersPref;", "Landroidx/preference/PreferenceFragmentCompat;", "Landroidx/preference/Preference$OnPreferenceClickListener;", "()V", "_dialogBinding", "Lcom/amaze/filemanager/databinding/DialogTwoedittextsBinding;", "dataUtils", "Lcom/amaze/filemanager/utils/DataUtils;", "dialogBinding", "getDialogBinding", "()Lcom/amaze/filemanager/databinding/DialogTwoedittextsBinding;", "mainActivity", "Lcom/amaze/filemanager/ui/activities/superclasses/ThemedActivity;", "getMainActivity", "()Lcom/amaze/filemanager/ui/activities/superclasses/ThemedActivity;", "position", "", "Landroidx/preference/Preference;", "", "sharedPrefs", "Landroid/content/SharedPreferences;", "utilsHandler", "Lcom/amaze/filemanager/database/UtilsHandler;", "disableButtonIfNotPath", "", "path", "Landroid/widget/EditText;", "dialog", "Lcom/afollestad/materialdialogs/MaterialDialog;", "disableButtonIfTitleEmpty", "title", "loadCreateDialog", "loadDeleteDialog", "p", "Lcom/amaze/filemanager/ui/views/preference/PathSwitchPreference;", "loadEditDialog", "onCreatePreferences", "savedInstanceState", "Landroid/os/Bundle;", "rootKey", "", "onPreferenceClick", "", "preference", "onResume", "app_fdroidDebug"})
public final class FoldersPref extends androidx.preference.PreferenceFragmentCompat implements androidx.preference.Preference.OnPreferenceClickListener {
    private android.content.SharedPreferences sharedPrefs;
    private final java.util.Map<androidx.preference.Preference, java.lang.Integer> position = null;
    private com.amaze.filemanager.utils.DataUtils dataUtils;
    private com.amaze.filemanager.database.UtilsHandler utilsHandler;
    private com.amaze.filemanager.databinding.DialogTwoedittextsBinding _dialogBinding;
    
    public FoldersPref() {
        super();
    }
    
    private final com.amaze.filemanager.ui.activities.superclasses.ThemedActivity getMainActivity() {
        return null;
    }
    
    private final com.amaze.filemanager.databinding.DialogTwoedittextsBinding getDialogBinding() {
        return null;
    }
    
    @java.lang.Override()
    public void onCreatePreferences(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState, @org.jetbrains.annotations.Nullable()
    java.lang.String rootKey) {
    }
    
    @java.lang.Override()
    public void onResume() {
    }
    
    @java.lang.Override()
    public boolean onPreferenceClick(@org.jetbrains.annotations.NotNull()
    androidx.preference.Preference preference) {
        return false;
    }
    
    private final void loadCreateDialog() {
    }
    
    private final void loadEditDialog(com.amaze.filemanager.ui.views.preference.PathSwitchPreference p) {
    }
    
    private final void loadDeleteDialog(com.amaze.filemanager.ui.views.preference.PathSwitchPreference p) {
    }
    
    private final void disableButtonIfNotPath(android.widget.EditText path, com.afollestad.materialdialogs.MaterialDialog dialog) {
    }
    
    private final void disableButtonIfTitleEmpty(android.widget.EditText title, com.afollestad.materialdialogs.MaterialDialog dialog) {
    }
}