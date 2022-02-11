package com.amaze.filemanager.utils;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\r\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0004\u0018\u00002\u00020\u0001B\u000f\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004B\u0015\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\bJ>\u0010\t\u001a\u0004\u0018\u00010\n2\b\u0010\u000b\u001a\u0004\u0018\u00010\n2\u0006\u0010\f\u001a\u00020\u00062\u0006\u0010\r\u001a\u00020\u00062\b\u0010\u000e\u001a\u0004\u0018\u00010\u000f2\u0006\u0010\u0010\u001a\u00020\u00062\u0006\u0010\u0011\u001a\u00020\u0006H\u0016J \u0010\u0012\u001a\u00020\u00132\u0006\u0010\u0014\u001a\u00020\u00062\u0006\u0010\u0015\u001a\u00020\u00062\u0006\u0010\u0016\u001a\u00020\u0006H\u0002R\u000e\u0010\u0007\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0017"}, d2 = {"Lcom/amaze/filemanager/utils/MinMaxInputFilter;", "Landroid/text/InputFilter;", "range", "Lkotlin/ranges/IntRange;", "(Lkotlin/ranges/IntRange;)V", "min", "", "max", "(II)V", "filter", "", "source", "start", "end", "dest", "Landroid/text/Spanned;", "dstart", "dend", "isInRange", "", "minValue", "maxValue", "input", "app_fdroidDebug"})
public final class MinMaxInputFilter implements android.text.InputFilter {
    private final int min = 0;
    private final int max = 0;
    
    public MinMaxInputFilter(int min, int max) {
        super();
    }
    
    public MinMaxInputFilter(@org.jetbrains.annotations.NotNull()
    kotlin.ranges.IntRange range) {
        super();
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.CharSequence filter(@org.jetbrains.annotations.Nullable()
    java.lang.CharSequence source, int start, int end, @org.jetbrains.annotations.Nullable()
    android.text.Spanned dest, int dstart, int dend) {
        return null;
    }
    
    private final boolean isInRange(int minValue, int maxValue, int input) {
        return false;
    }
}