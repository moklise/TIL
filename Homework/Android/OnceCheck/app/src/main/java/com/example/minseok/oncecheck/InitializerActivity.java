package com.example.minseok.oncecheck;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class InitializerActivity extends AppCompatActivity {

    Button doneBtn;
    Button classAddBtn;
    EditText className;
    EditText classTime;
    EditText classMemo;

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
                dbHelper.b_insert("initialized","y");
                setResult(0000);
                finish();
            }
        });

        className = (EditText) findViewById(R.id.className);
        classTime = (EditText) findViewById(R.id.classTime);
        classMemo = (EditText) findViewById(R.id.classMemo);

        classAddBtn = (Button) findViewById(R.id.classAddBtn);
        classAddBtn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                Toast.makeText(getApplicationContext(),"저장되었습니다.",Toast.LENGTH_SHORT);
                dbHelper.c_insert(String.valueOf(className.getText()), String.valueOf(classTime.getText()), String.valueOf(classMemo.getText()));
            }
        });

    }
}
