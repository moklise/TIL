package com.example.minseok.allinfoyouwant;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class LockScreen extends AppCompatActivity {

    int countOfInput = 0;
    String inputPw = "";
    String st = "";
    String PASSWORD = "1111";

    TextView resultView;
    Button num1;
    Button num2;
    Button num3;
    Button num4;
    Button num5;
    Button num6;
    Button num7;
    Button num8;
    Button num9;
    Button deleteAll;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.screen_lock);

        resultView = (TextView) findViewById(R.id.numResult);
        num1 = (Button) findViewById(R.id.num1);
        num2 = (Button) findViewById(R.id.num2);
        num3 = (Button) findViewById(R.id.num3);
        num4 = (Button) findViewById(R.id.num4);
        num5 = (Button) findViewById(R.id.num5);
        num6 = (Button) findViewById(R.id.num6);
        num7 = (Button) findViewById(R.id.num7);
        num8 = (Button) findViewById(R.id.num8);
        num9 = (Button) findViewById(R.id.num9);
        deleteAll = (Button) findViewById(R.id.deleteAll);

        num1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TypePassword(1);
            }
        });
        num2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TypePassword(2);
            }
        });
        num3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TypePassword(3);
            }
        });
        num4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TypePassword(4);
            }
        });
        num5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TypePassword(5);
            }
        });
        num6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TypePassword(6);
            }
        });
        num7.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TypePassword(7);
            }
        });
        num8.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TypePassword(8);
            }
        });
        num9.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TypePassword(9);
            }
        });
        deleteAll.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                countOfInput = 0;
                inputPw = "";
                st = "";
                resultView.setText(st);
            }
        });
    }


    public void TypePassword(int _pw){
        inputPw +=  String.valueOf(_pw);

        countOfInput++;
        st += "*";
        resultView.setText(st);

        if (countOfInput == 4){

            if(PASSWORD.equals(inputPw)){
                sendResult();
            }else{
                Toast.makeText(getApplicationContext(), "비밀번호가 틀렸습니다.", Toast.LENGTH_SHORT).show();
                inputPw = "";
                st = "";
                countOfInput = 0;
            }
        }
    }

    public void sendResult() {
        Intent resultIntent = new Intent();
        resultIntent.putExtra("ok", true);
        setResult(1, resultIntent);
        Toast.makeText(getApplicationContext(), "DONE", Toast.LENGTH_SHORT).show();
        finish();
    }

}
