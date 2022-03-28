package edu.niu.z1811457.portfolio15;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Point;
import android.os.Bundle;
import android.text.InputType;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.ScaleAnimation;
import android.widget.Button;
import android.widget.EditText;
import android.widget.GridLayout;
import android.widget.ScrollView;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;

import java.util.ArrayList;

public class UpdateActivity extends AppCompatActivity {

    private DataBaseManager dataBaseManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        //create the database
        dataBaseManager = new DataBaseManager(this);

        updateView();
    }//end onCreate

    //method to handle generating the view
    public void updateView() {
        //get tall the candy info from the database
        ArrayList<Candy> candies = dataBaseManager.selectAll();

        //if there is info in the database
        if(candies.size() > 0) {
            ScrollView scrollView = new ScrollView(this);
            GridLayout gridLayout = new GridLayout(this);

            //set the rows and columns for the grid
            gridLayout.setRowCount(candies.size() + 1);
            gridLayout.setColumnCount(4);

            //find the width of the screen
            Point point = new Point();
            getWindowManager().getDefaultDisplay().getSize(point);

            int width = point.x;

            //create a custom button handler
            ButtonHandler buttonHandler = new ButtonHandler();

            //process all the candies in the array list
            for (Candy candy : candies) {
                //format the ID number for the candy
                TextView idTV = new TextView(this);
                idTV.setGravity(Gravity.CENTER);
                idTV.setText("" + candy.getId());

                //format the name of the candy
                EditText name = new EditText(this);
                name.setText(candy.getName());
                name.setId(candy.getId() * 69);

                //format the price of the candy
                EditText price = new EditText(this);
                price.setText("" + candy.getPrice());
                price.setId(candy.getId() * 69 + 69);
                price.setInputType(InputType.TYPE_NUMBER_FLAG_DECIMAL);

                //update button
                Button updateButton = new Button(this);
                updateButton.setText(R.string.update_button_label);
                updateButton.setId(candy.getId());
                updateButton.setOnClickListener(buttonHandler);

                //add the 4 objects to the grid
                gridLayout.addView(idTV, (int)(width * 0.1), ViewGroup.LayoutParams.WRAP_CONTENT);
                gridLayout.addView(name, (int)(width * 0.4), ViewGroup.LayoutParams.WRAP_CONTENT);
                gridLayout.addView(price, (int)(width * 0.15), ViewGroup.LayoutParams.WRAP_CONTENT);
                gridLayout.addView(updateButton, (int)(width * 0.35), ViewGroup.LayoutParams.WRAP_CONTENT);
            }//end for loop

            //populate the last row of the grid with a back button
            Button backButton = new Button(this);
            backButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    finish();
                }
            });

            //set up the layout for the
            GridLayout.Spec rowSpec = GridLayout.spec(candies.size(), 1),
                            colSpec = GridLayout.spec(0, 4);

            GridLayout.LayoutParams layoutParams = new GridLayout.LayoutParams(rowSpec, colSpec);

            //apply the parameters to the backButton
            backButton.setLayoutParams(layoutParams);

            //set the width and height for the button
            backButton.setWidth(width);
            backButton.setHeight((int)(width * 0.1));

            //this step is optional (if it takes up the whole width)
            backButton.setGravity(Gravity.CENTER);

            backButton.setText(R.string.back_button_label);

            //add the back button to the grid layout
            gridLayout.addView(backButton);

            //add the grid layout to the scrollview
            scrollView.addView(gridLayout);

            //display the scrollview
            setContentView(scrollView);
        }//end if
    }//end updateView

    //inner class to handle button clicks
    private class ButtonHandler implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            //get the id number of the button that was clicked
            int candyID = v.getId();

            //editText fields for the name and the price fields
            EditText nameET = findViewById(candyID * 69),
                     priceET = findViewById(candyID * 69 + 69);

            //get the info from the edittext
            String name = nameET.getText().toString();
            String price = priceET.getText().toString();

            try {
                //get the numeric value from the strong holding the price
                double priceVal = Double.parseDouble(price);

                //update the database
                dataBaseManager.updateByID(candyID, name, priceVal);


                //update the display on the screen
                updateView();
            }
            catch(NumberFormatException nfe) {
                Toast.makeText(UpdateActivity.this, "Update Price Error", Toast.LENGTH_LONG).show();
            }
        }//end onClick
    }//end ButtonHandler
}//end UpdateActivity