// Generated by view binder compiler. Do not edit!
package com.amaze.filemanager.databinding;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.viewbinding.ViewBinding;
import com.amaze.filemanager.R;
import com.amaze.filemanager.ui.views.ThemedTextView;
import java.lang.NullPointerException;
import java.lang.Override;
import java.lang.String;

public final class GriditemBinding implements ViewBinding {
  @NonNull
  private final FrameLayout rootView;

  @NonNull
  public final ImageView checkIconGrid;

  @NonNull
  public final TextView date;

  @NonNull
  public final View dummyView;

  @NonNull
  public final ThemedTextView firstline;

  @NonNull
  public final ImageView genericIcon;

  @NonNull
  public final RelativeLayout iconFrameGrid;

  @NonNull
  public final ImageView iconThumb;

  @NonNull
  public final LinearLayout line1;

  @NonNull
  public final TextView permis;

  @NonNull
  public final ImageButton properties;

  @NonNull
  public final FrameLayout second;

  @NonNull
  public final TextView secondLine;

  private GriditemBinding(@NonNull FrameLayout rootView, @NonNull ImageView checkIconGrid,
      @NonNull TextView date, @NonNull View dummyView, @NonNull ThemedTextView firstline,
      @NonNull ImageView genericIcon, @NonNull RelativeLayout iconFrameGrid,
      @NonNull ImageView iconThumb, @NonNull LinearLayout line1, @NonNull TextView permis,
      @NonNull ImageButton properties, @NonNull FrameLayout second, @NonNull TextView secondLine) {
    this.rootView = rootView;
    this.checkIconGrid = checkIconGrid;
    this.date = date;
    this.dummyView = dummyView;
    this.firstline = firstline;
    this.genericIcon = genericIcon;
    this.iconFrameGrid = iconFrameGrid;
    this.iconThumb = iconThumb;
    this.line1 = line1;
    this.permis = permis;
    this.properties = properties;
    this.second = second;
    this.secondLine = secondLine;
  }

  @Override
  @NonNull
  public FrameLayout getRoot() {
    return rootView;
  }

  @NonNull
  public static GriditemBinding inflate(@NonNull LayoutInflater inflater) {
    return inflate(inflater, null, false);
  }

  @NonNull
  public static GriditemBinding inflate(@NonNull LayoutInflater inflater,
      @Nullable ViewGroup parent, boolean attachToParent) {
    View root = inflater.inflate(R.layout.griditem, parent, false);
    if (attachToParent) {
      parent.addView(root);
    }
    return bind(root);
  }

  @NonNull
  public static GriditemBinding bind(@NonNull View rootView) {
    // The body of this method is generated in a way you would not otherwise write.
    // This is done to optimize the compiled bytecode for size and performance.
    int id;
    missingId: {
      id = R.id.check_icon_grid;
      ImageView checkIconGrid = rootView.findViewById(id);
      if (checkIconGrid == null) {
        break missingId;
      }

      id = R.id.date;
      TextView date = rootView.findViewById(id);
      if (date == null) {
        break missingId;
      }

      id = R.id.dummy_view;
      View dummyView = rootView.findViewById(id);
      if (dummyView == null) {
        break missingId;
      }

      id = R.id.firstline;
      ThemedTextView firstline = rootView.findViewById(id);
      if (firstline == null) {
        break missingId;
      }

      id = R.id.generic_icon;
      ImageView genericIcon = rootView.findViewById(id);
      if (genericIcon == null) {
        break missingId;
      }

      id = R.id.icon_frame_grid;
      RelativeLayout iconFrameGrid = rootView.findViewById(id);
      if (iconFrameGrid == null) {
        break missingId;
      }

      id = R.id.icon_thumb;
      ImageView iconThumb = rootView.findViewById(id);
      if (iconThumb == null) {
        break missingId;
      }

      id = R.id.line1;
      LinearLayout line1 = rootView.findViewById(id);
      if (line1 == null) {
        break missingId;
      }

      id = R.id.permis;
      TextView permis = rootView.findViewById(id);
      if (permis == null) {
        break missingId;
      }

      id = R.id.properties;
      ImageButton properties = rootView.findViewById(id);
      if (properties == null) {
        break missingId;
      }

      FrameLayout second = (FrameLayout) rootView;

      id = R.id.secondLine;
      TextView secondLine = rootView.findViewById(id);
      if (secondLine == null) {
        break missingId;
      }

      return new GriditemBinding((FrameLayout) rootView, checkIconGrid, date, dummyView, firstline,
          genericIcon, iconFrameGrid, iconThumb, line1, permis, properties, second, secondLine);
    }
    String missingId = rootView.getResources().getResourceName(id);
    throw new NullPointerException("Missing required view with ID: ".concat(missingId));
  }
}
