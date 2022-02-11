package com.amaze.filemanager.asynchronous.services;

import java.lang.System;

@kotlin.Suppress(names = {"TooManyFunctions", "StringLiteralDuplication"})
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\f\n\u0002\u0018\u0002\n\u0002\b\n\n\u0002\u0010\u0002\n\u0002\b\u0015\b\u0007\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u001b\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\u0004H\u0002J\b\u0010\u001e\u001a\u00020\u001cH\u0007J\b\u0010\u001f\u001a\u00020\u001cH\u0007J\b\u0010 \u001a\u00020\u001cH\u0007J\b\u0010!\u001a\u00020\u001cH\u0007J\b\u0010\"\u001a\u00020\u001cH\u0007J\b\u0010#\u001a\u00020\u001cH\u0007J\b\u0010$\u001a\u00020\u001cH\u0007J\b\u0010%\u001a\u00020\u001cH\u0007J\b\u0010&\u001a\u00020\u001cH\u0007J\b\u0010\'\u001a\u00020\u001cH\u0007J\b\u0010(\u001a\u00020\u001cH\u0007J\b\u0010)\u001a\u00020\u001cH\u0007J\b\u0010*\u001a\u00020\u001cH\u0007J\b\u0010+\u001a\u00020\u001cH\u0007J\b\u0010,\u001a\u00020\u001cH\u0007J\b\u0010-\u001a\u00020\u001cH\u0007J\b\u0010.\u001a\u00020\u001cH\u0007J\b\u0010/\u001a\u00020\u001cH\u0007J\b\u00100\u001a\u00020\u001cH\u0007R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0010\u001a\u0004\u0018\u00010\u0011X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0017\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0019\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001a\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u00061"}, d2 = {"Lcom/amaze/filemanager/asynchronous/services/ExtractServiceTest;", "", "()V", "emptyTar", "Ljava/io/File;", "emptyZip", "listPasswordProtected7Zipfile", "multiVolumeRarFilePart1", "multiVolumeRarFilePart2", "multiVolumeRarFilePart3", "multiVolumeRarFileV5Part1", "multiVolumeRarFileV5Part2", "multiVolumeRarFileV5Part3", "passwordProtected7Zipfile", "passwordProtectedZipfile", "rarfile", "service", "Lcom/amaze/filemanager/asynchronous/services/ExtractService;", "sevenZipfile", "tarBz2file", "tarLzmafile", "tarXzfile", "tarballfile", "tarfile", "zipfile1", "zipfile2", "zipfile3", "performTest", "", "archiveFile", "setUp", "tearDown", "testEmptyTar", "testEmptyZip", "testExtract7z", "testExtractListPasswordProtected7Zip", "testExtractMultiVolumeRar", "testExtractMultiVolumeRarV5", "testExtractPasswordProtected7Zip", "testExtractPasswordProtectedZip", "testExtractRar", "testExtractTar", "testExtractTarBz2", "testExtractTarGz", "testExtractTarLzma", "testExtractTarXz", "testExtractZipNormal", "testExtractZipSlip", "testExtractZipSlipWin", "app_fdroidDebug"})
@org.robolectric.annotation.LooperMode(value = org.robolectric.annotation.LooperMode.Mode.PAUSED)
@org.robolectric.annotation.Config(shadows = {com.amaze.filemanager.shadows.ShadowMultiDex.class}, sdk = {16, 19, 28})
@org.junit.runner.RunWith(value = androidx.test.ext.junit.runners.AndroidJUnit4.class)
public final class ExtractServiceTest {
    private final java.io.File zipfile1 = null;
    private final java.io.File zipfile2 = null;
    private final java.io.File zipfile3 = null;
    private final java.io.File emptyZip = null;
    private final java.io.File rarfile = null;
    private final java.io.File tarfile = null;
    private final java.io.File emptyTar = null;
    private final java.io.File tarballfile = null;
    private final java.io.File tarLzmafile = null;
    private final java.io.File tarXzfile = null;
    private final java.io.File tarBz2file = null;
    private final java.io.File sevenZipfile = null;
    private final java.io.File passwordProtectedZipfile = null;
    private final java.io.File passwordProtected7Zipfile = null;
    private final java.io.File listPasswordProtected7Zipfile = null;
    private final java.io.File multiVolumeRarFilePart1 = null;
    private final java.io.File multiVolumeRarFilePart2 = null;
    private final java.io.File multiVolumeRarFilePart3 = null;
    private final java.io.File multiVolumeRarFileV5Part1 = null;
    private final java.io.File multiVolumeRarFileV5Part2 = null;
    private final java.io.File multiVolumeRarFileV5Part3 = null;
    private com.amaze.filemanager.asynchronous.services.ExtractService service;
    
