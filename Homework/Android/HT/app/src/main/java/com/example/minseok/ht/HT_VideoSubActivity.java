package com.example.minseok.ht;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

public class HT_VideoSubActivity extends AppCompatActivity {
    String name;
    String link;

    TextView nameTextView;
    TextView linkTextView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ht__video_sub);

        Bundle loader = new Bundle(getIntent().getExtras());
        name = loader.getString("name");
        link = loader.getString("link");

        nameTextView = (TextView) findViewById(R.id.name);
        linkTextView = (TextView) findViewById(R.id.link);

        nameTextView.setText(name);
        linkTextView.setText(link);

    }
}
