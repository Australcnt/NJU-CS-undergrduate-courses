package com.amaze.filemanager.filesystem.files;

import java.lang.System;

@kotlin.Suppress(names = {"TooManyFunctions", "StringLiteralDuplication"})
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u000f\b\u0007\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0003\u001a\u00020\u0004H\u0007J\b\u0010\u0005\u001a\u00020\u0004H\u0007J\b\u0010\u0006\u001a\u00020\u0004H\u0007J\b\u0010\u0007\u001a\u00020\u0004H\u0007J\b\u0010\b\u001a\u00020\u0004H\u0007J\b\u0010\t\u001a\u00020\u0004H\u0007J\b\u0010\n\u001a\u00020\u0004H\u0007J\b\u0010\u000b\u001a\u00020\u0004H\u0007J\b\u0010\f\u001a\u00020\u0004H\u0007J\b\u0010\r\u001a\u00020\u0004H\u0007J\b\u0010\u000e\u001a\u00020\u0004H\u0007J\b\u0010\u000f\u001a\u00020\u0004H\u0007J\b\u0010\u0010\u001a\u00020\u0004H\u0007J\b\u0010\u0011\u001a\u00020\u0004H\u0007J\b\u0010\u0012\u001a\u00020\u0004H\u0007\u00a8\u0006\u0013"}, d2 = {"Lcom/amaze/filemanager/filesystem/files/FileUtilsTest;", "", "()V", "testGetPathsInPathForFile", "", "testGetPathsInPathForFolder", "testGetPathsInPathForFolderWithSlashAtEnd", "testGetPathsInPathWithFtpUri", "testGetPathsInPathWithFtpUriWithMultiByteChars", "testGetPathsInPathWithNoSlashPrefix", "testGetPathsInPathWithSmbUri", "testGetPathsInPathWithSmbUri2", "testGetPathsInPathWithSmbUri3", "testGetPathsInPathWithSmbUri4", "testGetPathsInPathWithSmbUriContainingSpace", "testGetPathsInPathWithSpaceInPath", "testGetPathsInPathWithSpacePrefixed", "testParseStringForHybridFileParcelable", "testSplitUri", "app_fdroidDebug"})
@org.robolectric.annotation.Config(sdk = {16, 19, 28})
@org.robolectric.annotation.LooperMode(value = org.robolectric.annotation.LooperMode.Mode.PAUSED)
@org.junit.runner.RunWith(value = androidx.test.ext.junit.runners.AndroidJUnit4.class)
public final class FileUtilsTest {
    
    public FileUtilsTest() {
        super();
    }
    
    /**
     * Test FileUtils.getPathsInPath() for directory
     *
     * @see FileUtils.getPathsInPath
     */
    @org.junit.Test()
    public final void testGetPathsInPathForFolder() {
    }
    
    /**
     * Test FileUtils.getPathsInPath() for file
     *
     * @see FileUtils.getPathsInPath
     */
    @org.junit.Test()
    public final void testGetPathsInPathForFile() {
    }
    
    /**
     * Test FileUtils.getPathsInPath() for directory
     *
     * @see FileUtils.getPathsInPath
     */
    @org.junit.Test()
    public final void testGetPathsInPathForFolderWithSlashAtEnd() {
    }
    
    /**
     * Test FileUtils.getPathsInPath() with prefixing space in path
     *
     * @see FileUtils.getPathsInPath
     */
    @org.junit.Test()
    public final void testGetPathsInPathWithSpacePrefixed() {
    }
    
    /**
     * Test FileUtils.getPathsInPath() with spaces in path
     *
     * @see FileUtils.getPathsInPath
     */
    @org.junit.Test()
    public final void testGetPathsInPathWithSpaceInPath() {
    }
    
    /**
     * Test FileUtils.getPathsInPath() with spaces in path
     *
     * @see FileUtils.getPathsInPath
     */
    @org.junit.Test()
    public final void testGetPathsInPathWithNoSlashPrefix() {
    }
    
    /**
     * Test FileUtils.getPathsInPath() with SMB URI
     *
     * @see FileUtils.getPathsInPath
     */
    @org.junit.Test()
    public final void testGetPathsInPathWithSmbUri() {
    }
    
    /**
     * Test FileUtils.getPathsInPath() with SMB URI
     *
     * @see FileUtils.getPathsInPath
     */
    @org.junit.Test()
    public final void testGetPathsInPathWithSmbUri2() {
    }
    
    /**
     * Test FileUtils.getPathsInPath() with SMB URI
     *
     * @see FileUtils.getPathsInPath
     */
    @org.junit.Test()
    public final void testGetPathsInPathWithSmbUri3() {
    }
    
    /**
     * Test FileUtils.getPathsInPath() with SMB URI
     *
     * @see FileUtils.getPathsInPath
     */
    @org.junit.Test()
    public final void testGetPathsInPathWithSmbUri4() {
    }
    
    /**
     * Test FileUtils.getPathsInPath() with SMB URI containing space
     *
     * Legit URI should encode the space to %20, but not for our case. This case is
     * to ensure the space won't get encoded.
     *
     * @see FileUtils.getPathsInPath
     */
    @org.junit.Test()
    public final void testGetPathsInPathWithSmbUriContainingSpace() {
    }
    
    /**
     * Test FileUtils.getPathsInPath() with FTP URI having port number too
     *
     * @see FileUtils.getPathsInPath
     */
    @org.junit.Test()
    public final void testGetPathsInPathWithFtpUri() {
    }
    
    /**
     * Test FileUtils.getPathsInPath() with FTP URI with multi-byte characters.
     *
     * Legit URI should encode the multi-byte chars, but not for our case. This case is to
     * ensure the multi-byte chars won't get encoded.
     *
     * @see FileUtils.getPathsInPath
     */
    @org.junit.Test()
    public final void testGetPathsInPathWithFtpUriWithMultiByteChars() {
    }
    
    /**
     * Test [FileUtils.splitUri]
     */
    @org.junit.Test()
    public final void testSplitUri() {
    }
    
    /**
     * Test [FileUtils.parseName]
     */
    @org.junit.Test()
    public final void testParseStringForHybridFileParcelable() {
    }
}