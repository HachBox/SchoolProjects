package edu.niu.z1811457.portfolio11;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity implements ButtonFragment.OnItemSelectedListener{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    public void onShadeItemSelected(String colorInfo) {
    //get the information fragment
    InformationFragment informationFragment = (InformationFragment)getSupportFragmentManager().findFragmentById(R.id.infoFragment);

    //if the information fragment is in the layout, then orientation is landscape
        if(informationFragment != null && informationFragment.isInLayout()) {
            //use the setText method that is part of the informationFragment to display the string argument
            informationFragment.setText(colorInfo);
        }
        else {
            Intent infoIntent = new Intent(this, InformationActivity.class);
            //put the string argument into the intent
            infoIntent.putExtra("Info", colorInfo);

            //start the Information activity
            startActivity(infoIntent);
        }

    }//end onShadeItemSelected
}