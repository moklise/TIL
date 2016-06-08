package com.example.minseok.oncecheck;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;

import java.util.ArrayList;


public class ScrollingActivity extends AppCompatActivity {

//    TextView todayWeather = (TextView) findViewById(R.id.todayWeatherText);
    TextView todayWeather;
    TextView todayWeatherSub;
    TextView todayClass;
    NetworkManager DataConnector;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_scrolling);

        todayWeather = (TextView) findViewById(R.id.todayWeatherText);
        todayWeatherSub = (TextView) findViewById(R.id.todayWeatherTextSub);
        todayClass = (TextView) findViewById(R.id.todayClass);
        DataConnector  = new NetworkManager();

        // Toolbar
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        // Change Title String
        getSupportActionBar().setTitle(NetworkManager.getToday());

        // updateInfo();
        Bundle bundle = getIntent().getExtras();
        ArrayList<String> weather = bundle.getStringArrayList("weather");
        ArrayList<String> weatherMax = bundle.getStringArrayList("weatherMax");

        todayWeather.setText("현재 온도는 " + weather.get(0) + "입니다. \n 오늘의 최고 기온은 : " + weatherMax.get(0) + "입니다.");
        todayWeatherSub.setText("그냥 집에 계시는게 낫겠네요");


        todayClass.setText("기기");


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
