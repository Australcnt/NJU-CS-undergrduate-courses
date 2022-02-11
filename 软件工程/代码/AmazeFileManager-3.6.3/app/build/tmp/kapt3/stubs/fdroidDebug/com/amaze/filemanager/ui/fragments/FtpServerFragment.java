package com.amaze.filemanager.ui.fragments;

import java.lang.System;

/**
 * Created by yashwanthreddyg on 10-06-2016. Edited by Luca D'Amico (Luca91) on 25 Jul 2017 (Fixed
 * FTP Server while usi
 */
@kotlin.Suppress(names = {"TooManyFunctions"})
@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u00c4\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000e\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0010\u000b\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0011\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\r\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0010\u0018\u0000 \u0089\u00012\u00020\u0001:\u0002\u0089\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010S\u001a\u00020T2\u0006\u0010U\u001a\u00020\u000fJ\u0010\u0010V\u001a\u00020T2\u0006\u00107\u001a\u00020\u0006H\u0002J\u0016\u0010W\u001a\u00020T2\f\u0010X\u001a\b\u0012\u0004\u0012\u00020T0YH\u0002J1\u0010Z\u001a\b\u0012\u0004\u0012\u00020\t0\b2!\u0010X\u001a\u001d\u0012\u0013\u0012\u00110\\\u00a2\u0006\f\b]\u0012\b\b^\u0012\u0004\b\b(_\u0012\u0004\u0012\u00020T0[H\u0002J\u000f\u0010`\u001a\u0004\u0018\u00010TH\u0002\u00a2\u0006\u0002\u0010aJ\b\u0010b\u001a\u00020TH\u0002J\b\u0010c\u001a\u00020TH\u0002J\u0010\u0010d\u001a\u00020T2\u0006\u0010e\u001a\u00020fH\u0002J\u0012\u0010g\u001a\u00020T2\b\u0010h\u001a\u0004\u0018\u00010iH\u0016J\u0018\u0010j\u001a\u00020T2\u0006\u0010k\u001a\u00020l2\u0006\u0010m\u001a\u00020nH\u0016J$\u0010o\u001a\u00020p2\u0006\u0010m\u001a\u00020q2\b\u0010r\u001a\u0004\u0018\u00010s2\b\u0010h\u001a\u0004\u0018\u00010iH\u0016J\b\u0010t\u001a\u00020TH\u0016J\u0010\u0010u\u001a\u00020T2\u0006\u0010v\u001a\u00020wH\u0007J\u0010\u0010x\u001a\u00020%2\u0006\u0010y\u001a\u00020zH\u0016J\b\u0010{\u001a\u00020TH\u0016J\b\u0010|\u001a\u00020TH\u0016J\u0010\u0010}\u001a\u00020\u000f2\u0006\u0010U\u001a\u00020\u000fH\u0002J\b\u0010~\u001a\u00020TH\u0002J\b\u0010\u007f\u001a\u00020TH\u0002J\u0011\u0010\u0080\u0001\u001a\u00020T2\u0006\u00101\u001a\u00020\u000fH\u0002J\u0011\u0010\u0081\u0001\u001a\u00020T2\u0006\u0010O\u001a\u00020\u000fH\u0002J\t\u0010\u0082\u0001\u001a\u00020%H\u0002J\t\u0010\u0083\u0001\u001a\u00020TH\u0002J\t\u0010\u0084\u0001\u001a\u00020TH\u0002J\t\u0010\u0085\u0001\u001a\u00020TH\u0002J\t\u0010\u0086\u0001\u001a\u00020TH\u0002J\t\u0010\u0087\u0001\u001a\u00020TH\u0002J\u0019\u0010\u0088\u0001\u001a\u00020T2\u0006\u0010-\u001a\u00020.2\u0006\u0010\u000b\u001a\u00020\u0004H\u0002R\u0010\u0010\u0003\u001a\u0004\u0018\u00010\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\t0\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\n\u001a\b\u0012\u0004\u0012\u00020\t0\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u000b\u001a\u00020\u00048BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\f\u0010\rR\u0014\u0010\u000e\u001a\u00020\u000f8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0010\u0010\u0011R\u0014\u0010\u0012\u001a\u00020\u00068BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0013\u0010\u0014R\u0016\u0010\u0015\u001a\u0004\u0018\u00010\u000f8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0016\u0010\u0011R\u0014\u0010\u0017\u001a\u00020\u00188BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0019\u0010\u001aR\u0014\u0010\u001b\u001a\u00020\u001c8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u001d\u0010\u001eR$\u0010 \u001a\u00020\u00062\u0006\u0010\u001f\u001a\u00020\u00068B@BX\u0082\u000e\u00a2\u0006\f\u001a\u0004\b!\u0010\u0014\"\u0004\b\"\u0010#R$\u0010&\u001a\u00020%2\u0006\u0010$\u001a\u00020%8B@BX\u0082\u000e\u00a2\u0006\f\u001a\u0004\b\'\u0010(\"\u0004\b)\u0010*R\u000e\u0010+\u001a\u00020,X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010-\u001a\u00020.8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b/\u00100R\u0014\u00101\u001a\u0002028BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b3\u00104R\u0016\u00105\u001a\u0004\u0018\u00010\u000f8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b6\u0010\u0011R\u0014\u00107\u001a\u0002028BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b8\u00104R$\u0010:\u001a\u00020%2\u0006\u00109\u001a\u00020%8B@BX\u0082\u000e\u00a2\u0006\f\u001a\u0004\b;\u0010(\"\u0004\b<\u0010*R$\u0010>\u001a\u00020%2\u0006\u0010=\u001a\u00020%8B@BX\u0082\u000e\u00a2\u0006\f\u001a\u0004\b?\u0010(\"\u0004\b@\u0010*R\u0014\u0010A\u001a\u0002028BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\bB\u00104R\u0010\u0010C\u001a\u0004\u0018\u00010DX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010E\u001a\u0004\u0018\u00010FX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010G\u001a\u0004\u0018\u00010FX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010H\u001a\u0004\u0018\u00010FX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010I\u001a\u0004\u0018\u00010FX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010J\u001a\u0004\u0018\u00010FX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010K\u001a\u0002028BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\bL\u00104R\u0014\u0010M\u001a\u0002028BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\bN\u00104R\u0014\u0010O\u001a\u0002028BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\bP\u00104R\u0014\u0010Q\u001a\u00020\u000f8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\bR\u0010\u0011\u00a8\u0006\u008a\u0001"}, d2 = {"Lcom/amaze/filemanager/ui/fragments/FtpServerFragment;", "Landroidx/fragment/app/Fragment;", "()V", "_binding", "Lcom/amaze/filemanager/databinding/FragmentFtpBinding;", "accentColor", "", "activityResultHandlerOnFtpServerPathGrantedSafAccess", "Landroidx/activity/result/ActivityResultLauncher;", "Landroid/content/Intent;", "activityResultHandlerOnFtpServerPathUpdate", "binding", "getBinding", "()Lcom/amaze/filemanager/databinding/FragmentFtpBinding;", "defaultPathFromPreferences", "", "getDefaultPathFromPreferences", "()Ljava/lang/String;", "defaultPortFromPreferences", "getDefaultPortFromPreferences", "()I", "ftpAddressString", "getFtpAddressString", "ftpBtn", "Landroid/widget/Button;", "getFtpBtn", "()Landroid/widget/Button;", "ftpPasswordVisibleButton", "Landroid/widget/ImageButton;", "getFtpPasswordVisibleButton", "()Landroid/widget/ImageButton;", "seconds", "ftpTimeout", "getFtpTimeout", "setFtpTimeout", "(I)V", "useSafFileSystem", "", "legacyFileSystemPreference", "getLegacyFileSystemPreference", "()Z", "setLegacyFileSystemPreference", "(Z)V", "mWifiReceiver", "Landroid/content/BroadcastReceiver;", "mainActivity", "Lcom/amaze/filemanager/ui/activities/MainActivity;", "getMainActivity", "()Lcom/amaze/filemanager/ui/activities/MainActivity;", "password", "Landroid/widget/TextView;", "getPassword", "()Landroid/widget/TextView;", "passwordFromPreferences", "getPasswordFromPreferences", "port", "getPort", "isReadonly", "readonlyPreference", "getReadonlyPreference", "setReadonlyPreference", "isSecureEnabled", "securePreference", "getSecurePreference", "setSecurePreference", "sharedPath", "getSharedPath", "snackbar", "Lcom/google/android/material/snackbar/Snackbar;", "spannedStatusConnected", "Landroid/text/Spanned;", "spannedStatusNoConnection", "spannedStatusNotRunning", "spannedStatusSecure", "spannedStatusUrl", "statusText", "getStatusText", "url", "getUrl", "username", "getUsername", "usernameFromPreferences", "getUsernameFromPreferences", "changeFTPServerPath", "", "path", "changeFTPServerPort", "checkUriAccessIfNecessary", "callback", "Lkotlin/Function0;", "createOpenDocumentTreeIntentCallback", "Lkotlin/Function1;", "Landroid/net/Uri;", "Lkotlin/ParameterName;", "name", "directoryUri", "dismissSnackbar", "()Lkotlin/Unit;", "doStartServer", "ftpBtnOnClick", "initLoginDialogViews", "loginDialogView", "Lcom/amaze/filemanager/databinding/DialogFtpLoginBinding;", "onCreate", "savedInstanceState", "Landroid/os/Bundle;", "onCreateOptionsMenu", "menu", "Landroid/view/Menu;", "inflater", "Landroid/view/MenuInflater;", "onCreateView", "Landroid/view/View;", "Landroid/view/LayoutInflater;", "container", "Landroid/view/ViewGroup;", "onDestroyView", "onFtpReceiveActions", "signal", "Lcom/amaze/filemanager/asynchronous/services/ftp/FtpService$FtpReceiverActions;", "onOptionsItemSelected", "item", "Landroid/view/MenuItem;", "onPause", "onResume", "pathToDisplayString", "promptUserToEnableWireless", "promptUserToRestartServer", "setFTPPassword", "setFTPUsername", "shouldUseSafFileSystem", "startServer", "stopServer", "updatePathText", "updateSpans", "updateStatus", "updateViews", "Companion", "app_fdroidDebug"})
public final class FtpServerFragment extends androidx.fragment.app.Fragment {
    private int accentColor = 0;
    private android.text.Spanned spannedStatusNoConnection;
    private android.text.Spanned spannedStatusConnected;
    private android.text.Spanned spannedStatusUrl;
    private android.text.Spanned spannedStatusSecure;
    private android.text.Spanned spannedStatusNotRunning;
    private com.google.android.material.snackbar.Snackbar snackbar;
    private com.amaze.filemanager.databinding.FragmentFtpBinding _binding;
    private final androidx.activity.result.ActivityResultLauncher<android.content.Intent> activityResultHandlerOnFtpServerPathUpdate = null;
    private final androidx.activity.result.ActivityResultLauncher<android.content.Intent> activityResultHandlerOnFtpServerPathGrantedSafAccess = null;
    private final android.content.BroadcastReceiver mWifiReceiver = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.amaze.filemanager.ui.fragments.FtpServerFragment.Companion Companion = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String TAG = "FtpServerFragment";
    public static final int REQUEST_CODE_SAF_FTP = 225;
    public static final int GRANT_URI_RW_PERMISSION = 3;
    
    public FtpServerFragment() {
        super();
    }
    
    private final android.widget.TextView getStatusText() {
        return null;
    }
    
    private final android.widget.TextView getUrl() {
        return null;
    }
    
    private final android.widget.TextView getUsername() {
        return null;
    }
    
    private final android.widget.TextView getPassword() {
        return null;
    }
    
    private final android.widget.TextView getPort() {
        return null;
    }
    
    private final android.widget.TextView getSharedPath() {
        return null;
    }
    
    private final android.widget.Button getFtpBtn() {
        return null;
    }
    
    private final android.widget.ImageButton getFtpPasswordVisibleButton() {
        return null;
    }
    
    private final com.amaze.filemanager.databinding.FragmentFtpBinding getBinding() {
        return null;
    }
    
    private final com.amaze.filemanager.ui.activities.MainActivity getMainActivity() {
        return null;
    }
    
    @java.lang.Override()
    public void onCreate(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
    }
    
    @java.lang.Override()
    public void onDestroyView() {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.view.View onCreateView(@org.jetbrains.annotations.NotNull()
    android.view.LayoutInflater inflater, @org.jetbrains.annotations.Nullable()
    android.view.ViewGroup container, @org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
        return null;
    }
    
    private final void ftpBtnOnClick() {
    }
    
    @kotlin.Suppress(names = {"ComplexMethod", "LongMethod"})
    @java.lang.Override()
    public boolean onOptionsItemSelected(@org.jetbrains.annotations.NotNull()
    android.view.MenuItem item) {
        return false;
    }
    
    @java.lang.Override()
    public void onCreateOptionsMenu(@org.jetbrains.annotations.NotNull()
    android.view.Menu menu, @org.jetbrains.annotations.NotNull()
    android.view.MenuInflater inflater) {
    }
    
    private final boolean shouldUseSafFileSystem() {
        return false;
    }
    
    /**
     * Handles messages sent from [EventBus].
     *
     * @param signal as [FtpReceiverActions]
     */
    @kotlin.Suppress(names = {"StringLiteralDuplication"})
    @org.greenrobot.eventbus.Subscribe(threadMode = org.greenrobot.eventbus.ThreadMode.MAIN_ORDERED)
    public final void onFtpReceiveActions(@org.jetbrains.annotations.NotNull()
    com.amaze.filemanager.asynchronous.services.ftp.FtpService.FtpReceiverActions signal) {
    }
    
    @kotlin.Suppress(names = {"LabeledExpression"})
    private final androidx.activity.result.ActivityResultLauncher<android.content.Intent> createOpenDocumentTreeIntentCallback(kotlin.jvm.functions.Function1<? super android.net.Uri, kotlin.Unit> callback) {
        return null;
    }
    
    /**
     * Check URI access. Prompt user to DocumentsUI if necessary
     */
    private final void checkUriAccessIfNecessary(kotlin.jvm.functions.Function0<kotlin.Unit> callback) {
    }
    
    /**
     * Sends a broadcast to start ftp server
     */
    private final void startServer() {
    }
    
    /**
     * Sends a broadcast to stop ftp server
     */
    private final void stopServer() {
    }
    
    private final void doStartServer() {
    }
    
    @java.lang.Override()
    public void onResume() {
    }
    
    @java.lang.Override()
    public void onPause() {
    }
    
    /**
     * Update UI widgets after change in shared preferences
     */
    private final void updateStatus() {
    }
    
    private final void updatePathText() {
    }
    
    /**
     * Updates the status spans
     */
    private final void updateSpans() {
    }
    
    private final void initLoginDialogViews(com.amaze.filemanager.databinding.DialogFtpLoginBinding loginDialogView) {
    }
    
    private final void updateViews(com.amaze.filemanager.ui.activities.MainActivity mainActivity, com.amaze.filemanager.databinding.FragmentFtpBinding binding) {
    }
    
    private final java.lang.String getFtpAddressString() {
        return null;
    }
    
    private final int getDefaultPortFromPreferences() {
        return 0;
    }
    
    private final java.lang.String getUsernameFromPreferences() {
        return null;
    }
    
    private final java.lang.String getPasswordFromPreferences() {
        return null;
    }
    
    private final java.lang.String getDefaultPathFromPreferences() {
        return null;
    }
    
    private final java.lang.String pathToDisplayString(java.lang.String path) {
        return null;
    }
    
    private final void changeFTPServerPort(int port) {
    }
    
    /**
     * Update FTP server shared path in [android.content.SharedPreferences].
     *
     * @param path new shared path. Can be either absolute path (pre 4.4) or URI, which can be
     * <code>file:///</code> or <code>content://</code> as prefix
     */
    public final void changeFTPServerPath(@org.jetbrains.annotations.NotNull()
    java.lang.String path) {
    }
    
    private final void setFTPUsername(java.lang.String username) {
    }
    
    private final void setFTPPassword(java.lang.String password) {
    }
    
    private final int getFtpTimeout() {
        return 0;
    }
    
    private final void setFtpTimeout(int seconds) {
    }
    
    private final boolean getSecurePreference() {
        return false;
    }
    
    private final void setSecurePreference(boolean isSecureEnabled) {
    }
    
    private final boolean getReadonlyPreference() {
        return false;
    }
    
    private final void setReadonlyPreference(boolean isReadonly) {
    }
    
    private final boolean getLegacyFileSystemPreference() {
        return false;
    }
    
    private final void setLegacyFileSystemPreference(boolean useSafFileSystem) {
    }
    
    private final void promptUserToRestartServer() {
    }
    
    private final void promptUserToEnableWireless() {
    }
    
    private final kotlin.Unit dismissSnackbar() {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0086T\u00a2\u0006\u0002\n\u0000\u00a8\u0006\b"}, d2 = {"Lcom/amaze/filemanager/ui/fragments/FtpServerFragment$Companion;", "", "()V", "GRANT_URI_RW_PERMISSION", "", "REQUEST_CODE_SAF_FTP", "TAG", "", "app_fdroidDebug"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}