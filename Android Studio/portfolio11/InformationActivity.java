package edu.niu.z1811457.portfolio11;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.content.res.Configuration;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import org.w3c.dom.Text;

public class InformationActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        //check if the device is in landscape orientation and exit if it is
        if(getResources().getConfiguration().orientation == Configuration.ORIENTATION_LANDSCAPE) {
            finish();
            //go back to the MainActivity and skip the remaining life cycle methods
            return;
        }

        //set up the layout using the information fragment
        setContentView(R.layout.fragment_information);

        //get the intent that is used to call this activity and the information that it holds
        Intent intent = getIntent();

        String colorString = intent.getStringExtra("Info");

        //display the string in the textview that is part of the information fragment
        TextView colorTV = findViewById(R.id.colorInfoTextView);
        colorTV.setText(colorString);

        //Make the button visible
        Button backBtn = findViewById(R.id.backButton);
        backBtn.setVisibility(View.VISIBLE);

        //Handle the button click
        backBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //go back to the main activity
                finish();

                //make the button invisible
                view.setVisibility(View.INVISIBLE);
            }
        });
    }//end onCreate
}//end InfoActivity