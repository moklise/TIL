package com.example.minseok.oncecheck;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;


public class ScrollingActivity extends AppCompatActivity {

//    TextView todayWeather = (TextView) findViewById(R.id.todayWeatherText);
    TextView todayWeather;
    NetworkManager DataConnector;

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        Log.d("DOCUMENT", "뀨뀨뀨꺄꺄꺄꺆뀨ㄸ류ㅕㄸㅠㄸ류ㅕㄸ뀨ㅕㄸ류ㅕ뜎뗘뀨ㄸ");

        try{
            DataConnector = data.getParcelableExtra("DataList");
            todayWeather.setText("현재 온도는 : " + DataConnector.getWeather() + "입니다.");
        }catch (Exception e){
            Log.d("DOCUMENT", e.getMessage());
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_scrolling);

        todayWeather = (TextView) findViewById(R.id.todayWeatherText);

        // Toolbar
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        // Change Title String
        getSupportActionBar().setTitle(NetworkManager.getToday());

        // updateInfo();
        Bundle bundle = getIntent().getExtras();
        DataConnector = (NetworkManager)bundle.getParcelable("DataList");
        Log.d("DOCUMENT", String.valueOf(DataConnector.DataList2.isEmpty()));
        todayWeather.setText("현재 온도는 : " + DataConnector.getWeather() + "입니다.");




        // Floating Button 클릭시 Popup
        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "그렇습니다", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_scrolling, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }


}
