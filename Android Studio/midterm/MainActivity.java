package edu.niu.z1811457.midterm;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.RadioGroup;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private RadioGroup conversionRadioGroup;

    private FtToMeters conversion;

    private EditText inputET;

    private TextView outputTV;

    private String string;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        conversionRadioGroup = findViewById(R.id.radioGroup);

        conversionRadioGroup.setOnCheckedChangeListener(radioGroup);

        //connecting inputET to inputEditText
        inputET = findViewById(R.id.inputEditText);

    }//end onCreate

    private Intent val;

        private RadioGroup.OnCheckedChangeListener radioGroup = new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                switch (checkedId) {
                    case R.id.ftToMRadioButton:
                        val = new Intent(MainActivity.this, FtToMeters.class);
                        val.putExtra("title", "title changed");
                        //startActivity(intent);
                        break;

                    case R.id.inToCmRadioButton:
                       val = new Intent(MainActivity.this, InToCm.class);
                        //startActivity(intent2);
                        break;

                    case R.id.lbsToGRadioButton:
                        val = new Intent(MainActivity.this, LbsToG.class);

                        //startActivity(intent3)al = intent3;
                        break;
                }//end of switch
            }//end of radioGroup
        }; //end Listener

    public void goConvert(View view) {
        //Intent convert = new Intent(MainActivity.this, FtToMeters.class);
        startActivity(val);


    }
}//end MainActivity