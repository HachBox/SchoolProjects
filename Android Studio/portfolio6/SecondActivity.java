package edu.niu.z1811457.portfolio6;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

public class SecondActivity extends AppCompatActivity {

    private String createMsg2, startMsg2, resumeMsg2, pauseMsg2, stopMsg2, restartMsg2, destroyMsg2;

    private static final String SA_TAG = "2ndActivity LifeCycle";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        //populate the 7 string objects from strings.xml
        createMsg2 = (String)getResources().getText(R.string.create_msg2);
        startMsg2 = (String)getResources().getText(R.string.start_msg2);
        resumeMsg2 = (String)getResources().getText(R.string.resume_msg2);
        pauseMsg2 = (String)getResources().getText(R.string.pause_msg2);
        stopMsg2 = (String)getResources().getText(R.string.stop_msg2);
        restartMsg2 = (String)getResources().getText(R.string.restart_msg2);
        destroyMsg2 = (String)getResources().getText(R.string.destroy_msg2);

        //display a Toast message and a Log message
        Toast.makeText(getApplicationContext(), createMsg2, Toast.LENGTH_LONG).show();

        Log.d(SA_TAG, createMsg2);
    }//end onCreate

    @Override
    protected void onStart() {
        super.onStart();
        Toast.makeText(getApplicationContext(), startMsg2, Toast.LENGTH_SHORT).show();

        Log.d(SA_TAG, startMsg2);
    }

    @Override
    protected void onResume() {
        super.onResume();
        Toast.makeText(getApplicationContext(), resumeMsg2, Toast.LENGTH_SHORT).show();

        Log.d(SA_TAG, resumeMsg2);
    }

    @Override
    protected void onPause() {
        super.onPause();
        Toast.makeText(getApplicationContext(), pauseMsg2, Toast.LENGTH_SHORT).show();

        Log.d(SA_TAG, pauseMsg2);
    }

    @Override
    protected void onStop() {
        super.onStop();
        Toast.makeText(getApplicationContext(), stopMsg2, Toast.LENGTH_SHORT).show();

        Log.d(SA_TAG, stopMsg2);
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        Toast.makeText(getApplicationContext(), restartMsg2, Toast.LENGTH_SHORT).show();

        Log.d(SA_TAG, restartMsg2);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Toast.makeText(getApplicationContext(), destroyMsg2, Toast.LENGTH_SHORT).show();

        Log.d(SA_TAG, destroyMsg2);
    }

    public void goMain(View view) {

        finish();
    }
}