package edu.niu.z1811457.portfolio2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;

public class HelpActivity extends AppCompatActivity
{

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_help);


    }//end onCreate

    //method to handle the button click (goBack)

    public void goBack( View view )
    {
        //return to the main activity
        finish(); //this returns to the main activity
    }//end goBack

}//end HelpActivity