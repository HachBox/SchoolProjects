package edu.niu.z1811457.portfolio15;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.provider.MediaStore;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.RelativeLayout;
import android.widget.ScrollView;
import android.widget.Toast;

import java.util.ArrayList;

public class DeleteActivity extends AppCompatActivity {

    private DataBaseManager dataBaseManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);

        //create the database
        dataBaseManager = new DataBaseManager(this);

        //display the contents of the database
        updateView();
    }//end onCreate

    //method to display the contents of the database
    public void updateView() {
        //get the info from the database
        ArrayList<Candy> candies = dataBaseManager.selectAll();

        //layout
        RelativeLayout layout = new RelativeLayout(this);
        ScrollView scrollView = new ScrollView(this); //can only  hold one view inside of it
        RadioGroup group = new RadioGroup(this);

        //populate the radiogroup with radio buttons
        for (Candy candy : candies) {
            //create an individual radio button
            RadioButton radioButton = new RadioButton(this);

            //set the id number for the radio button
            radioButton.setId(candy.getId());

            //set the text that is displayed with the radiobutton
            radioButton.setText(candy.candyToString());

            //add the radio button to the radio group
            group.addView(radioButton);
        }//end for loop

        //handle clicking the radio buttons
        RadioButtonHandler handler = new RadioButtonHandler();
        //attach the handler to the radio group
        group.setOnCheckedChangeListener(handler);

        //add the radio group to the scroll view (one level of nesting)
        scrollView.addView(group);

        //add the scrollView to the relative layout
        layout.addView(scrollView);

        //add a back button
        Button backButton = new Button(this);
        backButton.setText(R.string.back_button_label);

        backButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });

        //set up the formatting to place the back button under the scrollview
        RelativeLayout.LayoutParams params =
                new RelativeLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);

        params.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
        params.addRule(RelativeLayout.CENTER_HORIZONTAL); //optional
        params.setMargins(0,0,0, 50);

        //add the back button to the relative layout using the parameters
        layout.addView(backButton, params);

        //display the relative layout
        setContentView(layout);
    }//end updateView

    //Inner class to handle the radio button clicks
    private class RadioButtonHandler implements RadioGroup.OnCheckedChangeListener {
        @Override
        public void onCheckedChanged(RadioGroup radioGroup, int checkedId) {
            dataBaseManager.deleteByID(checkedId);
            Toast.makeText(DeleteActivity.this, "Candy deleted", Toast.LENGTH_LONG).show();
            updateView();
        }
    }//end RadioGroupHandler
}//end DeleteActivity