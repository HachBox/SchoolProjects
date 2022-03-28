package edu.niu.z1811457.portfolio6;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private String createMsg, startMsg, resumeMsg, pauseMsg, stopMsg, restartMsg, destroyMsg;

    private static final String MA_TAG= "MainActivity LifeCycle";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //populate the 7 string objects from strings.xml
        createMsg = (String)getResources().getText(R.string.create_msg);
        startMsg = (String)getResources().getText(R.string.start_msg);
        resumeMsg = (String)getResources().getText(R.string.resume_msg);
        pauseMsg = (String)getResources().getText(R.string.pause_msg);
        stopMsg = (String)getResources().getText(R.string.stop_msg);
        restartMsg = (String)getResources().getText(R.string.restart_msg);
        destroyMsg = (String)getResources().getText(R.string.destroy_msg);

        //display a Toast message and a Log message
        Toast.makeText(getApplicationContext(), createMsg, Toast.LENGTH_LONG).show();

        Log.d(MA_TAG, createMsg);
    }//end onCreate

    @Override
    protected void onStart() {
        super.onStart();
        Toast.makeText(getApplicationContext(), startMsg, Toast.LENGTH_SHORT).show();

        Log.d(MA_TAG, startMsg);
    }

    @Override
    protected void onResume() {
        super.onResume();
        Toast.makeText(getApplicationContext(), resumeMsg, Toast.LENGTH_SHORT).show();

        Log.d(MA_TAG, resumeMsg);
    }

    @Override
    protected void onPause() {
        super.onPause();
        Toast.makeText(getApplicationContext(), pauseMsg, Toast.LENGTH_SHORT).show();

        Log.d(MA_TAG, pauseMsg);
    }

    @Override
    protected void onStop() {
        super.onStop();
        Toast.makeText(getApplicationContext(), stopMsg, Toast.LENGTH_SHORT).show();

        Log.d(MA_TAG, stopMsg);
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        Toast.makeText(getApplicationContext(), restartMsg, Toast.LENGTH_SHORT).show();

        Log.d(MA_TAG, restartMsg);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Toast.makeText(getApplicationContext(), destroyMsg, Toast.LENGTH_SHORT).show();

        Log.d(MA_TAG, destroyMsg);
    }

    public void doSecond(View view) {
        Intent secondIntent = new Intent(MainActivity.this, SecondActivity.class);

        //go to second activity
        startActivity(secondIntent);
    }
}