// Generated by view binder compiler. Do not edit!
package com.amaze.filemanager.databinding;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CheckBox;
import android.widget.TableLayout;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.viewbinding.ViewBinding;
import com.amaze.filemanager.R;
import java.lang.NullPointerException;
import java.lang.Override;
import java.lang.String;

public final class PermissiontableBinding implements ViewBinding {
  @NonNull
  private final TableLayout rootView;

  @NonNull
  public final CheckBox cexegroup;

  @NonNull
  public final CheckBox cexeother;

  @NonNull
  public final CheckBox cexeown;

  @NonNull
  public final CheckBox creadgroup;

  @NonNull
  public final CheckBox creadother;

  @NonNull
  public final CheckBox creadown;

  @NonNull
  public final CheckBox cwritegroup;

  @NonNull
  public final CheckBox cwriteother;

  @NonNull
  public final CheckBox cwriteown;

  private PermissiontableBinding(@NonNull TableLayout rootView, @NonNull CheckBox cexegroup,
      @NonNull CheckBox cexeother, @NonNull CheckBox cexeown, @NonNull CheckBox creadgroup,
      @NonNull CheckBox creadother, @NonNull CheckBox creadown, @NonNull CheckBox cwritegroup,
      @NonNull CheckBox cwriteother, @NonNull CheckBox cwriteown) {
    this.rootView = rootView;
    this.cexegroup = cexegroup;
    this.cexeother = cexeother;
    this.cexeown = cexeown;
    this.creadgroup = creadgroup;
    this.creadother = creadother;
    this.creadown = creadown;
    this.cwritegroup = cwritegroup;
    this.cwriteother = cwriteother;
    this.cwriteown = cwriteown;
  }

  @Override
  @NonNull
  public TableLayout getRoot() {
    return rootView;
  }

  @NonNull
  public static PermissiontableBinding inflate(@NonNull LayoutInflater inflater) {
    return inflate(inflater, null, false);
  }

  @NonNull
  public static PermissiontableBinding inflate(@NonNull LayoutInflater inflater,
      @Nullable ViewGroup parent, boolean attachToParent) {
    View root = inflater.inflate(R.layout.permissiontable, parent, false);
    if (attachToParent) {
      parent.addView(root);
    }
    return bind(root);
  }

  @NonNull
  public static PermissiontableBinding bind(@NonNull View rootView) {
    // The body of this method is generated in a way you would not otherwise write.
    // This is done to optimize the compiled bytecode for size and performance.
    int id;
    missingId: {
      id = R.id.cexegroup;
      CheckBox cexegroup = rootView.findViewById(id);
      if (cexegroup == null) {
        break missingId;
      }

      id = R.id.cexeother;
      CheckBox cexeother = rootView.findViewById(id);
      if (cexeother == null) {
        break missingId;
      }

      id = R.id.cexeown;
      CheckBox cexeown = rootView.findViewById(id);
      if (cexeown == null) {
        break missingId;
      }

      id = R.id.creadgroup;
      CheckBox creadgroup = rootView.findViewById(id);
      if (creadgroup == null) {
        break missingId;
      }

      id = R.id.creadother;
      CheckBox creadother = rootView.findViewById(id);
      if (creadother == null) {
        break missingId;
      }

      id = R.id.creadown;
      CheckBox creadown = rootView.findViewById(id);
      if (creadown == null) {
        break missingId;
      }

      id = R.id.cwritegroup;
      CheckBox cwritegroup = rootView.findViewById(id);
      if (cwritegroup == null) {
        break missingId;
      }

      id = R.id.cwriteother;
      CheckBox cwriteother = rootView.findViewById(id);
      if (cwriteother == null) {
        break missingId;
      }

      id = R.id.cwriteown;
      CheckBox cwriteown = rootView.findViewById(id);
      if (cwriteown == null) {
        break missingId;
      }

      return new PermissiontableBinding((TableLayout) rootView, cexegroup, cexeother, cexeown,
          creadgroup, creadother, creadown, cwritegroup, cwriteother, cwriteown);
    }
    String missingId = rootView.getResources().getResourceName(id);
    throw new NullPointerException("Missing required view with ID: ".concat(missingId));
  }
}
