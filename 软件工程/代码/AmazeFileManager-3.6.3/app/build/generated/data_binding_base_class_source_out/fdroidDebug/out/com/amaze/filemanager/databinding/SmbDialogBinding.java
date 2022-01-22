// Generated by view binder compiler. Do not edit!
package com.amaze.filemanager.databinding;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.widget.AppCompatCheckBox;
import androidx.appcompat.widget.AppCompatEditText;
import androidx.viewbinding.ViewBinding;
import com.amaze.filemanager.R;
import com.google.android.material.textfield.TextInputLayout;
import java.lang.NullPointerException;
import java.lang.Override;
import java.lang.String;

public final class SmbDialogBinding implements ViewBinding {
  @NonNull
  private final LinearLayout rootView;

  @NonNull
  public final AppCompatCheckBox chkSmbAnonymous;

  @NonNull
  public final AppCompatCheckBox chkSmbDisableIpcSignature;

  @NonNull
  public final AppCompatEditText connectionET;

  @NonNull
  public final TextInputLayout connectionTIL;

  @NonNull
  public final AppCompatEditText domainET;

  @NonNull
  public final TextInputLayout domainTIL;

  @NonNull
  public final AppCompatEditText ipET;

  @NonNull
  public final TextInputLayout ipTIL;

  @NonNull
  public final AppCompatEditText passwordET;

  @NonNull
  public final TextInputLayout passwordTIL;

  @NonNull
  public final AppCompatEditText shareET;

  @NonNull
  public final TextInputLayout shareTIL;

  @NonNull
  public final AppCompatEditText usernameET;

  @NonNull
  public final TextInputLayout usernameTIL;

  @NonNull
  public final TextView wanthelp;

  private SmbDialogBinding(@NonNull LinearLayout rootView,
      @NonNull AppCompatCheckBox chkSmbAnonymous,
      @NonNull AppCompatCheckBox chkSmbDisableIpcSignature, @NonNull AppCompatEditText connectionET,
      @NonNull TextInputLayout connectionTIL, @NonNull AppCompatEditText domainET,
      @NonNull TextInputLayout domainTIL, @NonNull AppCompatEditText ipET,
      @NonNull TextInputLayout ipTIL, @NonNull AppCompatEditText passwordET,
      @NonNull TextInputLayout passwordTIL, @NonNull AppCompatEditText shareET,
      @NonNull TextInputLayout shareTIL, @NonNull AppCompatEditText usernameET,
      @NonNull TextInputLayout usernameTIL, @NonNull TextView wanthelp) {
    this.rootView = rootView;
    this.chkSmbAnonymous = chkSmbAnonymous;
    this.chkSmbDisableIpcSignature = chkSmbDisableIpcSignature;
    this.connectionET = connectionET;
    this.connectionTIL = connectionTIL;
    this.domainET = domainET;
    this.domainTIL = domainTIL;
    this.ipET = ipET;
    this.ipTIL = ipTIL;
    this.passwordET = passwordET;
    this.passwordTIL = passwordTIL;
    this.shareET = shareET;
    this.shareTIL = shareTIL;
    this.usernameET = usernameET;
    this.usernameTIL = usernameTIL;
    this.wanthelp = wanthelp;
  }

  @Override
  @NonNull
  public LinearLayout getRoot() {
    return rootView;
  }

  @NonNull
  public static SmbDialogBinding inflate(@NonNull LayoutInflater inflater) {
    return inflate(inflater, null, false);
  }

  @NonNull
  public static SmbDialogBinding inflate(@NonNull LayoutInflater inflater,
      @Nullable ViewGroup parent, boolean attachToParent) {
    View root = inflater.inflate(R.layout.smb_dialog, parent, false);
    if (attachToParent) {
      parent.addView(root);
    }
    return bind(root);
  }

  @NonNull
  public static SmbDialogBinding bind(@NonNull View rootView) {
    // The body of this method is generated in a way you would not otherwise write.
    // This is done to optimize the compiled bytecode for size and performance.
    int id;
    missingId: {
      id = R.id.chkSmbAnonymous;
      AppCompatCheckBox chkSmbAnonymous = rootView.findViewById(id);
      if (chkSmbAnonymous == null) {
        break missingId;
      }

      id = R.id.chkSmbDisableIpcSignature;
      AppCompatCheckBox chkSmbDisableIpcSignature = rootView.findViewById(id);
      if (chkSmbDisableIpcSignature == null) {
        break missingId;
      }

      id = R.id.connectionET;
      AppCompatEditText connectionET = rootView.findViewById(id);
      if (connectionET == null) {
        break missingId;
      }

      id = R.id.connectionTIL;
      TextInputLayout connectionTIL = rootView.findViewById(id);
      if (connectionTIL == null) {
        break missingId;
      }

      id = R.id.domainET;
      AppCompatEditText domainET = rootView.findViewById(id);
      if (domainET == null) {
        break missingId;
      }

      id = R.id.domainTIL;
      TextInputLayout domainTIL = rootView.findViewById(id);
      if (domainTIL == null) {
        break missingId;
      }

      id = R.id.ipET;
      AppCompatEditText ipET = rootView.findViewById(id);
      if (ipET == null) {
        break missingId;
      }

      id = R.id.ipTIL;
      TextInputLayout ipTIL = rootView.findViewById(id);
      if (ipTIL == null) {
        break missingId;
      }

      id = R.id.passwordET;
      AppCompatEditText passwordET = rootView.findViewById(id);
      if (passwordET == null) {
        break missingId;
      }

      id = R.id.passwordTIL;
      TextInputLayout passwordTIL = rootView.findViewById(id);
      if (passwordTIL == null) {
        break missingId;
      }

      id = R.id.shareET;
      AppCompatEditText shareET = rootView.findViewById(id);
      if (shareET == null) {
        break missingId;
      }

      id = R.id.shareTIL;
      TextInputLayout shareTIL = rootView.findViewById(id);
      if (shareTIL == null) {
        break missingId;
      }

      id = R.id.usernameET;
      AppCompatEditText usernameET = rootView.findViewById(id);
      if (usernameET == null) {
        break missingId;
      }

      id = R.id.usernameTIL;
      TextInputLayout usernameTIL = rootView.findViewById(id);
      if (usernameTIL == null) {
        break missingId;
      }

      id = R.id.wanthelp;
      TextView wanthelp = rootView.findViewById(id);
      if (wanthelp == null) {
        break missingId;
      }

      return new SmbDialogBinding((LinearLayout) rootView, chkSmbAnonymous,
          chkSmbDisableIpcSignature, connectionET, connectionTIL, domainET, domainTIL, ipET, ipTIL,
          passwordET, passwordTIL, shareET, shareTIL, usernameET, usernameTIL, wanthelp);
    }
    String missingId = rootView.getResources().getResourceName(id);
    throw new NullPointerException("Missing required view with ID: ".concat(missingId));
  }
}
