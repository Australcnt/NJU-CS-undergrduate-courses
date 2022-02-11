package com.amaze.filemanager.asynchronous.asynctasks.ssh;

import java.lang.System;

/**
 * [AsyncTask] for authenticating with SSH server to verify if parameters are correct.
 *
 *
 * Used by [com.amaze.filemanager.ui.dialogs.SftpConnectDialog].
 *
 * @see SSHClient
 *
 * @see SSHClient.authPassword
 * @see SSHClient.authPublickey
 * @see com.amaze.filemanager.ui.dialogs.SftpConnectDialog.authenticateAndSaveSetup
 * @see com.amaze.filemanager.filesystem.ssh.SshConnectionPool.create
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0011\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0002\u0018\u00002\u001a\u0012\u0004\u0012\u00020\u0002\u0012\u0004\u0012\u00020\u0002\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00040\u00030\u0001B=\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\u0006\u0012\u0006\u0010\n\u001a\u00020\u0006\u0012\n\b\u0002\u0010\u000b\u001a\u0004\u0018\u00010\u0006\u0012\n\b\u0002\u0010\f\u001a\u0004\u0018\u00010\r\u00a2\u0006\u0002\u0010\u000eJ\'\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00040\u00032\u0012\u0010\u0010\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00020\u0011\"\u00020\u0002H\u0014\u00a2\u0006\u0002\u0010\u0012J\u0016\u0010\u0013\u001a\u00020\u00142\f\u0010\u0015\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003H\u0014R\u000e\u0010\t\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000b\u001a\u0004\u0018\u00010\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\f\u001a\u0004\u0018\u00010\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0016"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/SshAuthenticationTask;", "Landroid/os/AsyncTask;", "Ljava/lang/Void;", "Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult;", "Lnet/schmizz/sshj/SSHClient;", "hostname", "", "port", "", "hostKey", "username", "password", "privateKey", "Ljava/security/KeyPair;", "(Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/security/KeyPair;)V", "doInBackground", "params", "", "([Ljava/lang/Void;)Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult;", "onPostExecute", "", "result", "app_fdroidDebug"})
public final class SshAuthenticationTask extends android.os.AsyncTask<java.lang.Void, java.lang.Void, com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<net.schmizz.sshj.SSHClient>> {
    
    /**
     * Constructor.
     *
     * @param hostname hostname, required
     * @param port port, must be unsigned integer
     * @param hostKey SSH host fingerprint, required
     * @param username login username, required
     * @param password login password, required if using password authentication
     * @param privateKey login [KeyPair], required if using key-based authentication
     */
    private final java.lang.String hostname = null;
    private final int port = 0;
    private final java.lang.String hostKey = null;
    private final java.lang.String username = null;
    private final java.lang.String password = null;
    private final java.security.KeyPair privateKey = null;
    
    public SshAuthenticationTask(@org.jetbrains.annotations.NotNull()
    java.lang.String hostname, int port, @org.jetbrains.annotations.NotNull()
    java.lang.String hostKey, @org.jetbrains.annotations.NotNull()
    java.lang.String username, @org.jetbrains.annotations.Nullable()
    java.lang.String password, @org.jetbrains.annotations.Nullable()
    java.security.KeyPair privateKey) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<net.schmizz.sshj.SSHClient> doInBackground(@org.jetbrains.annotations.NotNull()
    java.lang.Void... params) {
        return null;
    }
    
    @java.lang.Override()
    protected void onPostExecute(@org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<net.schmizz.sshj.SSHClient> result) {
    }
}