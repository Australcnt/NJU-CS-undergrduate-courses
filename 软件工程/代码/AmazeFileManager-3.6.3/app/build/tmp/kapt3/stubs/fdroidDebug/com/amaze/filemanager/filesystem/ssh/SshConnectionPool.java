package com.amaze.filemanager.filesystem.ssh;

import java.lang.System;

/**
 * Poor man's implementation of SSH connection pool.
 *
 *
 * It uses a [ConcurrentHashMap] to hold the opened SSH connections; all code that uses
 * [SSHClient] can ask for connection here with `getConnection(url)`.
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000L\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0005\b\u00c6\u0002\u0018\u00002\u00020\u0001:\u0004\"#$%B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0012\u0010\u000e\u001a\u0004\u0018\u00010\u000b2\u0006\u0010\u000f\u001a\u00020\u0007H\u0002J>\u0010\u000e\u001a\u0004\u0018\u00010\u000b2\u0006\u0010\u0010\u001a\u00020\u00072\u0006\u0010\u0011\u001a\u00020\u00042\u0006\u0010\u0012\u001a\u00020\u00072\u0006\u0010\u0013\u001a\u00020\u00072\b\u0010\u0014\u001a\u0004\u0018\u00010\u00072\b\u0010\u0015\u001a\u0004\u0018\u00010\u0016H\u0002J\u0010\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u000bH\u0002J\u0010\u0010\u001a\u001a\u0004\u0018\u00010\u000b2\u0006\u0010\u000f\u001a\u00020\u0007J<\u0010\u001a\u001a\u0004\u0018\u00010\u000b2\u0006\u0010\u0010\u001a\u00020\u00072\u0006\u0010\u0011\u001a\u00020\u00042\u0006\u0010\u001b\u001a\u00020\u00072\u0006\u0010\u0013\u001a\u00020\u00072\b\u0010\u0014\u001a\u0004\u0018\u00010\u00072\b\u0010\u0015\u001a\u0004\u0018\u00010\u0016J\u0016\u0010\u001c\u001a\u00020\u00182\u0006\u0010\u000f\u001a\u00020\u00072\u0006\u0010\u001d\u001a\u00020\u001eJ\u0006\u0010\u001f\u001a\u00020\u0018J\u0010\u0010 \u001a\u00020!2\u0006\u0010\u0019\u001a\u00020\u000bH\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\t\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\u000b0\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\f\u001a\u00020\r8\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u0006&"}, d2 = {"Lcom/amaze/filemanager/filesystem/ssh/SshConnectionPool;", "", "()V", "SSH_CONNECT_TIMEOUT", "", "SSH_DEFAULT_PORT", "SSH_URI_PREFIX", "", "TAG", "connections", "", "Lnet/schmizz/sshj/SSHClient;", "sshClientFactory", "Lcom/amaze/filemanager/filesystem/ssh/SshConnectionPool$SSHClientFactory;", "create", "url", "host", "port", "hostKey", "username", "password", "keyPair", "Ljava/security/KeyPair;", "expire", "", "client", "getConnection", "hostFingerprint", "removeConnection", "callback", "Ljava/lang/Runnable;", "shutdown", "validate", "", "AsyncRemoveConnection", "ConnectionInfo", "DefaultSSHClientFactory", "SSHClientFactory", "app_fdroidDebug"})
public final class SshConnectionPool {
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.filesystem.ssh.SshConnectionPool INSTANCE = null;
    public static final int SSH_DEFAULT_PORT = 22;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String SSH_URI_PREFIX = "ssh://";
    public static final int SSH_CONNECT_TIMEOUT = 30000;
    private static final java.lang.String TAG = null;
    private static java.util.Map<java.lang.String, net.schmizz.sshj.SSHClient> connections;
    @org.jetbrains.annotations.NotNull()
    public static com.amaze.filemanager.filesystem.ssh.SshConnectionPool.SSHClientFactory sshClientFactory;
    
    private SshConnectionPool() {
        super();
    }
    
    /**
     * Remove a SSH connection from connection pool. Disconnects from server before removing.
     *
     *
     * For updating SSH connection settings.
     *
     *
     * This method will silently end without feedback if the specified SSH connection URI does not
     * exist in the connection pool.
     *
     * @param url SSH connection URI
     */
    public final void removeConnection(@org.jetbrains.annotations.NotNull()
    java.lang.String url, @org.jetbrains.annotations.NotNull()
    java.lang.Runnable callback) {
    }
    
    /**
     * Obtain a [SSHClient] connection from the underlying connection pool.
     *
     *
     * Beneath it will return the connection if it exists; otherwise it will create a new one and
     * put it into the connection pool.
     *
     * @param url SSH connection URL, in the form of `
     * ssh://<username>:<password>@<host>:<port>` or `
     * ssh://<username>@<host>:<port>`
     * @return [SSHClient] connection, already opened and authenticated
     * @throws IOException IOExceptions that occur during connection setup
     */
    @org.jetbrains.annotations.Nullable()
    public final net.schmizz.sshj.SSHClient getConnection(@org.jetbrains.annotations.NotNull()
    java.lang.String url) {
        return null;
    }
    
    /**
     * Obtain a [SSHClient] connection from the underlying connection pool.
     *
     *
     * Beneath it will return the connection if it exists; otherwise it will create a new one and
     * put it into the connection pool.
     *
     *
     * Different from [.getConnection] above, this accepts broken down parameters as
     * convenience method during setting up SCP/SFTP connection.
     *
     * @param host host name/IP, required
     * @param port SSH server port, required
     * @param hostFingerprint expected host fingerprint, required
     * @param username username, required
     * @param password password, required if using password to authenticate
     * @param keyPair [KeyPair], required if using key-based authentication
     * @return [SSHClient] connection
     */
    @org.jetbrains.annotations.Nullable()
    @kotlin.Suppress(names = {"LongParameterList"})
    public final net.schmizz.sshj.SSHClient getConnection(@org.jetbrains.annotations.NotNull()
    java.lang.String host, int port, @org.jetbrains.annotations.NotNull()
    java.lang.String hostFingerprint, @org.jetbrains.annotations.NotNull()
    java.lang.String username, @org.jetbrains.annotations.Nullable()
    java.lang.String password, @org.jetbrains.annotations.Nullable()
    java.security.KeyPair keyPair) {
        return null;
    }
    
    /**
     * Kill any connection that is still in place. Used by [ ].
     *
     * @see MainActivity.onDestroy
     * @see MainActivity.exit
     */
    public final void shutdown() {
    }
    
    @kotlin.Suppress(names = {"TooGenericExceptionThrown"})
    private final net.schmizz.sshj.SSHClient create(java.lang.String url) {
        return null;
    }
    
    @kotlin.Suppress(names = {"LongParameterList"})
    private final net.schmizz.sshj.SSHClient create(java.lang.String host, int port, java.lang.String hostKey, java.lang.String username, java.lang.String password, java.security.KeyPair keyPair) {
        return null;
    }
    
    private final boolean validate(net.schmizz.sshj.SSHClient client) {
        return false;
    }
    
    private final void expire(net.schmizz.sshj.SSHClient client) {
    }
    
    /**
     * Container object for SSH URI, encapsulating logic for splitting information from given URI.
     * `Uri.parse()` only parse URI that is compliant to RFC2396, but we have to deal with
     * URI that is not compliant, since usernames and/or strong passwords usually have special
     * characters included, like `ssh://user@example.com:P@##w0rd@127.0.0.1:22`.
     *
     *
     * A design decision to keep database schema slim, by the way... -TranceLove
     */
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0002\b\n\n\u0002\u0010\b\n\u0002\b\u0005\b\u0000\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004R\u001c\u0010\u0005\u001a\u0004\u0018\u00010\u0003X\u0084\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0006\u0010\u0007\"\u0004\b\b\u0010\u0004R\u0011\u0010\t\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u0007R\u0013\u0010\u000b\u001a\u0004\u0018\u00010\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\u0007R\u0011\u0010\r\u001a\u00020\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u0011\u0010\u0011\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0007\u00a8\u0006\u0013"}, d2 = {"Lcom/amaze/filemanager/filesystem/ssh/SshConnectionPool$ConnectionInfo;", "", "url", "", "(Ljava/lang/String;)V", "defaultPath", "getDefaultPath", "()Ljava/lang/String;", "setDefaultPath", "host", "getHost", "password", "getPassword", "port", "", "getPort", "()I", "username", "getUsername", "app_fdroidDebug"})
    public static final class ConnectionInfo {
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String host = null;
        private final int port = 0;
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String username = null;
        @org.jetbrains.annotations.Nullable()
        private final java.lang.String password = null;
        @org.jetbrains.annotations.Nullable()
        private java.lang.String defaultPath;
        
        public ConnectionInfo(@org.jetbrains.annotations.NotNull()
        java.lang.String url) {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getHost() {
            return null;
        }
        
        public final int getPort() {
            return 0;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getUsername() {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.String getPassword() {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        protected final java.lang.String getDefaultPath() {
            return null;
        }
        
        protected final void setDefaultPath(@org.jetbrains.annotations.Nullable()
        java.lang.String p0) {
        }
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0011\n\u0002\b\u0005\u0018\u00002\u0014\u0012\u0004\u0012\u00020\u0002\u0012\u0004\u0012\u00020\u0002\u0012\u0004\u0012\u00020\u00020\u0001B\u0019\b\u0000\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\b\u0010\u0005\u001a\u0004\u0018\u00010\u0006\u00a2\u0006\u0002\u0010\u0007J!\u0010\b\u001a\u00020\u00022\u0012\u0010\t\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00020\n\"\u00020\u0002H\u0014\u00a2\u0006\u0002\u0010\u000bJ\u0015\u0010\f\u001a\u00020\u00022\u0006\u0010\r\u001a\u00020\u0002H\u0014\u00a2\u0006\u0002\u0010\u000eR\u0010\u0010\u0005\u001a\u0004\u0018\u00010\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u000f"}, d2 = {"Lcom/amaze/filemanager/filesystem/ssh/SshConnectionPool$AsyncRemoveConnection;", "Landroid/os/AsyncTask;", "", "url", "", "callback", "Ljava/lang/Runnable;", "(Ljava/lang/String;Ljava/lang/Runnable;)V", "doInBackground", "params", "", "([Lkotlin/Unit;)V", "onPostExecute", "aVoid", "(Lkotlin/Unit;)V", "app_fdroidDebug"})
    public static final class AsyncRemoveConnection extends android.os.AsyncTask<kotlin.Unit, kotlin.Unit, kotlin.Unit> {
        private java.lang.String url;
        private final java.lang.Runnable callback = null;
        
        public AsyncRemoveConnection(@org.jetbrains.annotations.NotNull()
        java.lang.String url, @org.jetbrains.annotations.Nullable()
        java.lang.Runnable callback) {
            super();
        }
        
        @java.lang.Override()
        protected void doInBackground(@org.jetbrains.annotations.NotNull()
        kotlin.Unit... params) {
        }
        
        @java.lang.Override()
        protected void onPostExecute(@org.jetbrains.annotations.NotNull()
        kotlin.Unit aVoid) {
        }
    }
    
    /**
     * Interface defining a factory class for creating [SSHClient] instances.
     *
     * In normal usage you won't need this; will be useful however when writing tests concerning
     * SSHClient, that mocked instances can be returned so tests can be run without a real SSH server.
     */
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\bf\u0018\u00002\u00020\u0001J\u0012\u0010\u0002\u001a\u00020\u00032\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005H&\u00a8\u0006\u0006"}, d2 = {"Lcom/amaze/filemanager/filesystem/ssh/SshConnectionPool$SSHClientFactory;", "", "create", "Lnet/schmizz/sshj/SSHClient;", "config", "Lnet/schmizz/sshj/Config;", "app_fdroidDebug"})
    public static abstract interface SSHClientFactory {
        
        /**
         * Implement this to return [SSHClient] instances.
         */
        @org.jetbrains.annotations.NotNull()
        public abstract net.schmizz.sshj.SSHClient create(@org.jetbrains.annotations.Nullable()
        net.schmizz.sshj.Config config);
    }
    
    /**
     * Default [SSHClientFactory] implementation.
     */
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\b\u0000\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0012\u0010\u0003\u001a\u00020\u00042\b\u0010\u0005\u001a\u0004\u0018\u00010\u0006H\u0016\u00a8\u0006\u0007"}, d2 = {"Lcom/amaze/filemanager/filesystem/ssh/SshConnectionPool$DefaultSSHClientFactory;", "Lcom/amaze/filemanager/filesystem/ssh/SshConnectionPool$SSHClientFactory;", "()V", "create", "Lnet/schmizz/sshj/SSHClient;", "config", "Lnet/schmizz/sshj/Config;", "app_fdroidDebug"})
    public static final class DefaultSSHClientFactory implements com.amaze.filemanager.filesystem.ssh.SshConnectionPool.SSHClientFactory {
        
        public DefaultSSHClientFactory() {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public net.schmizz.sshj.SSHClient create(@org.jetbrains.annotations.Nullable()
        net.schmizz.sshj.Config config) {
            return null;
        }
    }
}