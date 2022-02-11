package com.amaze.filemanager.utils;

import java.lang.System;

/**
 * This allows the caller of a function to know when a file has ben found and deal with it ASAP
 *
 * @author Emmanuel on 21/9/2017, at 15:23.
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&\u00a8\u0006\u0006"}, d2 = {"Lcom/amaze/filemanager/utils/OnFileFound;", "", "onFileFound", "", "file", "Lcom/amaze/filemanager/filesystem/HybridFileParcelable;", "app_fdroidDebug"})
public abstract interface OnFileFound {
    
    @kotlin.Suppress(names = {"UndocumentedPublicFunction"})
    public abstract void onFileFound(@org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.filesystem.HybridFileParcelable file);
}