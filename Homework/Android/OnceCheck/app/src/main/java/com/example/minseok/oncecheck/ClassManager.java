package com.example.minseok.oncecheck;

import java.util.ArrayList;

/**
 * Created by minseok on 16. 6. 6..
 */
public class ClassManager{
    ArrayList<ClassItem> Classes;
    int numOfClass = 0;


    private class ClassItem{
        String name;
        String memo;
        int dayofweek;

        public String getName(){
            return name;
        }

        public String getMemo(){
            return memo;
        }

        public int getDayofweek(){
            return dayofweek;
        }

        public void setName(String _name){
            name = _name;
        }

        public void setMemo(String _memo){
            memo = _memo;
        }

        public void setDayofweek(){

        }


    }

}


