package com.amaze.filemanager.asynchronous.asynctasks.ssh;

import java.lang.System;

/**
 * [AsyncTask] to obtain SSH host fingerprint.
 *
 *
 * It works by adding a [HostKeyVerifier] that accepts all SSH host keys, then obtain the
 * key shown by server, and return to the task's caller.
 *
 *
 * [CountDownLatch] with [AtomicReference] combo is used to ensure SSH host key is
 * obtained successfully on returning to the task caller.
 *
 *
 * Mainly used by [com.amaze.filemanager.ui.dialogs.SftpConnectDialog] on saving SSH
 * connection settings.
 *
 * @see HostKeyVerifier
 *
 * @see SSHClient.addHostKeyVerifier
 * @see com.amaze.filemanager.ui.dialogs.SftpConnectDialog.onCreateDialog
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000B\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0011\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0004\u0018\u0000 \u00162\u001a\u0012\u0004\u0012\u00020\u0002\u0012\u0004\u0012\u00020\u0002\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00040\u00030\u0001:\u0001\u0016B)\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0012\u0010\t\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00040\u00030\n\u00a2\u0006\u0002\u0010\u000bJ\'\u0010\u000e\u001a\b\u0012\u0004\u0012\u00020\u00040\u00032\u0012\u0010\u000f\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00020\u0010\"\u00020\u0002H\u0014\u00a2\u0006\u0002\u0010\u0011J\u0016\u0010\u0012\u001a\u00020\u00132\f\u0010\u0014\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003H\u0014J\b\u0010\u0015\u001a\u00020\u0013H\u0014R\u001a\u0010\t\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00040\u00030\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\f\u001a\u0004\u0018\u00010\rX\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0017"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/GetSshHostFingerprintTask;", "Landroid/os/AsyncTask;", "Ljava/lang/Void;", "Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult;", "Ljava/security/PublicKey;", "hostname", "", "port", "", "callback", "Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult$Callback;", "(Ljava/lang/String;ILcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult$Callback;)V", "progressDialog", "Landroid/app/ProgressDialog;", "doInBackground", "params", "", "([Ljava/lang/Void;)Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult;", "onPostExecute", "", "result", "onPreExecute", "Companion", "app_fdroidDebug"})
public final class GetSshHostFingerprintTask extends android.os.AsyncTask<java.lang.Void, java.lang.Void, com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.security.PublicKey>> {
    private final java.lang.String hostname = null;
    private final int port = 0;
    private final com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult.Callback<com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.security.PublicKey>> callback = null;
    private android.app.ProgressDialog progressDialog;
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.asynchronous.asynctasks.ssh.GetSshHostFingerprintTask.Companion Companion = null;
    private static final java.lang.String TAG = null;
    
    public GetSshHostFingerprintTask(@org.jetbrains.annotations.NotNull()
    java.lang.String hostname, int port, @org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult.Callback<com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.security.PublicKey>> callback) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.security.PublicKey> doInBackground(@org.jetbrains.annotations.NotNull()
    java.lang.Void... params) {
        return null;
    }
    
    @java.lang.Override()
    protected void onPreExecute() {
    }
    
    @java.lang.Override()
    protected void onPostExecute(@org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.security.PublicKey> result) {
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u0005"}, d2 = {"Lcom/amaze/filemanager/asynchronous/asynctasks/ssh/GetSshHostFingerprintTask$Companion;", "", "()V", "TAG", "", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}