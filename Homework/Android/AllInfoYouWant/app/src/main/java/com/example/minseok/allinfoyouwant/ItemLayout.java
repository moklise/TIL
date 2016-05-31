package com.example.minseok.allinfoyouwant;

import android.app.Activity;
import android.content.Context;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.widget.LinearLayout;
import android.widget.TextView;

// MainListView Item Layout
public class ItemLayout extends LinearLayout
{
    Context mContext;
    LayoutInflater inflater;

    TextView nameTextView;
    TextView subjectTextView;
    TextView dateTextView;

    public ItemLayout(Context context)
    {
        super(context);

        mContext = context;
        init();
    }

    public ItemLayout(Context context, AttributeSet attrs)
    {
        super(context, attrs);

        mContext = context;
        init();
    }

    private void init()
    {
        // inflate XML Layout
        inflater = (LayoutInflater) mContext.getSystemService(Activity.LAYOUT_INFLATER_SERVICE);
        inflater.inflate(R.layout.list_item, this, true);

        subjectTextView = (TextView) findViewById(R.id.subjectText);
        nameTextView = (TextView) findViewById(R.id.nameText);
        dateTextView = (TextView) findViewById(R.id.dateText);
    }

    public void setNameText(String _name)
    {
        nameTextView.setText(_name);
    }

    public void setSubjectText(String _subject)
    {
        subjectTextView.setText(_subject);
    }

    public void setDateText(String _date)
    {
        dateTextView.setText(_date);
    }


}
