package com.example.minseok.oncecheck;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;

import java.util.ArrayList;

/**
 * Created by minseok on 16. 6. 6..
 */
public class LoadingActivity extends Activity {
    NetworkManager DataConnector;
    static ArrayList<String> weatherTemp;
    static ArrayList<String> weatherMaxTemp;
    static ArrayList<String> weatherStatus;
    static ArrayList<String> weatherRain;
    static int leftPart;

    DBManager dbHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_loading);
        DataConnector = new NetworkManager();
        DataConnector.start();

        dbHelper = new DBManager(this);
        Intent initializeIntent = new Intent(getBaseContext(), InitializerActivity.class);

        if(dbHelper.b_select("initialized").equals("")){
            startActivityForResult(initializeIntent, 0000);
        }else{
            startLoading();
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        startLoading();
    }

    private void startLoading() {
        Handler handler = new Handler();

        handler.postDelayed(new Runnable() {
            @Override
            public void run() {

                try{
                    Intent intent = new Intent(getBaseContext(), ScrollingActivity.class);
                    intent.putStringArrayListExtra("weather", weatherTemp);
                    intent.putStringArrayListExtra("weatherMax", weatherMaxTemp);
                    intent.putStringArrayListExtra("weatherStatus", weatherStatus);
                    intent.putStringArrayListExtra("weatherRain", weatherRain);
                    intent.putExtra("leftPart", leftPart);

                    startActivity(intent);
                    finish();
                }catch (Exception e){
                    Log.d("DOCUMENT", e.getMessage());
                }

            }
        }, 5000);
    }

    static public void getDataList(ArrayList<String> datalist){
        weatherTemp = (ArrayList<String>) datalist.clone();
        Log.d("DOCUMENT", "뱡뱡뱡뱡뱡뱌뱌뱌뱌뱝" + weatherTemp.get(0));
    }

    static public void getDataListMax(ArrayList<String> datalist){
        weatherMaxTemp = (ArrayList<String>) datalist.clone();
    }

    static public void getDataListStatus(ArrayList<String> datalist){
        weatherStatus = (ArrayList<String>) datalist.clone();
    }

    static public void getDataListRain(ArrayList<String> datalist){
        weatherRain = (ArrayList<String>) datalist.clone();
    }

    static public void getNextDay(int _currentPart){
        leftPart = _currentPart;
    }
}