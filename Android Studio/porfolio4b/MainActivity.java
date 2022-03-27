package edu.niu.z1811457.porfolio4b;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.Preference;
import android.preference.PreferenceManager;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity
{
    static final int NAME_CODE = 3;
    private TextView nameTV;

    //optional to save info (shared preferences - save name as part of app)

    static final String SAVED_NAME_KEY = "oldName",
                        DEFAULT_NAME = "none";

    private SharedPreferences preferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //connect the textView
        nameTV = findViewById(R.id.nameTextView);

        //optional - retrieve the shared preferences
        preferences = PreferenceManager.getDefaultSharedPreferences(this);

        //optional - get the saved name from the shared preferences
        String savedName = preferences.getString(SAVED_NAME_KEY, DEFAULT_NAME);

        //optional - test to see if name has been retrieved. if the saved name is not "none", display in the textview
        if ( !savedName.equals(DEFAULT_NAME) )
        {
         nameTV.setText("The last name that was entered was " + savedName);
        }

    }//end onCreate

    //method to handle the button click - go to NameActivity to get the name
    public void getName(View view)
    {
        //create te intent to go to NameActivity
        Intent nameIntent = new Intent(MainActivity.this, NameActivity.class);

        //go to NameActivity
        startActivityForResult(nameIntent, NAME_CODE);
    }//end getName


    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data)
    {
        super.onActivityResult(requestCode, resultCode, data);

        String returnedName;

        if ( requestCode == NAME_CODE && resultCode == RESULT_OK )
        {
            //get the returned from the intent
            returnedName = data.getStringExtra( "nameID");

            //put the name in the textView
            nameTV.setText("Your name is " + returnedName);

            //optional - save the name in the shared preferences
            SharedPreferences.Editor editor = preferences.edit(); //retrieves edittor

            //optional - put the name into the preferences
            editor.putString(SAVED_NAME_KEY, returnedName);
            editor.commit(); //commits the edit that was done (like git commit)
        }
    }//end onActivityResult
}//end MainActivity