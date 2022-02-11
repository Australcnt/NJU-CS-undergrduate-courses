package com.amaze.filemanager.utils;

import java.lang.System;

/**
 * General inteface for updating data before it's finished loading
 *
 * @author Emmanuel on 13/5/2017, at 22:45.
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\bf\u0018\u0000*\u0004\b\u0000\u0010\u00012\u00020\u0002J\u0015\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00028\u0000H&\u00a2\u0006\u0002\u0010\u0006\u00a8\u0006\u0007"}, d2 = {"Lcom/amaze/filemanager/utils/OnProgressUpdate;", "T", "", "onUpdate", "", "data", "(Ljava/lang/Object;)V", "app_fdroidDebug"})
public abstract interface OnProgressUpdate<T extends java.lang.Object> {
    
    @kotlin.Suppress(names = {"UndocumentedPublicFunction"})
    public abstract void onUpdate(T data);
}