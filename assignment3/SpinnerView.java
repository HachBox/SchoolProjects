package edu.niu.z1811457.assignment3;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.text.method.ScrollingMovementMethod;
import android.view.View;
import android.widget.TextView;

public class SpinnerView extends AppCompatActivity {

    private TextView carTV;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.spinner_view);

        carTV = findViewById(R.id.carTextView);

        Bundle b = getIntent().getExtras();

        carTV = findViewById(R.id.carTextView);

        //set the textview to have the keyword for receiving
        carTV.setText(b.getString("stats"));

        //allow the text view to be scrollable
        carTV.setMovementMethod(new ScrollingMovementMethod());
    }


    public void goBack( View view )
    {
        //return to the main activity
        finish(); //this returns to the main activity
    }//end goBack
}