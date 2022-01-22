// Generated by view binder compiler. Do not edit!
package com.amaze.filemanager.databinding;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.viewbinding.ViewBinding;
import com.amaze.filemanager.R;
import java.lang.NullPointerException;
import java.lang.Override;

public final class LayoutDraweractionviewBinding implements ViewBinding {
  @NonNull
  private final ImageButton rootView;

  @NonNull
  public final ImageButton imageButton;

  private LayoutDraweractionviewBinding(@NonNull ImageButton rootView,
      @NonNull ImageButton imageButton) {
    this.rootView = rootView;
    this.imageButton = imageButton;
  }

  @Override
  @NonNull
  public ImageButton getRoot() {
    return rootView;
  }

  @NonNull
  public static LayoutDraweractionviewBinding inflate(@NonNull LayoutInflater inflater) {
    return inflate(inflater, null, false);
  }

  @NonNull
  public static LayoutDraweractionviewBinding inflate(@NonNull LayoutInflater inflater,
      @Nullable ViewGroup parent, boolean attachToParent) {
    View root = inflater.inflate(R.layout.layout_draweractionview, parent, false);
    if (attachToParent) {
      parent.addView(root);
    }
    return bind(root);
  }

  @NonNull
  public static LayoutDraweractionviewBinding bind(@NonNull View rootView) {
    if (rootView == null) {
      throw new NullPointerException("rootView");
    }

    ImageButton imageButton = (ImageButton) rootView;

    return new LayoutDraweractionviewBinding((ImageButton) rootView, imageButton);
  }
}
