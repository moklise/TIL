package com.example.minseok.oncecheck;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserFactory;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.net.HttpURLConnection;
import java.net.URL;

/**
 * Created by minseok on 2016-06-02.
 */

public class XmlParser{

    public static String StartParsing() {
        String url = "http://www.gachon.ac.kr/etc/food_xml.jsp";
        String xml = downloadURL(url);
        return parseXML(xml);
    }

    // XML 형식의 String 처리
    private static String parseXML(String xml) {
        int itemtype = 0;
        String itemText = "이러면 못잡는거";
        try {
            XmlPullParserFactory factory = XmlPullParserFactory.newInstance();
            XmlPullParser parser = factory.newPullParser();
            parser.setInput(new StringReader(xml));

            // 여기까지 의미있는부분을 짤라준다.
            int eventType = parser.getEventType();
            while (eventType != XmlPullParser.END_DOCUMENT) {
                if(eventType == XmlPullParser.START_DOCUMENT) {
                    System.out.println("Start document");
                } else if(eventType == XmlPullParser.START_TAG) {
                    System.out.println("Start tag "+parser.getName());
                } else if(eventType == XmlPullParser.END_TAG) {
                    System.out.println("End tag "+parser.getName());
                } else if(eventType == XmlPullParser.TEXT) {
                    System.out.println("Text "+parser.getText());
                }
                eventType = parser.next();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        // Pasring 결과
//        return itemText;
        return xml;
    }

    // XML 형식의 Stirng 반환
    private static String downloadURL(String addr) {
        String doc = "";
        try {
            URL url = new URL(addr);
            HttpURLConnection conn = (HttpURLConnection) url.openConnection();


            conn.setConnectTimeout(10000);
            conn.setUseCaches(false);
            BufferedReader br = new BufferedReader(
                    new InputStreamReader(conn.getInputStream()));
            for (;;) {
                String line = br.readLine();
                if (line == null)
                    break;
                doc = doc + line + "\n";
            }
            br.close();

            // conn.disconnect();

        } catch (Exception ex) {
            ex.printStackTrace();
        }

        return doc;

    }

}
