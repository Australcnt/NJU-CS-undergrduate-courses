package com.amaze.filemanager.test;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0002\b\u0007\u0018\u0000 \f2\u00020\u0001:\u0001\fB\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0007J\u0013\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\u00060\bH\u0007\u00a2\u0006\u0002\u0010\tJ\u0010\u0010\n\u001a\u00020\u000b2\u0006\u0010\u0005\u001a\u00020\u0006H\u0007\u00a8\u0006\r"}, d2 = {"Lcom/amaze/filemanager/test/ShadowTabHandler;", "", "()V", "addTab", "Lio/reactivex/Completable;", "tab", "Lcom/amaze/filemanager/database/models/explorer/Tab;", "getAllTabs", "", "()[Lcom/amaze/filemanager/database/models/explorer/Tab;", "update", "", "Companion", "app_fdroidDebug"})
@org.robolectric.annotation.Implements(value = com.amaze.filemanager.database.TabHandler.class)
public final class ShadowTabHandler {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.test.ShadowTabHandler.Companion Companion = null;
    
    public ShadowTabHandler() {
        super();
    }
    
    /**
     * Implements [TabHandler.getInstance]
     */
    @org.jetbrains.annotations.NotNull()
    @org.robolectric.annotation.Implementation()
    public static final com.amaze.filemanager.database.TabHandler getInstance() {
        return null;
    }
    
    /**
     * Implements [TabHandler.addTab]
     */
    @org.jetbrains.annotations.NotNull()
    @org.robolectric.annotation.Implementation()
    public final io.reactivex.Completable addTab(@org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.database.models.explorer.Tab tab) {
        return null;
    }
    
    /**
     * Implements [TabHandler.update]
     */
    @org.robolectric.annotation.Implementation()
    public final void update(@org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.database.models.explorer.Tab tab) {
    }
    
    /**
     * For places where Activity is launched, but we are not actually looking at the Tabs loaded.
     *
     * @see TabHandler.getAllTabs
     */
    @org.jetbrains.annotations.NotNull()
    @org.robolectric.annotation.Implementation()
    public final com.amaze.filemanager.database.models.explorer.Tab[] getAllTabs() {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0003\u001a\u00020\u0004H\u0007\u00a8\u0006\u0005"}, d2 = {"Lcom/amaze/filemanager/test/ShadowTabHandler$Companion;", "", "()V", "getInstance", "Lcom/amaze/filemanager/database/TabHandler;", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
        
        /**
         * Implements [TabHandler.getInstance]
         */
        @org.jetbrains.annotations.NotNull()
        @org.robolectric.annotation.Implementation()
        public final com.amaze.filemanager.database.TabHandler getInstance() {
            return null;
        }
    }
}