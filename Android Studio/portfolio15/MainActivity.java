package edu.niu.z1811457.portfolio15;

import android.content.Intent;
import android.os.Bundle;

import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.view.View;

import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

public class
MainActivity extends AppCompatActivity {

    private DataBaseManager databaseManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG).setAction("Action", null).show();
            //Intent to go to the help activity
                Intent helpIntent = new Intent(MainActivity.this, HelpActivity.class);

                //go to the help activity
                startActivity(helpIntent);
            }
        });
    }//end onCreate

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }//end onCreateOptionsMenu

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_add) {
            //Toast.makeText(MainActivity.this, "ADD selection made", Toast.LENGTH_SHORT).show();
            Intent insertIntent = new Intent(MainActivity.this, InsertActivity.class);
            startActivity(insertIntent);
            return true;
        }
        else if (id == R.id.action_edit) {
            //Toast.makeText(MainActivity.this, "EDIT selection made", Toast.LENGTH_SHORT).show();
            Intent updateIntent = new Intent(MainActivity.this, UpdateActivity.class);
            startActivity(updateIntent);
            return true;
        }
        else if (id == R.id.action_delete) {
            //Toast.makeText(MainActivity.this, "DELETE selection made", Toast.LENGTH_SHORT).show();
            Intent deleteIntent = new Intent(MainActivity.this, DeleteActivity.class);
            startActivity(deleteIntent);
            return true;
        }

        return super.onOptionsItemSelected(item);
    }//end onOptionsItemSelected

    @Override
    protected void onResume() {
        super.onResume();
        updateScreen();
    }//end onResume

    //method to update the display on the screen
    public void updateScreen() {
        String databaseString;

        //create the database
        databaseManager = new DataBaseManager(this);

        //initial value for the string of database information
        databaseString = "Candies in the database\n\n";

        //Get the information from the database
        ArrayList<Candy> candies = databaseManager.selectAll();

        //Loop through the array list and add the candies to the string
        for ( Candy candy : candies) {
            databaseString += candy.candyToString() + "\n";
        }

        //create a textview and connect it to the object on content_main.xml
        TextView databaseTV = findViewById(R.id.databaseTextView);

        //put the string object into the textview
        databaseTV.setText(databaseString);
    }
}//end MainActivity