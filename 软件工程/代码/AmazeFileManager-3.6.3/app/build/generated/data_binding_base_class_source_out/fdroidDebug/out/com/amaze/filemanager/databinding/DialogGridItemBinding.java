// Generated by view binder compiler. Do not edit!
package com.amaze.filemanager.databinding;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.viewbinding.ViewBinding;
import com.amaze.filemanager.R;
import com.amaze.filemanager.ui.views.CheckableCircleView;
import java.lang.NullPointerException;
import java.lang.Override;

public final class DialogGridItemBinding implements ViewBinding {
  @NonNull
  private final CheckableCircleView rootView;

  @NonNull
  public final CheckableCircleView icon;

  private DialogGridItemBinding(@NonNull CheckableCircleView rootView,
      @NonNull CheckableCircleView icon) {
    this.rootView = rootView;
    this.icon = icon;
  }

  @Override
  @NonNull
  public CheckableCircleView getRoot() {
    return rootView;
  }

  @NonNull
  public static DialogGridItemBinding inflate(@NonNull LayoutInflater inflater) {
    return inflate(inflater, null, false);
  }

  @NonNull
  public static DialogGridItemBinding inflate(@NonNull LayoutInflater inflater,
      @Nullable ViewGroup parent, boolean attachToParent) {
    View root = inflater.inflate(R.layout.dialog_grid_item, parent, false);
    if (attachToParent) {
      parent.addView(root);
    }
    return bind(root);
  }

  @NonNull
  public static DialogGridItemBinding bind(@NonNull View rootView) {
    if (rootView == null) {
      throw new NullPointerException("rootView");
    }

    CheckableCircleView icon = (CheckableCircleView) rootView;

    return new DialogGridItemBinding((CheckableCircleView) rootView, icon);
  }
}
