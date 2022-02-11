package com.amaze.filemanager.utils;

import java.lang.System;

/**
 * Extract from: https://github.com/kcochibili/TinyDB--Android-Shared-Preferences-Turbo Author:
 * https://github.com/kcochibili
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0002\b\u0003\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J7\u0010\u0005\u001a\n\u0012\u0004\u0012\u00020\u0007\u0018\u00010\u00062\u0006\u0010\b\u001a\u00020\t2\b\u0010\n\u001a\u0004\u0018\u00010\u00042\u000e\u0010\u000b\u001a\n\u0012\u0004\u0012\u00020\u0007\u0018\u00010\u0006H\u0007\u00a2\u0006\u0002\u0010\fJ-\u0010\r\u001a\u00020\u000e2\u0006\u0010\b\u001a\u00020\t2\b\u0010\n\u001a\u0004\u0018\u00010\u00042\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006H\u0007\u00a2\u0006\u0002\u0010\u0010R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0011"}, d2 = {"Lcom/amaze/filemanager/utils/TinyDB;", "", "()V", "DIVIDER", "", "getBooleanArray", "", "", "preferences", "Landroid/content/SharedPreferences;", "key", "defaultValue", "(Landroid/content/SharedPreferences;Ljava/lang/String;[Ljava/lang/Boolean;)[Ljava/lang/Boolean;", "putBooleanArray", "", "array", "(Landroid/content/SharedPreferences;Ljava/lang/String;[Ljava/lang/Boolean;)V", "app_fdroidDebug"})
public final class TinyDB {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.utils.TinyDB INSTANCE = null;
    private static final java.lang.String DIVIDER = "\u201a\u2017\u201a";
    
    private TinyDB() {
        super();
    }
    
    /**
     * Put array of Boolean into SharedPreferences with 'key' and save
     *
     * @param key SharedPreferences key
     * @param array array of Booleans to be added
     */
    public static final void putBooleanArray(@org.jetbrains.annotations.NotNull()
    android.content.SharedPreferences preferences, @org.jetbrains.annotations.Nullable()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    java.lang.Boolean[] array) {
    }
    
    /**
     * Get parsed array of Booleans from SharedPreferences at 'key'
     *
     * @param key SharedPreferences key
     * @return Array of Booleans
     */
    @org.jetbrains.annotations.Nullable()
    public static final java.lang.Boolean[] getBooleanArray(@org.jetbrains.annotations.NotNull()
    android.content.SharedPreferences preferences, @org.jetbrains.annotations.Nullable()
    java.lang.String key, @org.jetbrains.annotations.Nullable()
    java.lang.Boolean[] defaultValue) {
        return null;
    }
}