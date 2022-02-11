package com.amaze.filemanager.crashreport;

import java.lang.System;

@kotlin.Metadata(mv = {1, 5, 1}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0003\u001a\u00020\u0004H\u0016J\u0018\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0016\u00a8\u0006\u000b"}, d2 = {"Lcom/amaze/filemanager/crashreport/AcraReportSender;", "Lorg/acra/sender/ReportSender;", "()V", "requiresForeground", "", "send", "", "context", "Landroid/content/Context;", "errorContent", "Lorg/acra/data/CrashReportData;", "app_fdroidDebug"})
public final class AcraReportSender implements org.acra.sender.ReportSender {
    
    public AcraReportSender() {
        super();
    }
    
    @java.lang.Override()
    public void send(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    org.acra.data.CrashReportData errorContent) {
    }
    
    @java.lang.Override()
    public boolean requiresForeground() {
        return false;
    }
}