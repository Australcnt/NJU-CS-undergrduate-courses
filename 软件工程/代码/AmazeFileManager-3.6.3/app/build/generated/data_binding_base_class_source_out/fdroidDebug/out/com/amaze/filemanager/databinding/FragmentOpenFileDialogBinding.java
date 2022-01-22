// Generated by view binder compiler. Do not edit!
package com.amaze.filemanager.databinding;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.recyclerview.widget.RecyclerView;
import androidx.viewbinding.ViewBinding;
import com.amaze.filemanager.R;
import java.lang.NullPointerException;
import java.lang.Override;
import java.lang.String;

public final class FragmentOpenFileDialogBinding implements ViewBinding {
  @NonNull
  private final ConstraintLayout rootView;

  @NonNull
  public final TextView alwaysButton;

  @NonNull
  public final RecyclerView appsRecyclerView;

  @NonNull
  public final TextView chooseDifferentAppTextView;

  @NonNull
  public final View divider;

  @NonNull
  public final TextView justOnceButton;

  @NonNull
  public final ImageView lastAppImage;

  @NonNull
  public final TextView lastAppTitle;

  @NonNull
  public final ImageButton openAsButton;

  @NonNull
  public final ConstraintLayout parent;

  private FragmentOpenFileDialogBinding(@NonNull ConstraintLayout rootView,
      @NonNull TextView alwaysButton, @NonNull RecyclerView appsRecyclerView,
      @NonNull TextView chooseDifferentAppTextView, @NonNull View divider,
      @NonNull TextView justOnceButton, @NonNull ImageView lastAppImage,
      @NonNull TextView lastAppTitle, @NonNull ImageButton openAsButton,
      @NonNull ConstraintLayout parent) {
    this.rootView = rootView;
    this.alwaysButton = alwaysButton;
    this.appsRecyclerView = appsRecyclerView;
    this.chooseDifferentAppTextView = chooseDifferentAppTextView;
    this.divider = divider;
    this.justOnceButton = justOnceButton;
    this.lastAppImage = lastAppImage;
    this.lastAppTitle = lastAppTitle;
    this.openAsButton = openAsButton;
    this.parent = parent;
  }

  @Override
  @NonNull
  public ConstraintLayout getRoot() {
    return rootView;
  }

  @NonNull
  public static FragmentOpenFileDialogBinding inflate(@NonNull LayoutInflater inflater) {
    return inflate(inflater, null, false);
  }

  @NonNull
  public static FragmentOpenFileDialogBinding inflate(@NonNull LayoutInflater inflater,
      @Nullable ViewGroup parent, boolean attachToParent) {
    View root = inflater.inflate(R.layout.fragment_open_file_dialog, parent, false);
    if (attachToParent) {
      parent.addView(root);
    }
    return bind(root);
  }

  @NonNull
  public static FragmentOpenFileDialogBinding bind(@NonNull View rootView) {
    // The body of this method is generated in a way you would not otherwise write.
    // This is done to optimize the compiled bytecode for size and performance.
    int id;
    missingId: {
      id = R.id.always_button;
      TextView alwaysButton = rootView.findViewById(id);
      if (alwaysButton == null) {
        break missingId;
      }

      id = R.id.apps_recycler_view;
      RecyclerView appsRecyclerView = rootView.findViewById(id);
      if (appsRecyclerView == null) {
        break missingId;
      }

      id = R.id.choose_different_app_text_view;
      TextView chooseDifferentAppTextView = rootView.findViewById(id);
      if (chooseDifferentAppTextView == null) {
        break missingId;
      }

      id = R.id.divider;
      View divider = rootView.findViewById(id);
      if (divider == null) {
        break missingId;
      }

      id = R.id.just_once_button;
      TextView justOnceButton = rootView.findViewById(id);
      if (justOnceButton == null) {
        break missingId;
      }

      id = R.id.last_app_image;
      ImageView lastAppImage = rootView.findViewById(id);
      if (lastAppImage == null) {
        break missingId;
      }

      id = R.id.last_app_title;
      TextView lastAppTitle = rootView.findViewById(id);
      if (lastAppTitle == null) {
        break missingId;
      }

      id = R.id.open_as_button;
      ImageButton openAsButton = rootView.findViewById(id);
      if (openAsButton == null) {
        break missingId;
      }

      ConstraintLayout parent = (ConstraintLayout) rootView;

      return new FragmentOpenFileDialogBinding((ConstraintLayout) rootView, alwaysButton,
          appsRecyclerView, chooseDifferentAppTextView, divider, justOnceButton, lastAppImage,
          lastAppTitle, openAsButton, parent);
    }
    String missingId = rootView.getResources().getResourceName(id);
    throw new NullPointerException("Missing required view with ID: ".concat(missingId));
  }
}
