package com.amaze.filemanager.ui.dialogs;

import java.lang.System;

/**
 * SSH/SFTP connection setup dialog.
 */
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u0090\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u000b\u0018\u0000 =2\u00020\u0001:\u0002=>B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u001bH\u0002J \u0010\u001c\u001a\u00020\u001d2\u0006\u0010\u001e\u001a\u00020\u001f2\u0006\u0010 \u001a\u00020\u00042\u0006\u0010!\u001a\u00020\u001dH\u0002J\b\u0010\"\u001a\u00020\u001fH\u0002J\u0018\u0010#\u001a\u00020$2\u0006\u0010%\u001a\u00020\u001d2\u0006\u0010&\u001a\u00020\'H\u0002J\u008c\u0001\u0010(\u001av\u0012\f\u0012\n \n*\u0004\u0018\u00010*0*\u0012\f\u0012\n \n*\u0004\u0018\u00010*0*\u0012\u0018\u0012\u0016\u0012\u0004\u0012\u00020, \n*\n\u0012\u0004\u0012\u00020,\u0018\u00010+0+ \n*:\u0012\f\u0012\n \n*\u0004\u0018\u00010*0*\u0012\f\u0012\n \n*\u0004\u0018\u00010*0*\u0012\u0018\u0012\u0016\u0012\u0004\u0012\u00020, \n*\n\u0012\u0004\u0012\u00020,\u0018\u00010+0+\u0018\u00010)0)2\u0006\u0010\u001e\u001a\u00020\u001f2\u0006\u0010%\u001a\u00020\u001dH\u0002J\n\u0010-\u001a\u0004\u0018\u00010\u0004H\u0002J\u0010\u0010.\u001a\u00020/2\u0006\u0010%\u001a\u00020\u001dH\u0002J\u0010\u00100\u001a\u00020\u00192\u0006\u0010%\u001a\u00020\u001dH\u0002J\u0012\u00101\u001a\u0002022\b\u00103\u001a\u0004\u0018\u000104H\u0016J\b\u00105\u001a\u00020\u0019H\u0016J \u00106\u001a\u00020\u00192\u0006\u0010\u001e\u001a\u00020\u001f2\u0006\u00107\u001a\u00020\u00042\u0006\u0010%\u001a\u00020\u001dH\u0002J<\u00108\u001a\u00020\u001d2\u0006\u0010\u001e\u001a\u00020\u001f2\u0006\u0010 \u001a\u00020\u00042\u0006\u00109\u001a\u00020\u00042\u0006\u0010:\u001a\u00020\u00042\b\u0010\u0015\u001a\u0004\u0018\u00010\u00042\b\u0010\u0013\u001a\u0004\u0018\u00010\u0014H\u0002J(\u0010;\u001a\u00020\u001d2\u0006\u0010<\u001a\u00020\u00042\u0006\u0010 \u001a\u00020\u00042\u0006\u00109\u001a\u00020\u00042\u0006\u0010:\u001a\u00020\u0004H\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0005\u001a\u0004\u0018\u00010\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\"\u0010\u0007\u001a\u0010\u0012\f\u0012\n \n*\u0004\u0018\u00010\t0\t0\bX\u0082\u0004\u00a2\u0006\b\n\u0000\u0012\u0004\b\u000b\u0010\u0002R\u0014\u0010\f\u001a\u00020\u00068BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\r\u0010\u000eR\u0016\u0010\u000f\u001a\n\u0012\u0004\u0012\u00020\u0011\u0018\u00010\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0012\u001a\u0004\u0018\u00010\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0013\u001a\u0004\u0018\u00010\u0014X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0015\u001a\u0004\u0018\u00010\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0016\u001a\u0004\u0018\u00010\u0017X\u0082\u000e\u00a2\u0006\u0002\n\u0000\u00a8\u0006?"}, d2 = {"Lcom/amaze/filemanager/ui/dialogs/SftpConnectDialog;", "Landroidx/fragment/app/DialogFragment;", "()V", "TAG", "", "_binding", "Lcom/amaze/filemanager/databinding/SftpDialogBinding;", "activityResultHandler", "Landroidx/activity/result/ActivityResultLauncher;", "Landroid/content/Intent;", "kotlin.jvm.PlatformType", "getActivityResultHandler$annotations", "binding", "getBinding", "()Lcom/amaze/filemanager/databinding/SftpDialogBinding;", "ctx", "Ljava/lang/ref/WeakReference;", "Landroid/content/Context;", "oldPath", "selectedParsedKeyPair", "Ljava/security/KeyPair;", "selectedParsedKeyPairName", "selectedPem", "Landroid/net/Uri;", "appendButtonListenersForEdit", "", "dialogBuilder", "Lcom/afollestad/materialdialogs/MaterialDialog$Builder;", "authenticateAndSaveSetup", "", "connectionSettings", "Lcom/amaze/filemanager/ui/dialogs/SftpConnectDialog$ConnectionSettings;", "hostKeyFingerprint", "isEdit", "createConnectionSettings", "createValidator", "Lcom/amaze/filemanager/utils/SimpleTextWatcher;", "edit", "okBTN", "Lcom/afollestad/materialdialogs/internal/MDButton;", "firstConnectToServer", "Landroid/os/AsyncTask;", "Ljava/lang/Void;", "Lcom/amaze/filemanager/asynchronous/asynctasks/AsyncTaskResult;", "Ljava/security/PublicKey;", "getPemContents", "handleOnPositiveButton", "Lcom/afollestad/materialdialogs/MaterialDialog$SingleButtonCallback;", "initForm", "onCreateDialog", "Landroid/app/Dialog;", "savedInstanceState", "Landroid/os/Bundle;", "onDestroyView", "reconnectToServerToVerifyHostFingerprint", "sshHostKey", "saveSshConnection", "path", "encryptedPath", "updateSshConnection", "connectionName", "Companion", "ConnectionSettings", "app_fdroidDebug"})
public final class SftpConnectDialog extends androidx.fragment.app.DialogFragment {
    private final java.lang.String TAG = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.ui.dialogs.SftpConnectDialog.Companion Companion = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ARG_NAME = "name";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ARG_EDIT = "edit";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ARG_ADDRESS = "address";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ARG_PORT = "port";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ARG_USERNAME = "username";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ARG_PASSWORD = "password";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ARG_DEFAULT_PATH = "defaultPath";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ARG_HAS_PASSWORD = "hasPassword";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ARG_KEYPAIR_NAME = "keypairName";
    private static final kotlin.ranges.IntRange VALID_PORT_RANGE = null;
    private java.lang.ref.WeakReference<android.content.Context> ctx;
    private android.net.Uri selectedPem;
    private java.security.KeyPair selectedParsedKeyPair;
    private java.lang.String selectedParsedKeyPairName;
    private java.lang.String oldPath;
    private com.amaze.filemanager.databinding.SftpDialogBinding _binding;
    private final androidx.activity.result.ActivityResultLauncher<android.content.Intent> activityResultHandler = null;
    
