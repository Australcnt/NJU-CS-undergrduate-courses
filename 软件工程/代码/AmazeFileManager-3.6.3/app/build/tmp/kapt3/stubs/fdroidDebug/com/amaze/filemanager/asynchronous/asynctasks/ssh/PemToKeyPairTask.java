package com.amaze.filemanager.asynchronous.asynctasks.ssh;

import java.lang.System;

/**
 * [AsyncTask] to convert given [InputStream] into [KeyPair] which is requird by
 * sshj, using [JcaPEMKeyConverter].
 *
 * @see JcaPEMKeyConverter
 *
 * @see KeyProvider
 *
 * @see OpenSSHKeyV1KeyFile
 *
 * @see PuTTYKeyFile
 *
 * @see com.amaze.filemanager.filesystem.ssh.SshConnectionPool.create
 * @see net.schmizz.sshj.SSHClient.authPublickey
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000T\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u0012\n\u0002\b\u0002\n\u0002\u0010\u0011\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0002\b\u000b\u0018\u00002\u0018\u0012\u0004\u0012\u00020\u0002\u0012\u0006\u0012\u0004\u0018\u00010\u0003\u0012\u0006\u0012\u0004\u0018\u00010\u00040\u0001:\u0005\"#$%&B\u001f\b\u0016\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u000e\u0010\u0007\u001a\n\u0012\u0006\u0012\u0004\u0018\u00010\u00040\b\u00a2\u0006\u0002\u0010\tB\u001f\b\u0016\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u000e\u0010\u0007\u001a\n\u0012\u0006\u0012\u0004\u0018\u00010\u00040\b\u00a2\u0006\u0002\u0010\fB\u001d\u0012\u0006\u0010\u0005\u001a\u00020\r\u0012\u000e\u0010\u0007\u001a\n\u0012\u0006\u0012\u0004\u0018\u00010\u00040\b\u00a2\u0006\u0002\u0010\u000eJ#\u0010\u0018\u001a\u0004\u0018\u00010\u00042\u0012\u0010\u0019\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00020\u0010\"\u00020\u0002H\u0014\u00a2\u0006\u0002\u0010\u001aJ\u0012\u0010\u001b\u001a\u00020\u001c2\b\u0010\u001d\u001a\u0004\u0018\u00010\u0004H\u0014J%\u0010\u001e\u001a\u00020\u001c2\u0016\u0010\u001f\u001a\f\u0012\b\b\u0001\u0012\u0004\u0018\u00010\u00030\u0010\"\u0004\u0018\u00010\u0003H\u0014\u00a2\u0006\u0002\u0010 J\u0010\u0010!\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\u0003H\u0002R\u0016\u0010\u0007\u001a\n\u0012\u0006\u0012\u0004\u0018\u00010\u00040\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u000f\u001a\f\u0012\b\u0012\u00060\u0011R\u00020\u00000\u0010X\u0082\u0004\u00a2\u0006\u0004\n\u0002\u0010\u0012R\u0010\u0010\u0013\u001a\u0004\u0018\u00010\u000bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0014\u001a\u0004\u0018\u00010\u0015X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0017X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\'"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask;", "Landroid/os/AsyncTask;", "Ljava/lang/Void;", "Ljava/io/IOException;", "Ljava/security/KeyPair;", "pemFile", "Ljava/io/InputStream;", "callback", "Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult$Callback;", "(Ljava/io/InputStream;Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult$Callback;)V", "pemContent", "", "(Ljava/lang/String;Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult$Callback;)V", "", "([BLcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult$Callback;)V", "converters", "", "Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask$PemToKeyPairConverter;", "[Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask$PemToKeyPairConverter;", "errorMessage", "passwordFinder", "Lnet/schmizz/sshj/userauth/password/PasswordFinder;", "paused", "", "doInBackground", "voids", "([Ljava/lang/Void;)Ljava/security/KeyPair;", "onPostExecute", "", "result", "onProgressUpdate", "values", "([Ljava/io/IOException;)V", "toastOnParseError", "JcaPemToKeyPairConverter", "OpenSshPemToKeyPairConverter", "OpenSshV1PemToKeyPairConverter", "PemToKeyPairConverter", "PuttyPrivateKeyToKeyPairConverter", "app_fdroidDebug"})
public final class PemToKeyPairTask extends android.os.AsyncTask<java.lang.Void, java.io.IOException, java.security.KeyPair> {
    private final byte[] pemFile = null;
    private final com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult.Callback<java.security.KeyPair> callback = null;
    private final com.amaze.filemanager.asynchronous.asynctasks.ssh.PemToKeyPairTask.PemToKeyPairConverter[] converters = null;
    private boolean paused = false;
    private net.schmizz.sshj.userauth.password.PasswordFinder passwordFinder;
    private java.lang.String errorMessage;
    
    public PemToKeyPairTask(@org.jetbrains.annotations.NotNull()
    byte[] pemFile, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult.Callback<java.security.KeyPair> callback) {
        super();
    }
    
    public PemToKeyPairTask(@org.jetbrains.annotations.NotNull()
    java.io.InputStream pemFile, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult.Callback<java.security.KeyPair> callback) {
        super();
    }
    
    public PemToKeyPairTask(@org.jetbrains.annotations.NotNull()
    java.lang.String pemContent, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult.Callback<java.security.KeyPair> callback) {
        super();
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    protected java.security.KeyPair doInBackground(@org.jetbrains.annotations.NotNull()
    java.lang.Void... voids) {
        return null;
    }
    
    @java.lang.Override()
    protected void onProgressUpdate(@org.jetbrains.annotations.NotNull()
    java.io.IOException... values) {
    }
    
    @java.lang.Override()
    protected void onPostExecute(@org.jetbrains.annotations.Nullable()
    java.security.KeyPair result) {
    }
    
    private final void toastOnParseError(java.io.IOException result) {
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\b\u00a2\u0004\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0012\u0010\u0003\u001a\u0004\u0018\u00010\u00042\b\u0010\u0005\u001a\u0004\u0018\u00010\u0006J\u0014\u0010\u0007\u001a\u0004\u0018\u00010\u00042\b\u0010\u0005\u001a\u0004\u0018\u00010\u0006H$\u00a8\u0006\b"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask$PemToKeyPairConverter;", "", "(Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask;)V", "convert", "Ljava/security/KeyPair;", "source", "", "throwingConvert", "app_fdroidDebug"})
    abstract class PemToKeyPairConverter {
        
        public PemToKeyPairConverter() {
            super();
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.security.KeyPair convert(@org.jetbrains.annotations.Nullable()
        java.lang.String source) {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        protected abstract java.security.KeyPair throwingConvert(@org.jetbrains.annotations.Nullable()
        java.lang.String source) throws java.lang.Exception;
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\b\u0082\u0004\u0018\u00002\u00060\u0001R\u00020\u0002B\u0005\u00a2\u0006\u0002\u0010\u0003J\u0014\u0010\u0004\u001a\u0004\u0018\u00010\u00052\b\u0010\u0006\u001a\u0004\u0018\u00010\u0007H\u0014\u00a8\u0006\b"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask$JcaPemToKeyPairConverter;", "Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask$PemToKeyPairConverter;", "Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask;", "(Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask;)V", "throwingConvert", "Ljava/security/KeyPair;", "source", "", "app_fdroidDebug"})
    final class JcaPemToKeyPairConverter extends com.amaze.filemanager.asynchronous.asynctasks.ssh.PemToKeyPairTask.PemToKeyPairConverter {
        
        public JcaPemToKeyPairConverter() {
            super();
        }
        
        @org.jetbrains.annotations.Nullable()
        @java.lang.Override()
        protected java.security.KeyPair throwingConvert(@org.jetbrains.annotations.Nullable()
        java.lang.String source) throws java.lang.Exception {
            return null;
        }
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\b\u0082\u0004\u0018\u00002\u00060\u0001R\u00020\u0002B\u0005\u00a2\u0006\u0002\u0010\u0003J\u0012\u0010\u0004\u001a\u00020\u00052\b\u0010\u0006\u001a\u0004\u0018\u00010\u0007H\u0016\u00a8\u0006\b"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask$OpenSshPemToKeyPairConverter;", "Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask$PemToKeyPairConverter;", "Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask;", "(Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask;)V", "throwingConvert", "Ljava/security/KeyPair;", "source", "", "app_fdroidDebug"})
    final class OpenSshPemToKeyPairConverter extends com.amaze.filemanager.asynchronous.asynctasks.ssh.PemToKeyPairTask.PemToKeyPairConverter {
        
        public OpenSshPemToKeyPairConverter() {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.security.KeyPair throwingConvert(@org.jetbrains.annotations.Nullable()
        java.lang.String source) throws java.lang.Exception {
            return null;
        }
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\b\u0082\u0004\u0018\u00002\u00060\u0001R\u00020\u0002B\u0005\u00a2\u0006\u0002\u0010\u0003J\u0012\u0010\u0004\u001a\u00020\u00052\b\u0010\u0006\u001a\u0004\u0018\u00010\u0007H\u0016\u00a8\u0006\b"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask$OpenSshV1PemToKeyPairConverter;", "Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask$PemToKeyPairConverter;", "Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask;", "(Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask;)V", "throwingConvert", "Ljava/security/KeyPair;", "source", "", "app_fdroidDebug"})
    final class OpenSshV1PemToKeyPairConverter extends com.amaze.filemanager.asynchronous.asynctasks.ssh.PemToKeyPairTask.PemToKeyPairConverter {
        
        public OpenSshV1PemToKeyPairConverter() {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.security.KeyPair throwingConvert(@org.jetbrains.annotations.Nullable()
        java.lang.String source) throws java.lang.Exception {
            return null;
        }
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\b\u0082\u0004\u0018\u00002\u00060\u0001R\u00020\u0002B\u0005\u00a2\u0006\u0002\u0010\u0003J\u0012\u0010\u0004\u001a\u00020\u00052\b\u0010\u0006\u001a\u0004\u0018\u00010\u0007H\u0016\u00a8\u0006\b"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask$PuttyPrivateKeyToKeyPairConverter;", "Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask$PemToKeyPairConverter;", "Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask;", "(Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/PemToKeyPairTask;)V", "throwingConvert", "Ljava/security/KeyPair;", "source", "", "app_fdroidDebug"})
    final class PuttyPrivateKeyToKeyPairConverter extends com.amaze.filemanager.asynchronous.asynctasks.ssh.PemToKeyPairTask.PemToKeyPairConverter {
        
        public PuttyPrivateKeyToKeyPairConverter() {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.security.KeyPair throwingConvert(@org.jetbrains.annotations.Nullable()
        java.lang.String source) throws java.lang.Exception {
            return null;
        }
    }
}