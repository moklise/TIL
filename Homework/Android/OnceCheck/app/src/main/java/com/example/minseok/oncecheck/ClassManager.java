package com.example.minseok.oncecheck;

import java.util.ArrayList;

/**
 * Created by minseok on 16. 6. 6..
 */
public class ClassManager{
    ArrayList<ClassItem> Classes;
    static int numOfClass = 0;

    public void addClass(String _name, int _dayofweek, String _memo){
        Classes.add(new ClassItem(_name, _dayofweek, _memo));
        numOfClass++;
    }

    public void removeClass(String _name){
        // _name 검색 후 삭제
    }

    public String getClassNameIdx(int _idx){
        return Classes.get(_idx).getName();
    }

    public int getClassDayOfWeekIdx(int _idx){
        return Classes.get(_idx).getDayofweek();
    }

    public String getClassMemoIdx(int _idx){
        return Classes.get(_idx).getMemo();
    }

    public void setClassNameIdx(int _idx, String _name){
        Classes.get(_idx).setName(_name);
    }

    public void setClassDayOfWeekIdx(int _idx, int _dayofweek){
        Classes.get(_idx).setDayofweek(_dayofweek);
    }

    public void setClassMemoIdx(int _idx, String _memo){
        Classes.get(_idx).setMemo(_memo);
    }

    public class ClassItem{
        String name;
        String memo;
        int dayofweek;

        public ClassItem(String _name, int _dayofweek, String _memo){
            name = _name;
            dayofweek = _dayofweek;
            memo = _memo;
        }

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
        public void setDayofweek(int _dayofweek){
            dayofweek = _dayofweek;
        }


    }

}


