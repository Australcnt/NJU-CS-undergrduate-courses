package com.amaze.filemanager.ui;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 2, d1 = {"\u0000&\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\u001a\n\u0010\u0002\u001a\u00020\u0003*\u00020\u0004\u001a\u0012\u0010\u0005\u001a\u00020\u0003*\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b\u001a\u0012\u0010\t\u001a\u00020\u0003*\u00020\b2\u0006\u0010\n\u001a\u00020\u000b\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\u00a8\u0006\f"}, d2 = {"TAG", "", "makeRequired", "", "Lcom/google/android/material/textfield/TextInputLayout;", "openKeyboard", "Landroid/widget/EditText;", "context", "Landroid/content/Context;", "startActivityCatchingSecurityException", "intent", "Landroid/content/Intent;", "app_fdroidDebug"})
public final class ExtensionsKt {
    private static final java.lang.String TAG = "ExtensionsKt";
    
    /**
     * Marks a text input field as mandatory (appends * at end)
     */
    public static final void makeRequired(@org.jetbrains.annotations.NotNull()
    com.google.android.material.textfield.TextInputLayout $this$makeRequired) {
    }
    
    /**
     * Makes the [Activity] starting not crash in case the app is
     * not meant to deal with this kind of intent
     */
    public static final void startActivityCatchingSecurityException(@org.jetbrains.annotations.NotNull()
    android.content.Context $this$startActivityCatchingSecurityException, @org.jetbrains.annotations.NotNull()
    android.content.Intent intent) {
    }
    
    /**
     * Force keyboard pop up on focus
     */
    public static final void openKeyboard(@org.jetbrains.annotations.NotNull()
    android.widget.EditText $this$openKeyboard, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
    }
}