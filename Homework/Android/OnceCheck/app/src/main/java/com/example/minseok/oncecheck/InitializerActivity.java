package com.example.minseok.oncecheck;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;

public class InitializerActivity extends AppCompatActivity {

    Button doneBtn;
    Button classAddBtn;
    DBManager dbHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setTitle("안녕하세요?");
        setContentView(R.layout.activity_initializer);

        dbHelper = new DBManager(this);

        doneBtn  = (Button) findViewById(R.id.doneBtn);
        doneBtn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                setResult(0000);
                finish();
            }
        });

        classAddBtn = (Button) findViewById(R.id.classAddBtn);
        classAddBtn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){

            }
        });

    }
}
