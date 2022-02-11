package com.amaze.filemanager.asynchronous.asynctasks;

import java.lang.System;

/**
 * Interface to define state to Asynctask
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\bf\u0018\u0000*\u0004\b\u0000\u0010\u00012\u00020\u0002J\u0015\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00028\u0000H&\u00a2\u0006\u0002\u0010\u0006\u00a8\u0006\u0007"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/StatefulAsyncTask;", "T", "", "setCallback", "", "t", "(Ljava/lang/Object;)V", "app_fdroidDebug"})
public abstract interface StatefulAsyncTask<T extends java.lang.Object> {
    
    /**
     * Set callback to current async task. To be used to attach the context on
     * orientation change of fragment / activity
     * @param t callback
     */
    public abstract void setCallback(T t);
}