package edu.niu.z1811457.porfolio4b;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class NameActivity extends AppCompatActivity
{

    private EditText nameET;


    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_name);

        //connect the object to the item on the screen
        nameET = findViewById(R.id.editTextName);

        //optional - request focus on the editText
        nameET.requestFocus();
    }//end onCreate

    //method to handle the button click = return the name to MainActivity
    public void returnName(View view)
    {
        //Get the name from the editText
        String inputName;
        inputName = nameET.getText().toString();    //saves it as a string value

        //can add an error checker to see if something is passed.

        //Retrieve the intent that called the NameActivity
        Intent intent;
        intent = getIntent();

        //Put the name into the intent
        intent.putExtra( "nameID", inputName);

        //set the result code to success
        setResult(RESULT_OK, intent);

        //return to MainActivity
        finish();
    }//end returnName



}//end NameActivity