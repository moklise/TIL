package com.example.minseok.oncecheck;

import android.os.Parcel;
import android.os.Parcelable;
import android.util.Log;

import java.util.ArrayList;
import java.util.Calendar;

/**
 * Created by minseok on 16. 6. 6..
 */

// 네트워크 데이터 관리
class NetworkManager extends Thread implements Parcelable {
    Thread crawler;
    String foodURL = "http://www.gachon.ac.kr/etc/food_xml.jsp";
    String weatherURL = "http://web.kma.go.kr/wid/queryDFSRSS.jsp?zone=4113162000";

    private ArrayList<String> DataList = new ArrayList<>();
    public ArrayList<String> DataList2 = new ArrayList<>();


    public NetworkManager(){
        Log.d("MSTEST", "Network Manager 생성");
    }

    protected NetworkManager(Parcel in) {
        foodURL = in.readString();
        weatherURL = in.readString();
        DataList = in.createStringArrayList();
        DataList2 = in.createStringArrayList();
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeString(foodURL);
        dest.writeString(weatherURL);
        dest.writeStringList(DataList);
        dest.writeStringList(DataList2);
    }

    @Override
    public int describeContents() {
        return 0;
    }

    public static final Creator<NetworkManager> CREATOR = new Creator<NetworkManager>() {
        @Override
        public NetworkManager createFromParcel(Parcel in) {
            return new NetworkManager(in);
        }

        @Override
        public NetworkManager[] newArray(int size) {
            return new NetworkManager[size];
        }
    };

    public void start(){
        Log.d("MSTEST", "Tread 생성 시작");
        crawler = new Thread(new NetworkManager());
        crawler.start();
    }

    @Override
    public void run() {
        super.run();

        Log.d("MSTEST", "Tread 작동");
//        DataList = (ArrayList<String>) XmlParser.StartParsing(foodURL, "FOOD").clone();
        DataList2 = (ArrayList<String>) XmlParser.StartParsing(weatherURL, "TODAYWEATHER").clone();

        try{
//            Log.d("DOCUMENT", "############ 내가 원하는 값 ############" + String.valueOf(DataList.get(0)));
            Log.d("DOCUMENT", "############ 내가 원하는 값 ############" + String.valueOf(DataList2.get(0)));
        }catch(Exception e){
            Log.d("DOCUMENT", "############ 응 안됨~ ############" + e.getMessage());
        }
    }

    public String getFood(){
        // Algorithm 적용
        return "오늘의 밥";
    }


    public String getWeather(){
        return String.valueOf(DataList2.get(0));
    }

    public String getFits(){
        return "옷";
    }

    public void getData(){
        try{
            Log.d("DOCUMENT", "############ 내가 원하는 값 ############" + String.valueOf(DataList.get(0)));
            Log.d("DOCUMENT", "############ 내가 원하는 값 ############" + String.valueOf(DataList2.get(0)));
        }catch(Exception e){
            Log.d("DOCUMENT", "############ 응 안됨~ ############" + e.getMessage());
        }
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

