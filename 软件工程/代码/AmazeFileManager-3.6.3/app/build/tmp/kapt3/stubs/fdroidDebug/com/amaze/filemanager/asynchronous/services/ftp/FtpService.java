package com.amaze.filemanager.asynchronous.services.ftp;

import java.lang.System;

/**
 * Created by yashwanthreddyg on 09-06-2016.
 *
 *
 * Edited by zent-co on 30-07-2019 Edited by bowiechen on 2019-10-19.
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000:\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\b\u0018\u0000 \u00182\u00020\u00012\u00020\u0002:\u0002\u0018\u0019B\u0005\u00a2\u0006\u0002\u0010\u0003J\u0010\u0010\f\u001a\u00020\u00052\u0006\u0010\r\u001a\u00020\u000eH\u0016J\b\u0010\u000f\u001a\u00020\u0010H\u0016J \u0010\u0011\u001a\u00020\u00122\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u0013\u001a\u00020\u00122\u0006\u0010\u0014\u001a\u00020\u0012H\u0016J\u0010\u0010\u0015\u001a\u00020\u00102\u0006\u0010\u0016\u001a\u00020\u000eH\u0016J\b\u0010\u0017\u001a\u00020\u0010H\u0016R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\t\u001a\u0004\u0018\u00010\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000b\u001a\u0004\u0018\u00010\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u001a"}, d2 = {"Lcom/amaze/filemanager/asynchronous/services/ftp/FtpService;", "Landroid/app/Service;", "Ljava/lang/Runnable;", "()V", "binder", "Landroid/os/IBinder;", "isPasswordProtected", "", "isStartedByTile", "password", "", "username", "onBind", "intent", "Landroid/content/Intent;", "onDestroy", "", "onStartCommand", "", "flags", "startId", "onTaskRemoved", "rootIntent", "run", "Companion", "FtpReceiverActions", "app_fdroidDebug"})
public final class FtpService extends android.app.Service implements java.lang.Runnable {
    private final android.os.IBinder binder = null;
    private java.lang.String username;
    private java.lang.String password;
    private boolean isPasswordProtected = false;
    private boolean isStartedByTile = false;
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.asynchronous.services.ftp.FtpService.Companion Companion = null;
    public static final int DEFAULT_PORT = 2211;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String DEFAULT_USERNAME = "";
    public static final int DEFAULT_TIMEOUT = 600;
    public static final boolean DEFAULT_SECURE = true;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PORT_PREFERENCE_KEY = "ftpPort";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String KEY_PREFERENCE_PATH = "ftp_path";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String KEY_PREFERENCE_USERNAME = "ftp_username";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String KEY_PREFERENCE_PASSWORD = "ftp_password_encrypted";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String KEY_PREFERENCE_TIMEOUT = "ftp_timeout";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String KEY_PREFERENCE_SECURE = "ftp_secure";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String KEY_PREFERENCE_READONLY = "ftp_readonly";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String KEY_PREFERENCE_SAF_FILESYSTEM = "ftp_saf_filesystem";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String INITIALS_HOST_FTP = "ftp://";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String INITIALS_HOST_SFTP = "ftps://";
    private static final java.lang.String WIFI_AP_ADDRESS_PREFIX = "192.168.43.";
    private static final char[] KEYSTORE_PASSWORD = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ACTION_START_FTPSERVER = "com.amaze.filemanager.services.ftpservice.FTPReceiver.ACTION_START_FTPSERVER";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ACTION_STOP_FTPSERVER = "com.amaze.filemanager.services.ftpservice.FTPReceiver.ACTION_STOP_FTPSERVER";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String TAG_STARTED_BY_TILE = "started_by_tile";
    private static java.lang.Thread serverThread;
    private static org.apache.ftpserver.FtpServer server;
    
    public FtpService() {
        super();
    }
    
    @java.lang.Override()
    public int onStartCommand(@org.jetbrains.annotations.NotNull()
    android.content.Intent intent, int flags, int startId) {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.os.IBinder onBind(@org.jetbrains.annotations.NotNull()
    android.content.Intent intent) {
        return null;
    }
    
    @kotlin.Suppress(names = {"LongMethod"})
    @java.lang.Override()
    public void run() {
    }
    
    @java.lang.Override()
    public void onDestroy() {
    }
    
    @java.lang.Override()
    public void onTaskRemoved(@org.jetbrains.annotations.NotNull()
    android.content.Intent rootIntent) {
    }
    
    /**
     * Derive the FTP server's default share path, depending the user's Android version.
     *
     * Default it's the internal storage's root as java.io.File; otherwise it's content://
     * based URI if it's running on Android 7.0 or above.
     */
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String defaultPath(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return null;
    }
    
    /**
     * Indicator whether FTP service is running
     */
    public static final boolean isRunning() {
        return false;
    }
    
    /**
     * Is the device connected to local network, either Ethernet or Wifi?
     */
    public static final boolean isConnectedToLocalNetwork(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return false;
    }
    
    /**
     * Is the device connected to Wifi?
     */
    public static final boolean isConnectedToWifi(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return false;
    }
    
    /**
     * Is the device's wifi hotspot enabled?
     */
    public static final boolean isEnabledWifiHotspot(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return false;
    }
    
    /**
     * Determine device's IP address
     */
    @org.jetbrains.annotations.Nullable()
    public static final java.net.InetAddress getLocalInetAddress(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\f\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0002\b\u0006\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002j\u0002\b\u0003j\u0002\b\u0004j\u0002\b\u0005j\u0002\b\u0006\u00a8\u0006\u0007"}, d2 = {"Lcom/amaze/filemanager/asynchronous/services/ftp/FtpService$FtpReceiverActions;", "", "(Ljava/lang/String;I)V", "STARTED", "STARTED_FROM_TILE", "STOPPED", "FAILED_TO_START", "app_fdroidDebug"})
    public static enum FtpReceiverActions {
        /*public static final*/ STARTED /* = new STARTED() */,
        /*public static final*/ STARTED_FROM_TILE /* = new STARTED_FROM_TILE() */,
        /*public static final*/ STOPPED /* = new STOPPED() */,
        /*public static final*/ FAILED_TO_START /* = new FAILED_TO_START() */;
        
        FtpReceiverActions() {
        }
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\\\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0010\u0019\n\u0002\b\u000b\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0005\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0006\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\u001e\u001a\u00020\u001f2\u0006\u0010 \u001a\u00020\u00072\u0006\u0010!\u001a\u00020\u0007H\u0002J\u0010\u0010\"\u001a\u00020\t2\u0006\u0010#\u001a\u00020$H\u0002J\u0010\u0010%\u001a\u00020\u00042\u0006\u0010&\u001a\u00020\'H\u0007J\u0012\u0010(\u001a\u0004\u0018\u00010)2\u0006\u0010&\u001a\u00020\'H\u0007J\u0010\u0010*\u001a\u00020\u00072\u0006\u0010+\u001a\u00020,H\u0002J\u0012\u0010-\u001a\u0004\u0018\u00010)2\u0006\u0010 \u001a\u00020\u0007H\u0002J\u0010\u0010.\u001a\u00020\t2\u0006\u0010&\u001a\u00020\'H\u0007J\u0010\u0010/\u001a\u00020\t2\u0006\u0010&\u001a\u00020\'H\u0007J\u0010\u00100\u001a\u00020\t2\u0006\u0010&\u001a\u00020\'H\u0007J\b\u00101\u001a\u00020\tH\u0007R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u0007X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0017\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0019\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u001a\u001a\u0004\u0018\u00010\u001bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u001c\u001a\u0004\u0018\u00010\u001dX\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u00062"}, d2 = {"Lcom/amaze/filemanager/asynchronous/services/ftp/FtpService$Companion;", "", "()V", "ACTION_START_FTPSERVER", "", "ACTION_STOP_FTPSERVER", "DEFAULT_PORT", "", "DEFAULT_SECURE", "", "DEFAULT_TIMEOUT", "DEFAULT_USERNAME", "INITIALS_HOST_FTP", "INITIALS_HOST_SFTP", "KEYSTORE_PASSWORD", "", "KEY_PREFERENCE_PASSWORD", "KEY_PREFERENCE_PATH", "KEY_PREFERENCE_READONLY", "KEY_PREFERENCE_SAF_FILESYSTEM", "KEY_PREFERENCE_SECURE", "KEY_PREFERENCE_TIMEOUT", "KEY_PREFERENCE_USERNAME", "PORT_PREFERENCE_KEY", "TAG_STARTED_BY_TILE", "WIFI_AP_ADDRESS_PREFIX", "server", "Lorg/apache/ftpserver/FtpServer;", "serverThread", "Ljava/lang/Thread;", "byteOfInt", "", "value", "which", "callIsWifiApEnabled", "wifiManager", "Landroid/net/wifi/WifiManager;", "defaultPath", "context", "Landroid/content/Context;", "getLocalInetAddress", "Ljava/net/InetAddress;", "getPort", "preferences", "Landroid/content/SharedPreferences;", "intToInet", "isConnectedToLocalNetwork", "isConnectedToWifi", "isEnabledWifiHotspot", "isRunning", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
        
        /**
         * Derive the FTP server's default share path, depending the user's Android version.
         *
         * Default it's the internal storage's root as java.io.File; otherwise it's content://
         * based URI if it's running on Android 7.0 or above.
         */
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String defaultPath(@org.jetbrains.annotations.NotNull()
        android.content.Context context) {
            return null;
        }
        
        /**
         * Indicator whether FTP service is running
         */
        public final boolean isRunning() {
            return false;
        }
        
        /**
         * Is the device connected to local network, either Ethernet or Wifi?
         */
        public final boolean isConnectedToLocalNetwork(@org.jetbrains.annotations.NotNull()
        android.content.Context context) {
            return false;
        }
        
        /**
         * Is the device connected to Wifi?
         */
        public final boolean isConnectedToWifi(@org.jetbrains.annotations.NotNull()
        android.content.Context context) {
            return false;
        }
        
        /**
         * Is the device's wifi hotspot enabled?
         */
        public final boolean isEnabledWifiHotspot(@org.jetbrains.annotations.NotNull()
        android.content.Context context) {
            return false;
        }
        
        /**
         * Determine device's IP address
         */
        @org.jetbrains.annotations.Nullable()
        public final java.net.InetAddress getLocalInetAddress(@org.jetbrains.annotations.NotNull()
        android.content.Context context) {
            return null;
        }
        
        private final java.net.InetAddress intToInet(int value) {
            return null;
        }
        
        private final byte byteOfInt(int value, int which) {
            return 0;
        }
        
        private final int getPort(android.content.SharedPreferences preferences) {
            return 0;
        }
        
        private final boolean callIsWifiApEnabled(android.net.wifi.WifiManager wifiManager) {
            return false;
        }
    }
}