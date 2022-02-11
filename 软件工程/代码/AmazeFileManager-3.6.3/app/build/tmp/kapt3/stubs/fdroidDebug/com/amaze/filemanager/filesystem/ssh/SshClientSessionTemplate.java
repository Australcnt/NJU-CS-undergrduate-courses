package com.amaze.filemanager.filesystem.ssh;

import java.lang.System;

/**
 * Constructor.
 *
 * @param url SSH connection URL, in the form of `
 * ssh://<username>:<password>@<host>:<port>` or `
 * ssh://<username>@<host>:<port>`
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\b&\u0018\u0000*\u0004\b\u0000\u0010\u00012\u00020\u0002B\r\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\u0015\u0010\u0006\u001a\u00028\u00002\u0006\u0010\u0007\u001a\u00020\bH&\u00a2\u0006\u0002\u0010\tR\u0010\u0010\u0003\u001a\u00020\u00048\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\n"}, d2 = {"Lcom/amaze/filemanager/filesystem/ssh/SshClientSessionTemplate;", "T", "", "url", "", "(Ljava/lang/String;)V", "execute", "sshClientSession", "Lnet/schmizz/sshj/connection/channel/direct/Session;", "(Lnet/schmizz/sshj/connection/channel/direct/Session;)Ljava/lang/Object;", "app_fdroidDebug"})
public abstract class SshClientSessionTemplate<T extends java.lang.Object> {
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String url = null;
    
    public SshClientSessionTemplate(@org.jetbrains.annotations.NotNull()
    java.lang.String url) {
        super();
    }
    
    /**
     * Implement logic here.
     *
     * @param sshClientSession [Session] instance, with connection opened and authenticated
     * @param <T> Requested return type
     * @return Result of the execution of the type requested
     */
    public abstract T execute(@org.jetbrains.annotations.NotNull()
    net.schmizz.sshj.connection.channel.direct.Session sshClientSession);
}