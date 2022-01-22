// Generated by view binder compiler. Do not edit!
package com.amaze.filemanager.databinding;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
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

public final class SmbComputersRowBinding implements ViewBinding {
  @NonNull
  private final RelativeLayout rootView;

  @NonNull
  public final TextView firstline;

  @NonNull
  public final ImageView icon;

  @NonNull
  public final RelativeLayout second;

  @NonNull
  public final TextView secondLine;

  private SmbComputersRowBinding(@NonNull RelativeLayout rootView, @NonNull TextView firstline,
      @NonNull ImageView icon, @NonNull RelativeLayout second, @NonNull TextView secondLine) {
    this.rootView = rootView;
    this.firstline = firstline;
    this.icon = icon;
    this.second = second;
    this.secondLine = secondLine;
  }

  @Override
  @NonNull
  public RelativeLayout getRoot() {
    return rootView;
  }

  @NonNull
  public static SmbComputersRowBinding inflate(@NonNull LayoutInflater inflater) {
    return inflate(inflater, null, false);
  }

  @NonNull
  public static SmbComputersRowBinding inflate(@NonNull LayoutInflater inflater,
      @Nullable ViewGroup parent, boolean attachToParent) {
    View root = inflater.inflate(R.layout.smb_computers_row, parent, false);
    if (attachToParent) {
      parent.addView(root);
    }
    return bind(root);
  }

  @NonNull
  public static SmbComputersRowBinding bind(@NonNull View rootView) {
    // The body of this method is generated in a way you would not otherwise write.
    // This is done to optimize the compiled bytecode for size and performance.
    int id;
    missingId: {
      id = R.id.firstline;
      TextView firstline = rootView.findViewById(id);
      if (firstline == null) {
        break missingId;
      }

      id = R.id.icon;
      ImageView icon = rootView.findViewById(id);
      if (icon == null) {
        break missingId;
      }

      RelativeLayout second = (RelativeLayout) rootView;

      id = R.id.secondLine;
      TextView secondLine = rootView.findViewById(id);
      if (secondLine == null) {
        break missingId;
      }

      return new SmbComputersRowBinding((RelativeLayout) rootView, firstline, icon, second,
          secondLine);
    }
    String missingId = rootView.getResources().getResourceName(id);
    throw new NullPointerException("Missing required view with ID: ".concat(missingId));
  }
}