    public SftpConnectDialog() {
        super();
    }
    
    private final com.amaze.filemanager.databinding.SftpDialogBinding getBinding() {
        return null;
    }
    
    @java.lang.Override()
    public void onDestroyView() {
    }
    
    @org.jetbrains.annotations.NotNull()
    @kotlin.Suppress(names = {"ComplexMethod"})
    @java.lang.Override()
    public android.app.Dialog onCreateDialog(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
        return null;
    }
    
    private final void initForm(boolean edit) {
    }
    
    private final void appendButtonListenersForEdit(com.afollestad.materialdialogs.MaterialDialog.Builder dialogBuilder) {
    }
    
    private final com.amaze.filemanager.utils.SimpleTextWatcher createValidator(boolean edit, com.afollestad.materialdialogs.internal.MDButton okBTN) {
        return null;
    }
    
    private final com.afollestad.materialdialogs.MaterialDialog.SingleButtonCallback handleOnPositiveButton(boolean edit) {
        return null;
    }
    
    private final android.os.AsyncTask<java.lang.Void, java.lang.Void, com.amaze.filemanager.asynchronous.asynctasks.AsyncTaskResult<java.security.PublicKey>> firstConnectToServer(com.amaze.filemanager.ui.dialogs.SftpConnectDialog.ConnectionSettings connectionSettings, boolean edit) {
        return null;
    }
    
