package edu.niu.z1811457.portfolio8;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;

import java.util.Timer;
import java.util.TimerTask;

public class SplashActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash);

        //Create the timertask object for displaying the splash screen and going to MainActivity
        TimerTask timerTask = new TimerTask() {
            @Override
            public void run() {
                //finish the splash activity execution
                finish();

                //Goto the main activity
                Intent mainIntent = new Intent(SplashActivity.this, MainActivity.class);
                startActivity(mainIntent);
            }
        }; //end TimerTask

        //setup the timer for how long the splash screen should display
        Timer timer = new Timer();

        timer.schedule(timerTask, 2000);
    }//end onCreate
}//end SplashActivity
