// Generated by view binder compiler. Do not edit!
package com.amaze.filemanager.databinding;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.CheckBox;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.viewbinding.ViewBinding;
import com.amaze.filemanager.R;
import java.lang.NullPointerException;
import java.lang.Override;
import java.lang.String;

public final class DialogDragDropBinding implements ViewBinding {
  @NonNull
  private final ConstraintLayout rootView;

  @NonNull
  public final Button buttonCopy;

  @NonNull
  public final Button buttonMove;

  @NonNull
  public final CheckBox rememberDrag;

  private DialogDragDropBinding(@NonNull ConstraintLayout rootView, @NonNull Button buttonCopy,
      @NonNull Button buttonMove, @NonNull CheckBox rememberDrag) {
    this.rootView = rootView;
    this.buttonCopy = buttonCopy;
    this.buttonMove = buttonMove;
    this.rememberDrag = rememberDrag;
  }

  @Override
  @NonNull
  public ConstraintLayout getRoot() {
    return rootView;
  }

  @NonNull
  public static DialogDragDropBinding inflate(@NonNull LayoutInflater inflater) {
    return inflate(inflater, null, false);
  }

  @NonNull
  public static DialogDragDropBinding inflate(@NonNull LayoutInflater inflater,
      @Nullable ViewGroup parent, boolean attachToParent) {
    View root = inflater.inflate(R.layout.dialog_drag_drop, parent, false);
    if (attachToParent) {
      parent.addView(root);
    }
    return bind(root);
  }

  @NonNull
  public static DialogDragDropBinding bind(@NonNull View rootView) {
    // The body of this method is generated in a way you would not otherwise write.
    // This is done to optimize the compiled bytecode for size and performance.
    int id;
    missingId: {
      id = R.id.button_copy;
      Button buttonCopy = rootView.findViewById(id);
      if (buttonCopy == null) {
        break missingId;
      }

      id = R.id.button_move;
      Button buttonMove = rootView.findViewById(id);
      if (buttonMove == null) {
        break missingId;
      }

      id = R.id.remember_drag;
      CheckBox rememberDrag = rootView.findViewById(id);
      if (rememberDrag == null) {
        break missingId;
      }

      return new DialogDragDropBinding((ConstraintLayout) rootView, buttonCopy, buttonMove,
          rememberDrag);
    }
    String missingId = rootView.getResources().getResourceName(id);
    throw new NullPointerException("Missing required view with ID: ".concat(missingId));
  }
}