    private final void reconnectToServerToVerifyHostFingerprint(com.amaze.filemanager.ui.dialogs.SftpConnectDialog.ConnectionSettings connectionSettings, java.lang.String sshHostKey, boolean edit) {
    }
    
    @kotlin.Suppress(names = {"LabeledExpression"})
    @java.lang.Deprecated()
    private static void getActivityResultHandler$annotations() {
    }
    
    private final boolean authenticateAndSaveSetup(com.amaze.filemanager.ui.dialogs.SftpConnectDialog.ConnectionSettings connectionSettings, java.lang.String hostKeyFingerprint, boolean isEdit) {
        return false;
    }
    
    private final boolean saveSshConnection(com.amaze.filemanager.ui.dialogs.SftpConnectDialog.ConnectionSettings connectionSettings, java.lang.String hostKeyFingerprint, java.lang.String path, java.lang.String encryptedPath, java.lang.String selectedParsedKeyPairName, java.security.KeyPair selectedParsedKeyPair) {
        return false;
    }
    
    private final boolean updateSshConnection(java.lang.String connectionName, java.lang.String hostKeyFingerprint, java.lang.String path, java.lang.String encryptedPath) {
        return false;
    }
    
    private final java.lang.String getPemContents() {
        return null;
    }
    
    private final com.amaze.filemanager.ui.dialogs.SftpConnectDialog.ConnectionSettings createConnectionSettings() {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0016\n\u0002\u0010\u000b\n\u0002\b\u0004\b\u0082\b\u0018\u00002\u00020\u0001BU\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\n\b\u0002\u0010\u0007\u001a\u0004\u0018\u00010\u0003\u0012\u0006\u0010\b\u001a\u00020\u0003\u0012\n\b\u0002\u0010\t\u001a\u0004\u0018\u00010\u0003\u0012\n\b\u0002\u0010\n\u001a\u0004\u0018\u00010\u0003\u0012\n\b\u0002\u0010\u000b\u001a\u0004\u0018\u00010\f\u00a2\u0006\u0002\u0010\rJ\t\u0010\u0019\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u001a\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u001b\u001a\u00020\u0006H\u00c6\u0003J\u000b\u0010\u001c\u001a\u0004\u0018\u00010\u0003H\u00c6\u0003J\t\u0010\u001d\u001a\u00020\u0003H\u00c6\u0003J\u000b\u0010\u001e\u001a\u0004\u0018\u00010\u0003H\u00c6\u0003J\u000b\u0010\u001f\u001a\u0004\u0018\u00010\u0003H\u00c6\u0003J\u000b\u0010 \u001a\u0004\u0018\u00010\fH\u00c6\u0003Ja\u0010!\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00032\b\b\u0002\u0010\u0005\u001a\u00020\u00062\n\b\u0002\u0010\u0007\u001a\u0004\u0018\u00010\u00032\b\b\u0002\u0010\b\u001a\u00020\u00032\n\b\u0002\u0010\t\u001a\u0004\u0018\u00010\u00032\n\b\u0002\u0010\n\u001a\u0004\u0018\u00010\u00032\n\b\u0002\u0010\u000b\u001a\u0004\u0018\u00010\fH\u00c6\u0001J\u0013\u0010\"\u001a\u00020#2\b\u0010$\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010%\u001a\u00020\u0006H\u00d6\u0001J\t\u0010&\u001a\u00020\u0003H\u00d6\u0001R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR\u0013\u0010\u0007\u001a\u0004\u0018\u00010\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u000fR\u0011\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u000fR\u0013\u0010\t\u001a\u0004\u0018\u00010\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u000fR\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\u0014R\u0013\u0010\u000b\u001a\u0004\u0018\u00010\f\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u0016R\u0013\u0010\n\u001a\u0004\u0018\u00010\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0017\u0010\u000fR\u0011\u0010\b\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0018\u0010\u000f\u00a8\u0006\'"}, d2 = {"Lcom/amaze/filemanager/ui/dialogs/SftpConnectDialog$ConnectionSettings;", "", "connectionName", "", "hostname", "port", "", "defaultPath", "username", "password", "selectedParsedKeyPairName", "selectedParsedKeyPair", "Ljava/security/KeyPair;", "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/security/KeyPair;)V", "getConnectionName", "()Ljava/lang/String;", "getDefaultPath", "getHostname", "getPassword", "getPort", "()I", "getSelectedParsedKeyPair", "()Ljava/security/KeyPair;", "getSelectedParsedKeyPairName", "getUsername", "component1", "component2", "component3", "component4", "component5", "component6", "component7", "component8", "copy", "equals", "", "other", "hashCode", "toString", "app_fdroidDebug"})
    static final class ConnectionSettings {
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String connectionName = null;
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String hostname = null;
        private final int port = 0;
        @org.jetbrains.annotations.Nullable()
        private final java.lang.String defaultPath = null;
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String username = null;
        @org.jetbrains.annotations.Nullable()
        private final java.lang.String password = null;
        @org.jetbrains.annotations.Nullable()
        private final java.lang.String selectedParsedKeyPairName = null;
        @org.jetbrains.annotations.Nullable()
        private final java.security.KeyPair selectedParsedKeyPair = null;
        
        @org.jetbrains.annotations.NotNull()
        public final com.amaze.filemanager.ui.dialogs.SftpConnectDialog.ConnectionSettings copy(@org.jetbrains.annotations.NotNull()
        java.lang.String connectionName, @org.jetbrains.annotations.NotNull()
        java.lang.String hostname, int port, @org.jetbrains.annotations.Nullable()
        java.lang.String defaultPath, @org.jetbrains.annotations.NotNull()
        java.lang.String username, @org.jetbrains.annotations.Nullable()
        java.lang.String password, @org.jetbrains.annotations.Nullable()
        java.lang.String selectedParsedKeyPairName, @org.jetbrains.annotations.Nullable()
        java.security.KeyPair selectedParsedKeyPair) {
            return null;
        }
        
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
        
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        public ConnectionSettings(@org.jetbrains.annotations.NotNull()
        java.lang.String connectionName, @org.jetbrains.annotations.NotNull()
        java.lang.String hostname, int port, @org.jetbrains.annotations.Nullable()
        java.lang.String defaultPath, @org.jetbrains.annotations.NotNull()
        java.lang.String username, @org.jetbrains.annotations.Nullable()
        java.lang.String password, @org.jetbrains.annotations.Nullable()
        java.lang.String selectedParsedKeyPairName, @org.jetbrains.annotations.Nullable()
        java.security.KeyPair selectedParsedKeyPair) {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String component1() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getConnectionName() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String component2() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getHostname() {
            return null;
        }
        
        public final int component3() {
            return 0;
        }
        
        public final int getPort() {
            return 0;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.String component4() {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.String getDefaultPath() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String component5() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getUsername() {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.String component6() {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.String getPassword() {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.String component7() {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.String getSelectedParsedKeyPairName() {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.security.KeyPair component8() {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.security.KeyPair getSelectedParsedKeyPair() {
            return null;
        }
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\t\n\u0002\u0018\u0002\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u00a8\u0006\u000f"}, d2 = {"Lcom/amaze/filemanager/ui/dialogs/SftpConnectDialog$Companion;", "", "()V", "ARG_ADDRESS", "", "ARG_DEFAULT_PATH", "ARG_EDIT", "ARG_HAS_PASSWORD", "ARG_KEYPAIR_NAME", "ARG_NAME", "ARG_PASSWORD", "ARG_PORT", "ARG_USERNAME", "VALID_PORT_RANGE", "Lkotlin/ranges/IntRange;", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}