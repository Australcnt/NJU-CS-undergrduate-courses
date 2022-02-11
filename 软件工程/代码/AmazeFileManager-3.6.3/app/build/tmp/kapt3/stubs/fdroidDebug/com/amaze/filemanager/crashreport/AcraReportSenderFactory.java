package com.amaze.filemanager.crashreport;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bH\u0016J\u0010\u0010\t\u001a\u00020\n2\u0006\u0010\u0007\u001a\u00020\bH\u0016\u00a8\u0006\u000b"}, d2 = {"Lcom/amaze/filemanager/crashreport/AcraReportSenderFactory;", "Lorg/acra/sender/ReportSenderFactory;", "()V", "create", "Lorg/acra/sender/ReportSender;", "context", "Landroid/content/Context;", "config", "Lorg/acra/config/CoreConfiguration;", "enabled", "", "app_fdroidDebug"})
public final class AcraReportSenderFactory implements org.acra.sender.ReportSenderFactory {
    
    public AcraReportSenderFactory() {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public org.acra.sender.ReportSender create(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    org.acra.config.CoreConfiguration config) {
        return null;
    }
    
    @java.lang.Override()
    public boolean enabled(@org.jetbrains.annotations.NotNull()
    org.acra.config.CoreConfiguration config) {
        return false;
    }
}