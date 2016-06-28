package com.example.minseok.ht;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;

public class HT_VideoAcitivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ht__video_acitivity);
    }

    public void OpenIt(View v)
    {
        Intent sender  = new Intent(getBaseContext() ,HT_VideoSubActivity.class);

        switch (Integer.valueOf(v.getTag().toString()))
        {
            case 1:
                sender.putExtra("name", "사철가");
                sender.putExtra("link", "https://www.youtube.com/embed/sfl3l2lV78A");
                break;
            case 2:
                sender.putExtra("name", "영재국악회");
                sender.putExtra("link", "https://www.youtube.com/embed/LGjwXSpsPRE");
                break;
            case 3:
                sender.putExtra("name", "허니데이");
                sender.putExtra("link", "https://www.youtube.com/embed/GbzGRoPNgAY");
                break;
            case 4:
                sender.putExtra("name", "창신제");
                sender.putExtra("link", "https://www.youtube.com/embed/BqnKcyjNvzg");
                break;
            default:
                // Error
                break;
        }

        startActivity(sender);

    }
}
