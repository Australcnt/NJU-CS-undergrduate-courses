package com.amaze.filemanager.filesystem;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\"\n\u0002\u0010\f\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u000b\u001a\u00020\u00052\u0006\u0010\f\u001a\u00020\rH\u0002J\u0018\u0010\u000e\u001a\u00020\t2\u0006\u0010\f\u001a\u00020\r2\u0006\u0010\u000f\u001a\u00020\u0010H\u0002J\u0016\u0010\u0011\u001a\u00020\t2\u0006\u0010\f\u001a\u00020\r2\u0006\u0010\u000f\u001a\u00020\u0010J\u001e\u0010\u0011\u001a\u00020\t2\u0006\u0010\f\u001a\u00020\r2\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0012\u001a\u00020\u0010R\u0014\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\b\u001a\b\u0012\u0004\u0012\u00020\t0\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u0005X\u0086T\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0013"}, d2 = {"Lcom/amaze/filemanager/filesystem/RandomPathGenerator;", "", "()V", "letters", "", "", "numbers", "other", "reservedFileNames", "", "separator", "generateRandomCharacter", "random", "Lkotlin/random/Random;", "generateRandomFilename", "length", "", "generateRandomPath", "slashesInPath", "app_fdroidDebug"})
public final class RandomPathGenerator {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.RandomPathGenerator INSTANCE = null;
    public static final char separator = '/';
    private static final java.util.Set<java.lang.Character> letters = null;
    private static final java.util.Set<java.lang.Character> numbers = null;
    private static final java.util.Set<java.lang.Character> other = null;
    private static final java.util.Set<java.lang.String> reservedFileNames = null;
    
    private RandomPathGenerator() {
        super();
    }
    
    /**
     * Generates a valid random path
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String generateRandomPath(@org.jetbrains.annotations.NotNull()
    kotlin.random.Random random, int length) {
        return null;
    }
    
    /**
     * Generates a valid random path, with a specific amount of directories
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String generateRandomPath(@org.jetbrains.annotations.NotNull()
    kotlin.random.Random random, int length, int slashesInPath) {
        return null;
    }
    
    private final java.lang.String generateRandomFilename(kotlin.random.Random random, int length) {
        return null;
    }
    
    /**
     * Characters from POSIX 3.282 Portable Filename Character Set.
     *
     * Not all characters should be tested equally,
     * this ensures that paths not only contain letters.
     */
    private final char generateRandomCharacter(kotlin.random.Random random) {
        return '\u0000';
    }
}