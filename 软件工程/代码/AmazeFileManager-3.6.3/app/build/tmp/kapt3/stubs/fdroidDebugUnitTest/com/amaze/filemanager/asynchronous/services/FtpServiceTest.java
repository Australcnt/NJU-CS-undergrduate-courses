package com.amaze.filemanager.asynchronous.services;

import java.lang.System;

@kotlin.Suppress(names = {"StringLiteralDuplication"})
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0012\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\t\b\u0007\u0018\u0000 \u00142\u00020\u0001:\u0001\u0014B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u000b\u001a\u00020\fH\u0007J\b\u0010\r\u001a\u00020\fH\u0002J\b\u0010\u000e\u001a\u00020\fH\u0007J\b\u0010\u000f\u001a\u00020\fH\u0007J\b\u0010\u0010\u001a\u00020\fH\u0007J\b\u0010\u0011\u001a\u00020\fH\u0007J\b\u0010\u0012\u001a\u00020\fH\u0007J\b\u0010\u0013\u001a\u00020\fH\u0007R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082D\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0005\u001a\u0004\u0018\u00010\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\t\u001a\u0004\u0018\u00010\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0015"}, d2 = {"Lcom/amaze/filemanager/asynchronous/services/FtpServiceTest;", "", "()V", "FTP_PORT", "", "ftpClient", "Lorg/apache/commons/net/ftp/FTPClient;", "randomContent", "", "server", "Lorg/apache/ftpserver/FtpServer;", "setUp", "", "setupNetwork", "tearDown", "testChdir", "testDownloadFile", "testRmDir", "testUploadFile", "testUploadFileToSubDir", "Companion", "app_fdroidDebug"})
@org.robolectric.annotation.LooperMode(value = org.robolectric.annotation.LooperMode.Mode.PAUSED)
@org.robolectric.annotation.Config(sdk = {19}, shadows = {com.amaze.filemanager.shadows.ShadowMultiDex.class})
@org.junit.runner.RunWith(value = androidx.test.ext.junit.runners.AndroidJUnit4.class)
public final class FtpServiceTest {
    private final int FTP_PORT = 62222;
    private org.apache.ftpserver.FtpServer server;
    private final byte[] randomContent = null;
    private org.apache.commons.net.ftp.FTPClient ftpClient;
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.asynchronous.services.FtpServiceTest.Companion Companion = null;
    @org.jetbrains.annotations.NotNull()
    private static final java.lang.String[] directories = null;
    
    public FtpServiceTest() {
        super();
    }
    
    /**
     * Test setup
     */
    @org.junit.Before()
    public final void setUp() {
    }
    
    private final void setupNetwork() {
    }
    
    /**
     * Kill FTP server if there is one running
     */
    @org.junit.After()
    public final void tearDown() {
    }
    
    /**
     * Test on change directory functions
     */
    @org.junit.Test()
    public final void testChdir() {
    }
    
    /**
     * Test remove directory function
     */
    @org.junit.Test()
    public final void testRmDir() {
    }
    
    /**
     * Test download file
     */
    @org.junit.Test()
    public final void testDownloadFile() {
    }
    
    /**
     * Test upload file
     */
    @org.junit.Test()
    public final void testUploadFile() {
    }
    
    /**
     * Test working with files and folders at subfolders
     */
    @org.junit.Test()
    public final void testUploadFileToSubDir() {
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0005\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R!\u0010\u0003\u001a\u0010\u0012\f\u0012\n \u0006*\u0004\u0018\u00010\u00050\u00050\u0004\u00a2\u0006\n\n\u0002\u0010\t\u001a\u0004\b\u0007\u0010\b\u00a8\u0006\n"}, d2 = {"Lcom/amaze/filemanager/asynchronous/services/FtpServiceTest$Companion;", "", "()V", "directories", "", "", "kotlin.jvm.PlatformType", "getDirectories", "()[Ljava/lang/String;", "[Ljava/lang/String;", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String[] getDirectories() {
            return null;
        }
    }
}