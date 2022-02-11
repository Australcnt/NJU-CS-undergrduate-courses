package com.amaze.filemanager.filesystem.ssh;

import java.lang.System;

/**
 * Template class for executing actions with [SFTPClient] while leave the complexities of
 * handling connection and session setup/teardown to [SshClientUtils].
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\b&\u0018\u0000*\u0004\b\u0000\u0010\u00012\u00020\u0002B\u0019\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\b\b\u0002\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\u0015\u0010\b\u001a\u00028\u00002\u0006\u0010\t\u001a\u00020\nH&\u00a2\u0006\u0002\u0010\u000bR\u0010\u0010\u0005\u001a\u00020\u00068\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0003\u001a\u00020\u00048\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\f"}, d2 = {"Lcom/amaze/filemanager/filesystem/ssh/SFtpClientTemplate;", "T", "", "url", "", "closeClientOnFinish", "", "(Ljava/lang/String;Z)V", "execute", "client", "Lnet/schmizz/sshj/sftp/SFTPClient;", "(Lnet/schmizz/sshj/sftp/SFTPClient;)Ljava/lang/Object;", "app_fdroidDebug"})
public abstract class SFtpClientTemplate<T extends java.lang.Object> {
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String url = null;
    public final boolean closeClientOnFinish = false;
    
    public SFtpClientTemplate(@org.jetbrains.annotations.NotNull()
    java.lang.String url) {
        super();
    }
    
    public SFtpClientTemplate(@org.jetbrains.annotations.NotNull()
    java.lang.String url, boolean closeClientOnFinish) {
        super();
    }
    
    /**
     * Implement logic here.
     *
     * @param client [SFTPClient] instance, with connection opened and authenticated, and SSH
     * session had been set up.
     * @param <T> Requested return type
     * @return Result of the execution of the type requested
     */
    public abstract T execute(@org.jetbrains.annotations.NotNull()
    net.schmizz.sshj.sftp.SFTPClient client);
}