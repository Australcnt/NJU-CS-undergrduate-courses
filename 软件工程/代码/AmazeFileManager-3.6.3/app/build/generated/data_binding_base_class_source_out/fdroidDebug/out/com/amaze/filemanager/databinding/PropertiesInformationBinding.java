// Generated by view binder compiler. Do not edit!
package com.amaze.filemanager.databinding;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.viewbinding.ViewBinding;
import com.amaze.filemanager.R;
import java.lang.NullPointerException;
import java.lang.Override;
import java.lang.String;

public final class PropertiesInformationBinding implements ViewBinding {
  @NonNull
  private final LinearLayout rootView;

  @NonNull
  public final TextView textViewAccessedTitle;

  @NonNull
  public final TextView textViewFileAccessed;

  @NonNull
  public final TextView textViewFileLocation;

  @NonNull
  public final TextView textViewFileModified;

  @NonNull
  public final TextView textViewFileName;

  @NonNull
  public final TextView textViewFileSize;

  @NonNull
  public final TextView textViewFileType;

  @NonNull
  public final TextView textViewLocationTitle;

  @NonNull
  public final TextView textViewModifiedTitle;

  @NonNull
  public final TextView textViewNameTitle;

  @NonNull
  public final TextView textViewSizeTitle;

  @NonNull
  public final TextView textViewTypeTitle;

  private PropertiesInformationBinding(@NonNull LinearLayout rootView,
      @NonNull TextView textViewAccessedTitle, @NonNull TextView textViewFileAccessed,
      @NonNull TextView textViewFileLocation, @NonNull TextView textViewFileModified,
      @NonNull TextView textViewFileName, @NonNull TextView textViewFileSize,
      @NonNull TextView textViewFileType, @NonNull TextView textViewLocationTitle,
      @NonNull TextView textViewModifiedTitle, @NonNull TextView textViewNameTitle,
      @NonNull TextView textViewSizeTitle, @NonNull TextView textViewTypeTitle) {
    this.rootView = rootView;
    this.textViewAccessedTitle = textViewAccessedTitle;
    this.textViewFileAccessed = textViewFileAccessed;
    this.textViewFileLocation = textViewFileLocation;
    this.textViewFileModified = textViewFileModified;
    this.textViewFileName = textViewFileName;
    this.textViewFileSize = textViewFileSize;
    this.textViewFileType = textViewFileType;
    this.textViewLocationTitle = textViewLocationTitle;
    this.textViewModifiedTitle = textViewModifiedTitle;
    this.textViewNameTitle = textViewNameTitle;
    this.textViewSizeTitle = textViewSizeTitle;
    this.textViewTypeTitle = textViewTypeTitle;
  }

  @Override
  @NonNull
  public LinearLayout getRoot() {
    return rootView;
  }

  @NonNull
  public static PropertiesInformationBinding inflate(@NonNull LayoutInflater inflater) {
    return inflate(inflater, null, false);
  }

  @NonNull
  public static PropertiesInformationBinding inflate(@NonNull LayoutInflater inflater,
      @Nullable ViewGroup parent, boolean attachToParent) {
    View root = inflater.inflate(R.layout.properties_information, parent, false);
    if (attachToParent) {
      parent.addView(root);
    }
    return bind(root);
  }

  @NonNull
  public static PropertiesInformationBinding bind(@NonNull View rootView) {
    // The body of this method is generated in a way you would not otherwise write.
    // This is done to optimize the compiled bytecode for size and performance.
    int id;
    missingId: {
      id = R.id.text_view_accessed_title;
      TextView textViewAccessedTitle = rootView.findViewById(id);
      if (textViewAccessedTitle == null) {
        break missingId;
      }

      id = R.id.text_view_file_accessed;
      TextView textViewFileAccessed = rootView.findViewById(id);
      if (textViewFileAccessed == null) {
        break missingId;
      }

      id = R.id.text_view_file_location;
      TextView textViewFileLocation = rootView.findViewById(id);
      if (textViewFileLocation == null) {
        break missingId;
      }

      id = R.id.text_view_file_modified;
      TextView textViewFileModified = rootView.findViewById(id);
      if (textViewFileModified == null) {
        break missingId;
      }

      id = R.id.text_view_file_name;
      TextView textViewFileName = rootView.findViewById(id);
      if (textViewFileName == null) {
        break missingId;
      }

      id = R.id.text_view_file_size;
      TextView textViewFileSize = rootView.findViewById(id);
      if (textViewFileSize == null) {
        break missingId;
      }

      id = R.id.text_view_file_type;
      TextView textViewFileType = rootView.findViewById(id);
      if (textViewFileType == null) {
        break missingId;
      }

      id = R.id.text_view_location_title;
      TextView textViewLocationTitle = rootView.findViewById(id);
      if (textViewLocationTitle == null) {
        break missingId;
      }

      id = R.id.text_view_modified_title;
      TextView textViewModifiedTitle = rootView.findViewById(id);
      if (textViewModifiedTitle == null) {
        break missingId;
      }

      id = R.id.text_view_name_title;
      TextView textViewNameTitle = rootView.findViewById(id);
      if (textViewNameTitle == null) {
        break missingId;
      }

      id = R.id.text_view_size_title;
      TextView textViewSizeTitle = rootView.findViewById(id);
      if (textViewSizeTitle == null) {
        break missingId;
      }

      id = R.id.text_view_type_title;
      TextView textViewTypeTitle = rootView.findViewById(id);
      if (textViewTypeTitle == null) {
        break missingId;
      }

      return new PropertiesInformationBinding((LinearLayout) rootView, textViewAccessedTitle,
          textViewFileAccessed, textViewFileLocation, textViewFileModified, textViewFileName,
          textViewFileSize, textViewFileType, textViewLocationTitle, textViewModifiedTitle,
          textViewNameTitle, textViewSizeTitle, textViewTypeTitle);
    }
    String missingId = rootView.getResources().getResourceName(id);
    throw new NullPointerException("Missing required view with ID: ".concat(missingId));
  }
}
