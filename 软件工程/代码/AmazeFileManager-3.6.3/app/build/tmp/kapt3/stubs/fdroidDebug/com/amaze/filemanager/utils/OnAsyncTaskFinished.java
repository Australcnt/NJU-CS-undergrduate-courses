package com.amaze.filemanager.utils;

import java.lang.System;

/**
 * @author Emmanuel on 14/9/2017, at 21:00.
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\bf\u0018\u0000*\u0004\b\u0000\u0010\u00012\u00020\u0002J\u0015\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00028\u0000H&\u00a2\u0006\u0002\u0010\u0006\u00a8\u0006\u0007"}, d2 = {"Lcom/amaze/filemanager/utils/OnAsyncTaskFinished;", "T", "", "onAsyncTaskFinished", "", "data", "(Ljava/lang/Object;)V", "app_fdroidDebug"})
public abstract interface OnAsyncTaskFinished<T extends java.lang.Object> {
    
    @kotlin.Suppress(names = {"UndocumentedPublicFunction"})
    public abstract void onAsyncTaskFinished(T data);
}