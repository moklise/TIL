package com.example.minseok.allinfoyouwant;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.BaseAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity
{
    public static final int LOCK_CODE = 9999;

    ListView mainListView;
    TextView itemView;
    MainListAdapter mainListAdapter;
    ArrayList<Item> dataList = new ArrayList<Item>();
    Boolean lockFlag = true;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mainListView = (ListView) findViewById(R.id.mainListView);
        mainListAdapter = new MainListAdapter(this);

       // 데이터 저장

        // List View의 Items
        String[] names = {"1", "2", "3", "4", "5", "2", "3", "4", "5", "2", "3", "4", "5", "2", "3", "4", "5"};
        String[] subjects = {"1", "2", "3", "4", "5", "2", "3", "4", "5", "2", "3", "4", "5", "2", "3", "4", "5"};
        String[] date = {"1", "2", "3", "4", "5", "2", "3", "4", "5", "2", "3", "4", "5", "2", "3", "4", "5"};


        // 데이터 입력
        for(int i = 0 ; i < names.length ; i++)
        {
            Item data = new Item(subjects[i],names[i],date[i]);
            dataList.add(data);
        }


        // Data Inflation
        for(int i = 0 ; i < names.length ; i++)
        {
            Item item = new Item(subjects[i], names[i], date[i]);
            mainListAdapter.addItem(item);
        }

        mainListView.setAdapter(mainListAdapter);
        mainListView.setOnItemClickListener(onClickListItem);

    }

    @Override
    protected void onResume() {

        // 잠금설정
        if(lockFlag){
            // 비밀번호 창 떠야함
            Intent lockScreen = new Intent(getApplicationContext(), LockScreen.class);
            startActivityForResult(lockScreen, LOCK_CODE);
        }

        super.onResume();
    }

    @Override
    protected void onPause() {
        lockFlag = true;
        super.onPause();
    }

    // Lock 관련
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data)
    {
        super.onActivityResult(requestCode, resultCode, data);

        if(requestCode == LOCK_CODE)
        {
            if(resultCode == 1)
            {
                if(data.getExtras().getBoolean("ok"))
                {
                    lockFlag = false;
                }
            }
        }

    }

    // List 관련
    private OnItemClickListener onClickListItem = new AdapterView.OnItemClickListener() {
        @Override
        public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
            Toast.makeText(getApplicationContext(), dataList.get(position).getSubject() , Toast.LENGTH_SHORT).show();
        }
    };

    class MainListAdapter extends BaseAdapter
    {
        // Item List
        ArrayList<Item> itemsList = new ArrayList<Item>();
        Context mContext;

        // Constructor
        public MainListAdapter(Context context)
        {
            mContext = context;
        }

        @Override
        public int getCount() {
            return itemsList.size();
        }

        @Override
        public Object getItem(int position)
        {
            return itemsList.get(position);
        }

        @Override
        public long getItemId(int position)
        {
            return position;
        }

        public void addItem(Item item)
        {
            itemsList.add(item);
        }

        public void clear()
        {
            itemsList.clear();
        }

        @Override
        public View getView(int position, View convertView, ViewGroup parent)
        {
            ItemLayout itemlayout = new ItemLayout(mContext);

            Item items = itemsList.get(position);

            itemlayout.setSubjectText(items.getSubject());
            itemlayout.setNameText(items.getName());
            itemlayout.setDateText(items.getDate());

            return itemlayout;
        }



    }


}
