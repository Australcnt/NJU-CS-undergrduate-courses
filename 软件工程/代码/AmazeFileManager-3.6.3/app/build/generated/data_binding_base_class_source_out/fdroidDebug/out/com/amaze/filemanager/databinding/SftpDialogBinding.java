// Generated by view binder compiler. Do not edit!
package com.amaze.filemanager.databinding;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.widget.AppCompatButton;
import androidx.appcompat.widget.AppCompatEditText;
import androidx.viewbinding.ViewBinding;
import com.amaze.filemanager.R;
import com.google.android.material.textfield.TextInputLayout;
import java.lang.NullPointerException;
import java.lang.Override;
import java.lang.String;

public final class SftpDialogBinding implements ViewBinding {
  @NonNull
  private final LinearLayout rootView;

  @NonNull
  public final AppCompatEditText connectionET;

  @NonNull
  public final TextInputLayout connectionTIL;

  @NonNull
  public final AppCompatEditText defaultPathET;

  @NonNull
  public final TextInputLayout defaultPathTIL;

  @NonNull
  public final AppCompatEditText ipET;

  @NonNull
  public final TextInputLayout ipTIL;

  @NonNull
  public final AppCompatEditText passwordET;

  @NonNull
  public final AppCompatEditText portET;

  @NonNull
  public final TextInputLayout portTIL;

  @NonNull
  public final AppCompatButton selectPemBTN;

  @NonNull
  public final AppCompatEditText usernameET;

  @NonNull
  public final TextInputLayout usernameTIL;

  private SftpDialogBinding(@NonNull LinearLayout rootView, @NonNull AppCompatEditText connectionET,
      @NonNull TextInputLayout connectionTIL, @NonNull AppCompatEditText defaultPathET,
      @NonNull TextInputLayout defaultPathTIL, @NonNull AppCompatEditText ipET,
      @NonNull TextInputLayout ipTIL, @NonNull AppCompatEditText passwordET,
      @NonNull AppCompatEditText portET, @NonNull TextInputLayout portTIL,
      @NonNull AppCompatButton selectPemBTN, @NonNull AppCompatEditText usernameET,
      @NonNull TextInputLayout usernameTIL) {
    this.rootView = rootView;
    this.connectionET = connectionET;
    this.connectionTIL = connectionTIL;
    this.defaultPathET = defaultPathET;
    this.defaultPathTIL = defaultPathTIL;
    this.ipET = ipET;
    this.ipTIL = ipTIL;
    this.passwordET = passwordET;
    this.portET = portET;
    this.portTIL = portTIL;
    this.selectPemBTN = selectPemBTN;
    this.usernameET = usernameET;
    this.usernameTIL = usernameTIL;
  }

  @Override
  @NonNull
  public LinearLayout getRoot() {
    return rootView;
  }

  @NonNull
  public static SftpDialogBinding inflate(@NonNull LayoutInflater inflater) {
    return inflate(inflater, null, false);
  }

  @NonNull
  public static SftpDialogBinding inflate(@NonNull LayoutInflater inflater,
      @Nullable ViewGroup parent, boolean attachToParent) {
    View root = inflater.inflate(R.layout.sftp_dialog, parent, false);
    if (attachToParent) {
      parent.addView(root);
    }
    return bind(root);
  }

  @NonNull
  public static SftpDialogBinding bind(@NonNull View rootView) {
    // The body of this method is generated in a way you would not otherwise write.
    // This is done to optimize the compiled bytecode for size and performance.
    int id;
    missingId: {
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

      id = R.id.defaultPathET;
      AppCompatEditText defaultPathET = rootView.findViewById(id);
      if (defaultPathET == null) {
        break missingId;
      }

      id = R.id.defaultPathTIL;
      TextInputLayout defaultPathTIL = rootView.findViewById(id);
      if (defaultPathTIL == null) {
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

      id = R.id.portET;
      AppCompatEditText portET = rootView.findViewById(id);
      if (portET == null) {
        break missingId;
      }

      id = R.id.portTIL;
      TextInputLayout portTIL = rootView.findViewById(id);
      if (portTIL == null) {
        break missingId;
      }

      id = R.id.selectPemBTN;
      AppCompatButton selectPemBTN = rootView.findViewById(id);
      if (selectPemBTN == null) {
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

      return new SftpDialogBinding((LinearLayout) rootView, connectionET, connectionTIL,
          defaultPathET, defaultPathTIL, ipET, ipTIL, passwordET, portET, portTIL, selectPemBTN,
          usernameET, usernameTIL);
    }
    String missingId = rootView.getResources().getResourceName(id);
    throw new NullPointerException("Missing required view with ID: ".concat(missingId));
  }
}
