package com.amaze.filemanager.filesystem.ssh;

import java.lang.System;

/**
 * sshj [net.schmizz.sshj.Config] for our own use.
 *
 *
 * Borrowed from original AndroidConfig, but also use vanilla BouncyCastle from the start
 * altogether.
 *
 * @see net.schmizz.sshj.Config
 *
 * @see net.schmizz.sshj.AndroidConfig
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\f\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u0000 \u00032\u00020\u0001:\u0001\u0003B\u0005\u00a2\u0006\u0002\u0010\u0002\u00a8\u0006\u0004"}, d2 = {"Lcom/amaze/filemanager/filesystem/ssh/CustomSshJConfig;", "Lnet/schmizz/sshj/DefaultConfig;", "()V", "Companion", "app_fdroidDebug"})
public final class CustomSshJConfig extends net.schmizz.sshj.DefaultConfig {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.ssh.CustomSshJConfig.Companion Companion = null;
    
    public CustomSshJConfig() {
        super();
    }
    
    /**
     * This is where we different from the original AndroidConfig. Found it only work if we remove
     * BouncyCastle bundled with Android before registering our BouncyCastle provider
     */
    public static final void init() {
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0003\u001a\u00020\u0004H\u0007\u00a8\u0006\u0005"}, d2 = {"Lcom/amaze/filemanager/filesystem/ssh/CustomSshJConfig$Companion;", "", "()V", "init", "", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
        
        /**
         * This is where we different from the original AndroidConfig. Found it only work if we remove
         * BouncyCastle bundled with Android before registering our BouncyCastle provider
         */
        public final void init() {
        }
    }
}