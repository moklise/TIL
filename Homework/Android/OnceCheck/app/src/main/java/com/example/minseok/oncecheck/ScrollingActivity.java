package com.example.minseok.oncecheck;

import android.graphics.drawable.BitmapDrawable;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;


public class ScrollingActivity extends AppCompatActivity {

//    TextView todayWeather = (TextView) findViewById(R.id.todayWeatherText);
    TextView todayWeather;
    TextView todayWeatherSub;
    TextView todayClass;
    ImageView todayWeatherImage;
    NetworkManager DataConnector;
    BitmapDrawable weatherImg;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_scrolling);

        todayWeatherImage = (ImageView) findViewById(R.id.todayWeatherImage);
        todayWeather = (TextView) findViewById(R.id.todayWeatherText);
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
        ArrayList<String> weatherStatus = bundle.getStringArrayList("weatherStatus");
        ArrayList<String> weatherRain = bundle.getStringArrayList("weatherRain");

        if( Integer.parseInt(weatherRain.get(0)) > 59 ){
            weatherImg = (BitmapDrawable) getResources().getDrawable(R.drawable.rain);
        }else{
            weatherImg = (BitmapDrawable) getResources().getDrawable(R.drawable.sun);
        }
        todayWeatherImage.setImageDrawable(weatherImg);

        String weatherString = "현재 온도는 " + weather.get(0) + "입니다.";

        Log.d("DOCUMENT", weatherMax.get(0));

        if( !weatherMax.get(0).equals("-999.0")) {
            weatherString += "\n 오늘의 최고 기온은 " + weatherMax.get(0) + "입니다. ";
        }
        weatherString += "\n현재 강수 확률은 "+ weatherRain.get(0) +"입니다.";
        weatherString += "\n그냥 집에 계시는게 낫겠네요";
        todayWeather.setText(weatherString);

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
