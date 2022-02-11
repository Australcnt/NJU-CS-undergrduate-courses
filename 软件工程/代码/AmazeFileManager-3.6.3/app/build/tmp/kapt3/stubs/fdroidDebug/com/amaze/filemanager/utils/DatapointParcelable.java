package com.amaze.filemanager.utils;

import java.lang.System;

/**
 * Class stores the [AbstractProgressiveService] progress variables. This class also acts
 * as data carrier to communicate with [ProcessViewerFragment]
 *
 * @param name name of source file being copied
 * @param amountOfSourceFiles total number of source files to be copied
 * @param sourceProgress which file is being copied from total number of files
 * @param totalSize total size of all source files combined
 * @param byteProgress current byte position in total bytes pool
 * @param speedRaw bytes being copied per sec
 * @param move allows changing the text from "Copying" to "Moving" in case of copy
 * @param completed if the operation has finished
 */
@kotlinx.parcelize.Parcelize()
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\t\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u001a\n\u0002\u0010\u0000\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0087\b\u0018\u0000 /2\u00020\u0001:\u0001/BG\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\b\u0012\u0006\u0010\n\u001a\u00020\b\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\f\u00a2\u0006\u0002\u0010\u000eJ\u000b\u0010\u001b\u001a\u0004\u0018\u00010\u0003H\u00c6\u0003J\t\u0010\u001c\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u001d\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u001e\u001a\u00020\bH\u00c6\u0003J\t\u0010\u001f\u001a\u00020\bH\u00c6\u0003J\t\u0010 \u001a\u00020\bH\u00c6\u0003J\t\u0010!\u001a\u00020\fH\u00c6\u0003J\t\u0010\"\u001a\u00020\fH\u00c6\u0003J[\u0010#\u001a\u00020\u00002\n\b\u0002\u0010\u0002\u001a\u0004\u0018\u00010\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00052\b\b\u0002\u0010\u0007\u001a\u00020\b2\b\b\u0002\u0010\t\u001a\u00020\b2\b\b\u0002\u0010\n\u001a\u00020\b2\b\b\u0002\u0010\u000b\u001a\u00020\f2\b\b\u0002\u0010\r\u001a\u00020\fH\u00c6\u0001J\t\u0010$\u001a\u00020\u0005H\u00d6\u0001J\u0013\u0010%\u001a\u00020\f2\b\u0010&\u001a\u0004\u0018\u00010\'H\u00d6\u0003J\t\u0010(\u001a\u00020\u0005H\u00d6\u0001J\t\u0010)\u001a\u00020\u0003H\u00d6\u0001J\u0019\u0010*\u001a\u00020+2\u0006\u0010,\u001a\u00020-2\u0006\u0010.\u001a\u00020\u0005H\u00d6\u0001R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u0011\u0010\t\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012R\u0011\u0010\r\u001a\u00020\f\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\u0014R\u0011\u0010\u000b\u001a\u00020\f\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u0014R\u0013\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0017R\u0011\u0010\u0006\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0018\u0010\u0010R\u0011\u0010\n\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0019\u0010\u0012R\u0011\u0010\u0007\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001a\u0010\u0012\u00a8\u00060"}, d2 = {"Lcom/amaze/filemanager/utils/DatapointParcelable;", "Landroid/os/Parcelable;", "name", "", "amountOfSourceFiles", "", "sourceProgress", "totalSize", "", "byteProgress", "speedRaw", "move", "", "completed", "(Ljava/lang/String;IIJJJZZ)V", "getAmountOfSourceFiles", "()I", "getByteProgress", "()J", "getCompleted", "()Z", "getMove", "getName", "()Ljava/lang/String;", "getSourceProgress", "getSpeedRaw", "getTotalSize", "component1", "component2", "component3", "component4", "component5", "component6", "component7", "component8", "copy", "describeContents", "equals", "other", "", "hashCode", "toString", "writeToParcel", "", "parcel", "Landroid/os/Parcel;", "flags", "Companion", "app_fdroidDebug"})
public final class DatapointParcelable implements android.os.Parcelable {
    @org.jetbrains.annotations.Nullable()
    private final java.lang.String name = null;
    private final int amountOfSourceFiles = 0;
    private final int sourceProgress = 0;
    private final long totalSize = 0L;
    private final long byteProgress = 0L;
    private final long speedRaw = 0L;
    private final boolean move = false;
    private final boolean completed = false;
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.utils.DatapointParcelable.Companion Companion = null;
    public static final android.os.Parcelable.Creator<com.amaze.filemanager.utils.DatapointParcelable> CREATOR = null;
    
