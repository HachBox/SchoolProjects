package edu.niu.z1811457.portfolio1;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity
{
    private EditText num1ET, num2ET;
    private Button addBtn, subBtn, multiBtn, divBtn, clearBtn;
    private TextView answerTV;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Connect the variable with the items on the screen
        num1ET = findViewById(R.id.num1EditText);
        num2ET = findViewById(R.id.num2EditText);

        addBtn = findViewById(R.id.addButton);
        subBtn = findViewById(R.id.subtractButton);
        multiBtn = findViewById(R.id.multiButton);
        divBtn = findViewById(R.id.divButton);
        clearBtn = findViewById(R.id.clearButton);

        answerTV = findViewById(R.id.answerTextView);

        //attach a named listner to the arithmetic buttons
        addBtn.setOnClickListener( mathListener );
        subBtn.setOnClickListener( mathListener );
        multiBtn.setOnClickListener( mathListener );
        divBtn.setOnClickListener( mathListener );

        /*
        divBtn.setOnClickListener( new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                Integer num1, num2, result;

                if(num2 == 0)
                {
                    //set the 2 edittext fields and the answer field to empty string
                    num1ET.setText("");
                    num2ET.setText("");
                    answerTV.setText("");
                    //put the focus on the first number field
                    num1ET.requestFocus();
                }
                else
                    {
                    result = num1 / num2;
                    Toast.makeText(view.getContext(), "Add button pushed", Toast.LENGTH_SHORT);
                    break;
                    }
            }
        }); //end setOnClickListener
        */

        //attach an anonymous listener to the clear button
        clearBtn.setOnClickListener( new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                //set the 2 edittext fields and the answer field to empty string
                num1ET.setText("");
                num2ET.setText("");
                answerTV.setText("");

                //put the focus on the first number field
                num1ET.requestFocus();
            }
        }); //end setOnClickListener
    }//end onCreate

    private View.OnClickListener mathListener = new View.OnClickListener()
    {
        @Override
        public void onClick(View view) //view is the button that was clicked
        {
            //Variables to handle the math
            Integer num1, num2, result;

            //Error check - check for values in the EditText fields
            if( num1ET.getText().toString().matches("") || num2ET.getText().toString().matches(""))
            {
                //display an error message/toast message
                Toast.makeText( view.getContext(), "The number fields cannot be empty", Toast.LENGTH_SHORT ).show();
                return;
            }

            //Get the information from the edittext fields
            num1 = Integer.parseInt( num1ET.getText().toString() );
            num2 = Integer.parseInt( num2ET.getText().toString() );

            //determine what arithmetic needs to be performed - based on the button that was clicked
            switch (view.getId())
            {
                case R.id.addButton:
                    result = num1 + num2;
                    //optional, know which button is pushed (for testing phase)
                    Toast.makeText(view.getContext(), "Add button pushed", Toast.LENGTH_SHORT).show();
                    break;

                case R.id.subtractButton:
                    result = num1 - num2;
                    //optional, know which button is pushed (for testing phase)
                    Toast.makeText(view.getContext(), "Subtract button pushed", Toast.LENGTH_SHORT).show();
                    break;

                case R.id.multiButton:
                    result = num1 * num2;
                    Toast.makeText(view.getContext(), "Multiplication button pushed", Toast.LENGTH_SHORT).show();
                    break;

                case R.id.divButton:
                    Toast.makeText(view.getContext(), "Division button pushed", Toast.LENGTH_SHORT).show();
                    result = num1 / num2;
                    break;

                default:
                    Toast.makeText(view.getContext(), "Oops", Toast.LENGTH_SHORT);
                    return;
            }//end switch

            //Display the result
            answerTV.setText(result.toString());

        }//end mathListener onClick
    };//end mathListener

}//end MainActivity