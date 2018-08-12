package com.xiaoxiyouran.myapplication;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    private Button mButtonEditText;                                     // 1- 声明这个控件

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        mButtonEditText = (Button) findViewById(R.id.btn_edittext);     // 2- 在 activity_main 中找到这个控件
        mButtonEditText.setOnClickListener(new View.OnClickListener() { // 3- 添加监听事件
            @Override
            public void onClick(View v) {
                // 界面跳转
                Intent intent = new Intent(MainActivity.this, EditTextActivity.class);
                startActivity(intent);
            }
        });

    }
}