    /**
     * Class stores the [AbstractProgressiveService] progress variables. This class also acts
     * as data carrier to communicate with [ProcessViewerFragment]
     *
     * @param name name of source file being copied
     * @param amountOfSourceFiles total number of source files to be copied
     * @param sourceProgress which file is being copied from total number of files
     * @param totalSize total size of all source files combined
     * @param byteProgress current byte position in total bytes pool
     * @param speedRaw bytes being copied per sec
     * @param move allows changing the text from "Copying" to "Moving" in case of copy
     * @param completed if the operation has finished
     */
    @org.jetbrains.annotations.NotNull()
    public final com.amaze.filemanager.utils.DatapointParcelable copy(@org.jetbrains.annotations.Nullable()
    java.lang.String name, int amountOfSourceFiles, int sourceProgress, long totalSize, long byteProgress, long speedRaw, boolean move, boolean completed) {
        return null;
    }
    
    /**
     * Class stores the [AbstractProgressiveService] progress variables. This class also acts
     * as data carrier to communicate with [ProcessViewerFragment]
     *
     * @param name name of source file being copied
     * @param amountOfSourceFiles total number of source files to be copied
     * @param sourceProgress which file is being copied from total number of files
     * @param totalSize total size of all source files combined
     * @param byteProgress current byte position in total bytes pool
     * @param speedRaw bytes being copied per sec
     * @param move allows changing the text from "Copying" to "Moving" in case of copy
     * @param completed if the operation has finished
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
    
    /**
     * Class stores the [AbstractProgressiveService] progress variables. This class also acts
     * as data carrier to communicate with [ProcessViewerFragment]
     *
     * @param name name of source file being copied
     * @param amountOfSourceFiles total number of source files to be copied
     * @param sourceProgress which file is being copied from total number of files
     * @param totalSize total size of all source files combined
     * @param byteProgress current byte position in total bytes pool
     * @param speedRaw bytes being copied per sec
     * @param move allows changing the text from "Copying" to "Moving" in case of copy
     * @param completed if the operation has finished
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * Class stores the [AbstractProgressiveService] progress variables. This class also acts
     * as data carrier to communicate with [ProcessViewerFragment]
     *
     * @param name name of source file being copied
     * @param amountOfSourceFiles total number of source files to be copied
     * @param sourceProgress which file is being copied from total number of files
     * @param totalSize total size of all source files combined
     * @param byteProgress current byte position in total bytes pool
     * @param speedRaw bytes being copied per sec
     * @param move allows changing the text from "Copying" to "Moving" in case of copy
     * @param completed if the operation has finished
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    public DatapointParcelable(@org.jetbrains.annotations.Nullable()
    java.lang.String name, int amountOfSourceFiles, int sourceProgress, long totalSize, long byteProgress, long speedRaw, boolean move, boolean completed) {
        super();
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String component1() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String getName() {
        return null;
    }
    
    public final int component2() {
        return 0;
    }
    
    public final int getAmountOfSourceFiles() {
        return 0;
    }
    
    public final int component3() {
        return 0;
    }
    
    public final int getSourceProgress() {
        return 0;
    }
    
    public final long component4() {
        return 0L;
    }
    
    public final long getTotalSize() {
        return 0L;
    }
    
    public final long component5() {
        return 0L;
    }
    
    public final long getByteProgress() {
        return 0L;
    }
    
    public final long component6() {
        return 0L;
    }
    
    public final long getSpeedRaw() {
        return 0L;
    }
    
    public final boolean component7() {
        return false;
    }
    
    public final boolean getMove() {
        return false;
    }
    
    public final boolean component8() {
        return false;
    }
    
    public final boolean getCompleted() {
        return false;
    }
    
    @java.lang.Override()
    public int describeContents() {
        return 0;
    }
    
    @java.lang.Override()
    public void writeToParcel(@org.jetbrains.annotations.NotNull()
    android.os.Parcel parcel, int flags) {
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 3)
    public static final class Creator implements android.os.Parcelable.Creator<com.amaze.filemanager.utils.DatapointParcelable> {
        
        public Creator() {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public final com.amaze.filemanager.utils.DatapointParcelable createFromParcel(@org.jetbrains.annotations.NotNull()
        android.os.Parcel in) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public final com.amaze.filemanager.utils.DatapointParcelable[] newArray(int size) {
            return null;
        }
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u000b\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J(\u0010\u0003\u001a\u00020\u00042\b\u0010\u0005\u001a\u0004\u0018\u00010\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f\u00a8\u0006\r"}, d2 = {"Lcom/amaze/filemanager/utils/DatapointParcelable$Companion;", "", "()V", "buildDatapointParcelable", "Lcom/amaze/filemanager/utils/DatapointParcelable;", "name", "", "amountOfSourceFiles", "", "totalSize", "", "move", "", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
        
        /**
         * For the first datapoint, everything is 0 or false except the params. Allows move boolean to
         * change the text from "Copying" to "Moving" in case of copy.
         *
         * @param name name of source file being copied
         * @param amountOfSourceFiles total number of source files to be copied
         * @param totalSize total size of all source files combined
         * @param move allows changing the text from "Copying" to "Moving" in case of copy
         */
        @org.jetbrains.annotations.NotNull()
        public final com.amaze.filemanager.utils.DatapointParcelable buildDatapointParcelable(@org.jetbrains.annotations.Nullable()
        java.lang.String name, int amountOfSourceFiles, long totalSize, boolean move) {
            return null;
        }
    }
}