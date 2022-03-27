package edu.niu.z1811457.portfolio2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import java.text.DecimalFormat;

public class MainActivity extends AppCompatActivity
{

    //Instance Variables
    private ShippingItem item;

    private EditText weightEditText;

    private TextView baseTV, addedTV, totalTV;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //connect the variables with the items on the screen
        weightEditText = findViewById(R.id.weightEditText);

        baseTV = findViewById(R.id.baseCostTextView);
        addedTV = findViewById(R.id.addedCostTextView);
        totalTV = findViewById(R.id.totalCostTextView);

        //Create the shipping item
        item = new ShippingItem();

        //make sure the cursor is in the EditTetxt field
        weightEditText.requestFocus();

        //add a TextChangedListener to the EditText field
        weightEditText.addTextChangedListener( weightWatcher );
    }//end onCreate

    private TextWatcher weightWatcher = new TextWatcher() {
        @Override
        public void beforeTextChanged(CharSequence s, int start, int count, int after)
        {

        }

        @Override
        public void onTextChanged(CharSequence s, int start, int before, int count)
        {
        //get the info that is in the charSequence
            try
            {
                item.setWeight( Integer.parseInt(s.toString()) );
            }
            catch (NumberFormatException nfe)
            {
                item.setWeight(0);
            }

            //Create the formatted costs
            DecimalFormat decimalFormat = new DecimalFormat( "#0.00" );

            //put the costs in the textViews
            baseTV.setText("$" + decimalFormat.format(item.getBaseCost()));
            addedTV.setText("$" + decimalFormat.format(item.getAddedCost()));
            totalTV.setText("$" + decimalFormat.format(item.getTotalCost()));
        }//end onTextChanged

        @Override
        public void afterTextChanged(Editable s)
        {

        }
    };

    //method to handle the button click to get application help (goHelp)
    public void goHelp( View view )
    {
        //create an intent that will go to the help activity
        Intent halp = new Intent(MainActivity.this, HelpActivity.class);

        //go to the help activity
        startActivity(halp);
    }//end goHelp

}//end MainActivity