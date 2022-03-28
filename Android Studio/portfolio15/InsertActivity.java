package edu.niu.z1811457.portfolio15;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class InsertActivity extends AppCompatActivity {

    private DataBaseManager dataBaseManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_insert);

        //create the database
        dataBaseManager = new DataBaseManager(this);
    }//end onCreate

    //Methods to handle the button clicks
    public void goBack(View view) {
        finish();
    }//end goBack method

    public void addItem(View view) {
        //connect to the editText fields on the screen
        EditText itemNameET = findViewById(R.id.itemNameEditText),
                 itemPriceET = findViewById(R.id.itemPriceEditText);

        //retrieve the info from the editText fields
        String itemName = itemNameET.getText().toString(),
               itemPrice = itemPriceET.getText().toString();

        try {
            //converty the price string to a double value
            double price = Double.parseDouble(itemPrice);

        //Create the candy object to insert into the database
            Candy newItem = new Candy(0, itemName, price);

            //Insert the candy object into the database
            dataBaseManager.insertCandy(newItem);
        }
        catch (NumberFormatException nfe) {
            Toast.makeText(this, "Price error", Toast.LENGTH_LONG).show();
        }

        //clear the editText fields
        itemNameET.setText("");
        itemPriceET.setText("");

        //move the focus to the name editText
        itemNameET.requestFocus();
    }//end addItem method
}