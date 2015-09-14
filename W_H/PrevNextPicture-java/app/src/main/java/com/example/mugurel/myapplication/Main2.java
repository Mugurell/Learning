package com.example.mugurel.myapplication;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.ImageView;

/**
 * Created by mugurel on 13.09.2015.
 */

public class Main2 extends Activity {
    private Context context = Main2.this;
    int count = 0;
    int[] poze = {R.drawable.poza, R.drawable.poza2};

    // trebuie sa imi declar butoanele din xml, cu ce lucrez eu aici
    Button prev;
    Button next;
    ImageView poza;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main2); // ca sa incarce layout-ul

        prev = (Button) findViewById(R.id.prev);
        next = (Button) findViewById(R.id.next);
        poza = (ImageView) findViewById(R.id.poza);
    }

    // vreau sa returneze id-ul urmatoarei poze
    // orice! id pt orice! resursa e un int !!!!
    private void onClickNext() {
        if (count == 0)
            count++;

        Intent intent = new Intent(context, Main2.class);
        startActivity(intent);
        ImageView mImageView = (ImageView) findViewById(count);
    }

    private void onClickPrev() {
        if (count == 1)
            count--;

        Intent intent = new Intent(context, Main2.class);
        startActivity(intent);
        ImageView mImageView = (ImageView) findViewById(poze[count]);
    }

}
