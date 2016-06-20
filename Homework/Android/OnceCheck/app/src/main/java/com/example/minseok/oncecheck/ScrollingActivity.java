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
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;


public class ScrollingActivity extends AppCompatActivity {

//    TextView todayWeather = (TextView) findViewById(R.id.todayWeatherText);
    ImageView todayWeatherImage;
    TextView todayWeather;
    ImageView tommorowWeatherImage;
    TextView tomorrowWeather;
    TextView todayFit;
    ImageView todayFitImage;
    ImageView todayFitImage2;
    ImageView todayFitImage3;
    TextView todayClass;
    EditText tomorrowTodo;
    DBManager dbHelper;

    int leftDay = 0;

    NetworkManager DataConnector;
    BitmapDrawable imgBuffer;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_scrolling);

        dbHelper = new DBManager(this);
        todayWeatherImage = (ImageView) findViewById(R.id.todayWeatherImage);
        todayWeather = (TextView) findViewById(R.id.todayWeatherText);
        tommorowWeatherImage = (ImageView) findViewById((R.id.tomorrowWeatherImage));
        tomorrowWeather = (TextView) findViewById(R.id.tomorrowWeatherText);
        todayFit = (TextView) findViewById(R.id.todayFitText);
        todayFitImage = (ImageView) findViewById(R.id.todayFit);
        todayFitImage2 = (ImageView) findViewById(R.id.todayFit2);
        todayFitImage3 = (ImageView) findViewById(R.id.todayFit3);
        todayClass = (TextView) findViewById(R.id.todayClass);
        tomorrowTodo = (EditText) findViewById(R.id.tomorrowtodoText);

        DataConnector  = new NetworkManager();

        // Toolbar
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        // Change Title String
        getSupportActionBar().setTitle(NetworkManager.getToday());

        // updateInfo();
        // 오늘의 날씨
        Bundle bundle = getIntent().getExtras();
        ArrayList<String> weather = bundle.getStringArrayList("weather");
        ArrayList<String> weatherMax = bundle.getStringArrayList("weatherMax");
        ArrayList<String> weatherStatus = bundle.getStringArrayList("weatherStatus");
        ArrayList<String> weatherRain = bundle.getStringArrayList("weatherRain");

        leftDay = bundle.getInt("leftPart");
        // 오늘의 날씨
        if( Integer.parseInt(weatherRain.get(0)) > 59 ){
            imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.rain);
        }else{
            imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.sun);
        }
        todayWeatherImage.setImageDrawable(imgBuffer);

        String weatherString = "현재 온도는 " + weather.get(0) + "입니다.";
        if( !weatherMax.get(0).equals("-999.0")) {
            weatherString += "\n 오늘의 최고 기온은 " + weatherMax.get(0) + "입니다. ";
        }
        weatherString += "\n현재 강수 확률은 "+ weatherRain.get(0) +"% 입니다.";
        
        if(Double.valueOf(weather.get(0)) > 30)
        {
            weatherString += "\n더우니 그냥 집에 계시는게 낫겠네요";    
        }
        else if(Double.valueOf(weather.get(0)) > 20)
        {
            weatherString += "\n놀러다니기 좋은 날씨네요";
        }else if(Double.valueOf(weather.get(0)) > 10)
        {
            weatherString += "\n놀러다니기 좋은 날씨네요";
        }else{
            weatherString += "\n너무 추으니 그냥 집에 계시는게 낫겠네요";
        }

        
        todayWeather.setText(weatherString);


        // 내일의 날씨
        if( Integer.parseInt(weatherRain.get(0)) > 59 ){
            imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.rain);
        }else{
            imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.sun);
        }
        tommorowWeatherImage.setImageDrawable(imgBuffer);

        weatherString = "";
        if( !weatherMax.get(0).equals("-999.0")) {
            weatherString = "내일의 최고기온은 " + weatherMax.get(leftDay+1) + "입니다.";
        }
        weatherString += "\n내일의 강수 확률은 "+ weatherRain.get(leftDay+1) +"% 입니다.";
        tomorrowWeather.setText(weatherString);

        double validTemp = 0;

        for(int i = 0 ; i < leftDay + 8 ; i++){
            if( !weatherMax.get(i).equals("-999.0")) {
                validTemp = Double.valueOf(weatherMax.get(i));
                break;
            }
        }

            // 옷
            if( validTemp > 27){
                imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.tanktop);
                todayFitImage.setImageDrawable(imgBuffer);
                imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.longtanktop);
                todayFitImage2.setImageDrawable(imgBuffer);
                imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.shorts);
                todayFitImage3.setImageDrawable(imgBuffer);
                todayFit.setText("나시티, 반바지, 민소매 원피스가 적당하겠습니다 :)");
            }else if( validTemp > 23){
                imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.shirt1);
                todayFitImage.setImageDrawable(imgBuffer);
                imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.ga);
                todayFitImage2.setImageDrawable(imgBuffer);
                imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.pants);
                todayFitImage3.setImageDrawable(imgBuffer);
                todayFit.setText("긴팔티, 가디건, 후드티, 면바지, 슬랙스, 스키니 :)");
            }else if( validTemp > 17){
                imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.jacket);
                todayFitImage.setImageDrawable(imgBuffer);
                imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.hoodie);
                todayFitImage2.setImageDrawable(imgBuffer);
                imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.jeans);
                todayFitImage3.setImageDrawable(imgBuffer);
                todayFit.setText("니트, 가디건, 후드티, 맨투맨, 청바지");
            }else if( validTemp > 12){
                imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.jacket);
                todayFitImage.setImageDrawable(imgBuffer);
                imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.shirts);
                todayFitImage2.setImageDrawable(imgBuffer);
                imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.ga);
                todayFitImage3.setImageDrawable(imgBuffer);
                todayFit.setText("자켓, 셔츠, 가디건, 간절기 야상, 살색스타킹");
            }else if( validTemp > 10){
                imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.coat);
                todayFitImage.setImageDrawable(imgBuffer);
                todayFit.setText("트렌치코트, 간절기 야상, 여러겹 껴입기");
            }else if( validTemp > 6){
                imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.coat);
                todayFitImage.setImageDrawable(imgBuffer);
                todayFit.setText("코트, 가죽자켓이 적당하겠습니다 :)");
            }else{
                imgBuffer = (BitmapDrawable) getResources().getDrawable(R.drawable.neck);
                todayFitImage.setImageDrawable(imgBuffer);
                Log.d("DOCUMENT", weatherMax.get(0));
                todayFit.setText("패딩, 목도리, 겨울야상이 적당하겠습니다 :)");
            }

        todayClass = (TextView) findViewById(R.id.todayClass);
        todayClass.setText(dbHelper.c_printData());


        // Floating Button 클릭시 Popup
        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "내일 할일 [ " + tomorrowTodo.getText() +  " ]을 추가하였습니다.", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();

                dbHelper.b_insert("todo", String.valueOf(tomorrowTodo.getText()));
                tomorrowTodo.setText("");

                //intent로 새 액티비티 보내기
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
