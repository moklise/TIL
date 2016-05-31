package com.example.minseok.allinfoyouwant;

/**
 * Created by minseok on 2016-05-31.
 */
public class Item {
    String subject;
    String name;
    String date;

    public Item(String _subject, String _name, String _date)
    {
        subject = _subject;
        name = _name;
        date = _date;
    }

    public String getSubject() {
        return subject;
    }

    public void setSubject(String subject) {
        this.subject = subject;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }
}
