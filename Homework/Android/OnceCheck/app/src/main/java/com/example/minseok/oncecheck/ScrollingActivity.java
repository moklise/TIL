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

import java.util.Calendar;

public class ScrollingActivity extends AppCompatActivity {

    TextView todayWeather;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_scrolling);

        // Toolbar
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        // Change Title String
        getSupportActionBar().setTitle(setToday());

        // updateInfo();
        todayWeather = (TextView) findViewById(R.id.todayWeatherText);
        todayWeather.setText(XmlParser.StartParsing());

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

    private String setToday(){
        Calendar cal = Calendar.getInstance();

        //현재 년도, 월, 일
        int year = cal.get ( cal.YEAR );
        int month = cal.get ( cal.MONTH ) + 1 ;
        int date = cal.get ( cal.DATE ) ;
        String DayOfWeek = "";

        cal.set(Calendar.YEAR, year);
        cal.set(Calendar.MONTH, month);
        cal.set(Calendar.DATE, date);

        DayOfWeek = String.valueOf(month)+"/"+String.valueOf(date)+" ";

        switch (cal.get(Calendar.DAY_OF_WEEK)){
            case 1:
                DayOfWeek += "일요일";
                break;
            case 2:
                DayOfWeek += "월요일";
                break;
            case 3:
                DayOfWeek += "화요일";
                break;
            case 4:
                DayOfWeek += "수요일";
                break;
            case 5:
                DayOfWeek += "목요일";
                break;
            case 6:
                DayOfWeek += "금요일";
                break;
            case 7:
                DayOfWeek += "토요일";
                break;
        }

        return DayOfWeek;
    }

    private void updateInfo(){

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