    public ExtractServiceTest() {
        super();
    }
    
    /**
     * Copy archives to storage.
     *
     * @throws Exception
     */
    @org.junit.Before()
    public final void setUp() throws java.lang.Exception {
    }
    
    /**
     * Post test cleanup.
     *
     * @throws Exception
     */
    @org.junit.After()
    public final void tearDown() throws java.lang.Exception {
    }
    
    /**
     * Test zip-slip security vulnerability.
     */
    @org.junit.Test()
    public final void testExtractZipSlip() {
    }
    
    /**
     * Test zip-slip vulnerability for zips with Windows paths.
     */
    @org.junit.Test()
    public final void testExtractZipSlipWin() {
    }
    
    /**
     * Test normal unzip.
     */
    @org.junit.Test()
    public final void testExtractZipNormal() {
    }
    
    /**
     * Test unrar.
     */
    @org.junit.Test()
    public final void testExtractRar() {
    }
    
    /**
     * Test tar extract.
     */
    @org.junit.Test()
    public final void testExtractTar() {
    }
    
    /**
     * Test tar.gz extract.
     */
    @org.junit.Test()
    public final void testExtractTarGz() {
    }
    
    /**
     * Test tar.lzma extract.
     */
    @org.junit.Test()
    public final void testExtractTarLzma() {
    }
    
    /**
     * Test tar.xz extract.
     */
    @org.junit.Test()
    public final void testExtractTarXz() {
    }
    
    /**
     * Test tar.bz2 extract.
     */
    @org.junit.Test()
    public final void testExtractTarBz2() {
    }
    
    /**
     * Test 7z extract.
     */
    @org.junit.Test()
    public final void testExtract7z() {
    }
    
    /**
     * Test password-protected zip.
     */
    @org.junit.Test()
    public final void testExtractPasswordProtectedZip() {
    }
    
    /**
     * Test password-protected 7z.
     */
    @org.junit.Ignore(value = "Work isn\'t finished yet, skipping test")
    @org.junit.Test()
    public final void testExtractPasswordProtected7Zip() {
    }
    
    /**
     * Test password-protected 7zip with list also protected.
     */
    @org.junit.Test()
    public final void testExtractListPasswordProtected7Zip() {
    }
    
    /**
     * Test multi-volume rar extract.
     */
    @org.junit.Test()
    public final void testExtractMultiVolumeRar() {
    }
    
    /**
     * Test multi volume rar v5 extract. Should Toast user that rar v5 is unsupported.
     */
    @org.junit.Test()
    public final void testExtractMultiVolumeRarV5() {
    }
    
    /**
     * Test for extracting zip with zero entries.
     *
     * @see [https://github.com/TeamAmaze/AmazeFileManager/issues/2659]
     */
    @org.junit.Test()
    public final void testEmptyZip() {
    }
    
    /**
     * Test for extracting tar with zero entries.
     *
     * @see [https://github.com/TeamAmaze/AmazeFileManager/issues/2659]
     */
    @org.junit.Test()
    public final void testEmptyTar() {
    }
    
    private final void performTest(java.io.File archiveFile) {
    }
}