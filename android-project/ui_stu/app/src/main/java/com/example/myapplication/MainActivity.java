package com.example.myapplication;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.example.myapplication.uistu.viewstu.customizeview.way1.UiStuCustomizeView1Activity;

public class MainActivity extends AppCompatActivity {
    private final String TAG = getClass().getName();
    int buttonSize = 1;
    Button[] buttons = new Button[buttonSize];

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        registerMyStuButton();
    }

    private void registerMyStuButton() {
        buttons[0] = findViewById(R.id.bt_stu_ui_run_customizeview1_act);
        for(int i=0;i<buttonSize;i++){
            buttons[i].setOnClickListener(listener);
        }
    }

    View.OnClickListener listener = new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            Intent intent = new Intent();
            switch (v.getId()) {
                case R.id.bt_stu_ui_run_customizeview1_act:
                    intent.setClass(getApplicationContext(), UiStuCustomizeView1Activity.class);
                    startActivity(intent);
                    break;
                default:
                    break;
            }
        }
    };
}
