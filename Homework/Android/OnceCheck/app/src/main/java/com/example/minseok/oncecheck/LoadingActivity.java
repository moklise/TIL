package com.example.minseok.oncecheck;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Parcelable;
import android.util.Log;

/**
 * Created by minseok on 16. 6. 6..
 */
public class LoadingActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_loading);
        startLoading();
    }

    private void startLoading() {
        Handler handler = new Handler();

        final NetworkManager DataConnector = new NetworkManager();
        DataConnector.start();

        handler.postDelayed(new Runnable() {
            @Override
            public void run() {
                Intent intent = new Intent(getApplicationContext(), ScrollingActivity.class);
                intent.putExtra("DataList", (Parcelable) DataConnector);
                startActivityForResult(intent, 100);
                Log.d("DOCUMENT", "보내쨩");
                finish();
            }
        }, 2000);
    }
}