package edu.niu.z1811457.portfolio13;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.FrameLayout;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Connect the layout on the screen with a frame latyout object
        FrameLayout layout = findViewById(R.id.drawingLayout);

        //Create the surface view that will be drawn on (where the bakk will be bouncing)
        BounceSurfaceView bounceSurfaceView = new BounceSurfaceView(this);

        //add the surface view to the layout
        layout.addView(bounceSurfaceView);
    }//end onCreate
}//end MainActivity