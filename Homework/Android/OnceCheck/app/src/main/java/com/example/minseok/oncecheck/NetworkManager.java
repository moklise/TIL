package com.example.minseok.oncecheck;

import android.util.Log;

import java.util.ArrayList;
import java.util.Calendar;

/**
 * Created by minseok on 16. 6. 6..
 */

// 네트워크 데이터 관리
class NetworkManager extends Thread{
    Thread crawler;
    String foodURL = "http://www.gachon.ac.kr/etc/food_xml.jsp";
    String weatherURL = "http://web.kma.go.kr/wid/queryDFSRSS.jsp?zone=4113162000";

    private ArrayList DataList = null;
    private ArrayList DataList2 = null;


    public NetworkManager(){
        Log.d("MSTEST", "Network Manager 생성");
    }

    public void start(){
        Log.d("MSTEST", "Tread 생성 시작");
        crawler = new Thread(new NetworkManager());
        crawler.start();
    }

    @Override
    public void run() {
        super.run();
        Log.d("MSTEST", "Tread 작동");
        DataList = XmlParser.StartParsing(foodURL, "FOOD");
        DataList2 = XmlParser.StartParsing(weatherURL, "WEATHER");


        try{
            Log.d("MSTEST", String.valueOf(DataList.get(0)));
        }catch(Exception e){
            Log.d("MSTEST", e.getMessage());

        }
    }

    public String getFood(){
        // Algorithm 적용
        return "오늘의 밥";
    }

    public String getWhether(){
        return "19";
    }

    public String getFits(){
        return "옷";
    }

    static public String getToday(){
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

        int DayOfWeek_i = cal.get(Calendar.DAY_OF_WEEK);

        // Tuning DayOFWeek
        if( DayOfWeek_i <= 2 ){
            DayOfWeek_i =  DayOfWeek_i + 5;
        }else{
            DayOfWeek_i = DayOfWeek_i - 2;
        }

        switch (DayOfWeek_i){
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
}

