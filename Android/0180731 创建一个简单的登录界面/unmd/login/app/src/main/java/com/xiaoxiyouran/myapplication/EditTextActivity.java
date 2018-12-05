package com.xiaoxiyouran.myapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class EditTextActivity extends AppCompatActivity {

    //    为登录按钮设置一个点击事件
    private Button mBtnLogin;   // 1- 声明这个控件

    private EditText mEtUserName;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit_text);

        mBtnLogin = (Button) findViewById(R.id.btn_login);   // 2- 获取按钮

        mBtnLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(EditTextActivity.this, "登录成功"/*显示的文字*/, Toast.LENGTH_SHORT/*显示的时间*/).show(); // 必须调用 show() 才会显示成功
            }
        });

        mEtUserName = (EditText) findViewById(R.id.et_1);
        // 添加内容变化时的监听事件
        mEtUserName.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                Log.d("edittext", s.toString());    // 打印内容

            }

            @Override
            public void afterTextChanged(Editable s) {

            }
        });

    }
}
