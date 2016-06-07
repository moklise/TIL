package com.example.minseok.oncecheck;

import android.util.Log;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserException;
import org.xmlpull.v1.XmlPullParserFactory;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;

/**
 * Created by minseok on 2016-06-02.
 */

public class XmlParser{

    static public ArrayList<String> StartParsing(String url, String status) {
        String xml = downloadURL(url);
        return (ArrayList<String>) parseXML(xml, status).clone();
    }

    // Status 가 food 일경우와 weather일 경우가 다르다
    private static String CheckLine(XmlPullParser parser, int eventType, String status) throws IOException, XmlPullParserException {
        switch (status){

            // 학식
            case "FOOD":
                switch (eventType){
                    case XmlPullParser.START_DOCUMENT:

                        System.out.println("Start document");
                        Log.d("MSTEST", "Start document");

                        break;

                    case XmlPullParser.START_TAG:

                        break;
                }
                break;

            // 오늘의 날씨
            case "TODAYWEATHER":
                switch (eventType) {

                    case XmlPullParser.START_DOCUMENT:

                        System.out.println("Start document");
                        Log.d("MSTEST", "Start document");

                        break;

                    case XmlPullParser.START_TAG:
                        if (parser.getName().equals("temp")) {
                            parser.next();
                            Log.d("DOCUMENT", parser.getText());
                            return parser.getText();
                        }

                        break;
                    default:
                }
                break;

            // 내일의 날씨
//            case "tomorrowWeather":
//                break;

            default:

        }

        return "";
    }

    // XML 형식의 String 처리
    private static ArrayList<String> parseXML(String xml, String status) {
        ArrayList<String> tempDataList = new ArrayList<>();
        Log.d("DOCUMENT", xml);

        try {
            XmlPullParserFactory factory = XmlPullParserFactory.newInstance();
            XmlPullParser parser = factory.newPullParser();
            parser.setInput(new StringReader(xml));

            // 여기까지 의미있는부분을 짤라준다.
            int eventType = parser.getEventType();
            String buffer;
            while (eventType != XmlPullParser.END_DOCUMENT) {
                buffer = CheckLine(parser, eventType, status);
                if(!(buffer).equals("")){
                    tempDataList.add(buffer);
                }
                eventType = parser.next();
            }

        } catch (Exception e) {
            e.printStackTrace();
            Log.d("DOCUMENT", "parseXML : " + e.toString());
        }
        // Pasring 결과
        try {
            Log.d("DOCUMENT", "ㅎㅇㅎㅇㅎㅇ" + tempDataList.get(0));
        } catch (Exception e){
            Log.d("DOCUMENT", "parseXML의 마지막부분에서 안됨~" + e.getMessage());
        }
        return (ArrayList<String>) tempDataList.clone();
    }

    // DOCUMENT 읽기 XML 형식의 Stirng 반환
    private static String downloadURL(String addr) {
        String doc = "";

        Log.d("MSTEST","START READING DOCUMENT");

        try {
            URL url = new URL(addr);
            HttpURLConnection conn = (HttpURLConnection) url.openConnection();
            BufferedReader br = new BufferedReader(new InputStreamReader(conn.getInputStream()));

            for (;;) {
                String line = br.readLine();
                if (line == null)
                    break;
                doc = doc + line + "\n";
            }
            br.close();

            conn.disconnect();
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        Log.d("MSTEST","END READING DOCUMENT");
        return doc;

    }
}