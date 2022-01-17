package com.dnielfe.manager.debug;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

import com.dnielfe.manager.R;
import com.dnielfe.manager.ThemableActivity;

public class Newview extends ThemableActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_newview);
    }

    public void goBackToMain(View view) {
        Intent intent = new Intent(getBaseContext(), com.dnielfe.manager.BrowserActivity.class);
        startActivity(intent);
    }
}
