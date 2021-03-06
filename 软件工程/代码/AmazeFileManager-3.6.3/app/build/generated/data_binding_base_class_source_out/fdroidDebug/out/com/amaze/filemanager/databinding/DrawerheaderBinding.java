// Generated by view binder compiler. Do not edit!
package com.amaze.filemanager.databinding;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.viewbinding.ViewBinding;
import com.amaze.filemanager.R;
import java.lang.NullPointerException;
import java.lang.Override;
import java.lang.String;

public final class DrawerheaderBinding implements ViewBinding {
  @NonNull
  private final FrameLayout rootView;

  @NonNull
  public final TextView appVersion;

  @NonNull
  public final ImageView donate;

  @NonNull
  public final View drawerHeader;

  @NonNull
  public final RelativeLayout drawerHeaderParent;

  @NonNull
  public final ImageView telegram;

  private DrawerheaderBinding(@NonNull FrameLayout rootView, @NonNull TextView appVersion,
      @NonNull ImageView donate, @NonNull View drawerHeader,
      @NonNull RelativeLayout drawerHeaderParent, @NonNull ImageView telegram) {
    this.rootView = rootView;
    this.appVersion = appVersion;
    this.donate = donate;
    this.drawerHeader = drawerHeader;
    this.drawerHeaderParent = drawerHeaderParent;
    this.telegram = telegram;
  }

  @Override
  @NonNull
  public FrameLayout getRoot() {
    return rootView;
  }

  @NonNull
  public static DrawerheaderBinding inflate(@NonNull LayoutInflater inflater) {
    return inflate(inflater, null, false);
  }

  @NonNull
  public static DrawerheaderBinding inflate(@NonNull LayoutInflater inflater,
      @Nullable ViewGroup parent, boolean attachToParent) {
    View root = inflater.inflate(R.layout.drawerheader, parent, false);
    if (attachToParent) {
      parent.addView(root);
    }
    return bind(root);
  }

  @NonNull
  public static DrawerheaderBinding bind(@NonNull View rootView) {
    // The body of this method is generated in a way you would not otherwise write.
    // This is done to optimize the compiled bytecode for size and performance.
    int id;
    missingId: {
      id = R.id.app_version;
      TextView appVersion = rootView.findViewById(id);
      if (appVersion == null) {
        break missingId;
      }

      id = R.id.donate;
      ImageView donate = rootView.findViewById(id);
      if (donate == null) {
        break missingId;
      }

      id = R.id.drawer_header;
      View drawerHeader = rootView.findViewById(id);
      if (drawerHeader == null) {
        break missingId;
      }

      id = R.id.drawer_header_parent;
      RelativeLayout drawerHeaderParent = rootView.findViewById(id);
      if (drawerHeaderParent == null) {
        break missingId;
      }

      id = R.id.telegram;
      ImageView telegram = rootView.findViewById(id);
      if (telegram == null) {
        break missingId;
      }

      return new DrawerheaderBinding((FrameLayout) rootView, appVersion, donate, drawerHeader,
          drawerHeaderParent, telegram);
    }
    String missingId = rootView.getResources().getResourceName(id);
    throw new NullPointerException("Missing required view with ID: ".concat(missingId));
  }
}
