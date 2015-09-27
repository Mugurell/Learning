package com.example.mugurel.myapplication;

import android.app.Activity;
import android.content.Context;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {
    private final String TAG = "MainActivity";
    private Context context = MainActivity.this;
    private TextView tv;
    private Button btn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {//constructor method
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.e(TAG, "OnCreate");

        tv = (TextView) findViewById(R.id.text_view);
        tv.setText("ce faci bah");

        btn = (Button) findViewById(R.id.button);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(context, "hahaha", Toast.LENGTH_SHORT).show();
            }
        });
    }

    @Override
    protected void onStart() {
        super.onStart();//se apeleaza dupa oncreate, activitatea e vizibila
        Log.e(TAG, "onStart");
    }

    @Override
    protected void onResume() {
        super.onResume();//focus
        Log.e(TAG, "onResume");
    }

    @Override
    protected void onPause() {
        super.onPause();//nu are focus, dar e vizibila
        Log.e(TAG, "onPause");
    }

    @Override
    protected void onStop() {
        super.onStop();//nu e vizibila
        Log.e(TAG, "onStop");
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Log.e(TAG, "onDestroy");
    }
}
