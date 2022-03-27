package edu.niu.z1811457.portfolio3;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.RadioGroup;
import android.widget.SeekBar;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity
{

    private RadioGroup pattyRadioGroup, cheeseRadioGroup;
    private TextView caloriesTV;

    private Boorger boorger;

    private CheckBox baconCB;

    private SeekBar sauceSeekBar;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //create the Burger object
        boorger = new Boorger();

        //connect the variables with the objects on the screen
        pattyRadioGroup = findViewById(R.id.pattyRadioGroup);
        caloriesTV = findViewById(R.id.caloriesTextView);
        baconCB = findViewById(R.id.baconCheckBox);
        cheeseRadioGroup = findViewById(R.id.cheeseRadioGroup);
        sauceSeekBar = findViewById(R.id.sauceSeekBar);

        //display the initial number of calories
        displayCalories();

        //attach a named listener to the patty radio group
        pattyRadioGroup.setOnCheckedChangeListener( pattyListener );

        //this CB can be an anonymous one or a named listener.
        //attach a named listener to the bacon checkbox
        baconCB.setOnClickListener( baconListener );

        //attach an anonymous listener to the cheese radio group
        cheeseRadioGroup.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId)
            {
                switch ( checkedId )
                {
                    case R.id.noCheeseRadioButton:
                        boorger.setCheeseCalories(0);
                        break;

                    case R.id.cheddarRadioButton:
                        boorger.setCheeseCalories(boorger.CHEDDAR);
                        break;

                    case R.id.mozzarellaRadioButton:
                        boorger.setCheeseCalories(boorger.MOZZARELLA);
                        break;
                }//end switch

                //you can add an error checking thing here
                displayCalories();

            }
        });//end cheeseRadioGroup

        //attach a named listener to the seekBar
        sauceSeekBar.setOnSeekBarChangeListener( sauceListener );

    }//end onCreate

    //Listener to handle sauce amount
    private SeekBar.OnSeekBarChangeListener sauceListener = new SeekBar.OnSeekBarChangeListener() {
        @Override
        public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser)
        {
            boorger.setSauceCalories( seekBar.getProgress() );
            displayCalories();
        }//end onProgressChanged

        @Override
        public void onStartTrackingTouch(SeekBar seekBar)
        {

        }//end onStartTrackingTouch

        @Override
        public void onStopTrackingTouch(SeekBar seekBar)
        {

        }//end onStopTrackingTouch
    };

    //Listener to handle patty selection
    private RadioGroup.OnCheckedChangeListener pattyListener = new RadioGroup.OnCheckedChangeListener()
    {
        @Override
        public void onCheckedChanged(RadioGroup group, int checkedId) {
            switch (checkedId) {
                case R.id.beefRadioButton:
                    boorger.setPattyCalories(Boorger.BEEF);
                    break;

                case R.id.turkeyRadioButton:
                    boorger.setPattyCalories(Boorger.TURKEY);
                    break;

                case R.id.veggieRadioButton:
                    boorger.setPattyCalories(Boorger.VEGGIE);
                    break;
            }

            //update the displayed calorie count
            displayCalories();
        }
    };//end pattyListener

    //Listener to handle bacon
    private View.OnClickListener baconListener = new View.OnClickListener() {
        @Override
        public void onClick(View v)
        {
            if ( ((CheckBox)v).isChecked() ) //baconCB.isChecked() <-- this also works on this line
            {
                boorger.setBaconCalories(true);
            }
            else
            {
                boorger.setBaconCalories(false);
            }

            displayCalories(); //updates calories
        }//end onClick
    };//end baconListener

    //method to update the number of calories
    private void displayCalories()
    {
        String caloriesOutput = "Calories: " + boorger.getTotalCalories();
        caloriesTV.setText(caloriesOutput);
    }//end displayCalories

}//end MainActivity