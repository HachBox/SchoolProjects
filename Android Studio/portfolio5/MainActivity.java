package edu.niu.z1811457.portfolio5;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private Spinner xmlSpin, arraySpin, listSpin;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //connect the xmlSpin to the screen
        xmlSpin = findViewById(R.id.xmlSpinner);

        //create the array adapter with the data from strings.xml
        ArrayAdapter<CharSequence> adapter1 = ArrayAdapter.createFromResource(this, R.array.spinner_array, R.layout.spinner_view);

        //connect the spinner and the array adapter
        xmlSpin.setAdapter(adapter1);

        //handle making a selection form the spinner
        xmlSpin.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                String selection1;
                //get the selection from the spinner
                selection1 = parent.getItemAtPosition(position).toString();

                //put the string into a toast message
                Toast toast = Toast.makeText(getApplicationContext(), "The xml selection is " + selection1, Toast.LENGTH_LONG);

                //set up the placement of where the toast message should display
                toast.setGravity(Gravity.BOTTOM | Gravity.LEFT, 50, 500);

                //display the toast message
                toast.show();
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });

        //spinner with info from array of Strings
        arraySpin = findViewById(R.id.arraySpinner);

        ArrayAdapter<String> adapter2 = new ArrayAdapter<>(this, R.layout.spinner_view, SpinnerData.values);

        arraySpin.setAdapter(adapter2);

        arraySpin.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                String selection2;
                selection2 = parent.getItemAtPosition(position).toString();
                Toast.makeText(getApplicationContext(),"The array selection " + selection2, Toast.LENGTH_LONG).show();
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });

        //List of Spinner information
        List<String> listInfo = new ArrayList<>();

        //add information to the List object
        listInfo.add("Cobra");
        listInfo.add("Aventador");
        listInfo.add("Aperta");

        listSpin = findViewById(R.id.listSpinner);

        ArrayAdapter<String> adapter3 = new ArrayAdapter<>(this, R.layout.spinner_view,listInfo);

        listSpin.setAdapter(adapter3);

        listSpin.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                String selection3;
                selection3 = parent.getItemAtPosition(position).toString();

                Toast toast = Toast.makeText(getApplicationContext(), "This list selection " + selection3, Toast.LENGTH_LONG);
                toast.setGravity(Gravity.BOTTOM | Gravity.CENTER_HORIZONTAL, 0, 400);
                toast.show();
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });
    }
}