package edu.niu.z1811457.midterm;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.text.DecimalFormat;

public class InToCm extends AppCompatActivity {

    private EditText inputET;

    private TextView outputTV;

    private Button convertBtn;

    //Constants
    static final Double BASE_INPUT = 0.000;
    static final Double BASE_OUTPUT = 0.000;

    //Instance variables
    private Double inputAmt, outputAmt;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_in_to_cm);

        inputET = findViewById(R.id.inputEditText);

        outputTV = findViewById(R.id.outputTextView);

        convertBtn = findViewById(R.id.convertButton);

        convertBtn.setOnClickListener( convertListener );
    }
    private View.OnClickListener convertListener = new View.OnClickListener() {
        @Override
        public void onClick(View view) {
            Double num, result;

            if( inputET.getText().toString().matches("") || inputET.getText().toString().matches(""))
            {
                //display an error message/toast message
                Toast.makeText( view.getContext(), "The number fields cannot be empty", Toast.LENGTH_SHORT ).show();
                return;
            }

            num = Double.parseDouble( inputET.getText().toString() );

            DecimalFormat decimalFormat = new DecimalFormat("#0.000");

            switch(view.getId()) {
                case R.id.convertButton:
                    result = num * 2.540;
                    outputTV.setText(decimalFormat.format(result));
                    break;
            }
        }
    };

    public void goBack( View view )
    {
        //return to the main activity
        finish(); //this returns to the main activity
    }//end goBack
}