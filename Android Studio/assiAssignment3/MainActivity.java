package edu.niu.z1811457.assignment3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.provider.MediaStore;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private Spinner arraySpin;

    private Button spinnerBtn;

    private ImageView carIV;

    static final int PICTURE_CODE = 7;

    private String x;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //spinner with info from array of Strings
        arraySpin = findViewById(R.id.arraySpinner);

        ArrayAdapter<String> spinnerArrayAdapter = new ArrayAdapter<String>
                (this, android.R.layout.simple_spinner_item, SpinnerData.cars); //selected item will look like a spinner set from XML

        arraySpin.setAdapter(spinnerArrayAdapter);

        //spinnerArrayAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);

        carIV = findViewById(R.id.carImageView);

        /*Showing the array spinner selections and the actions the it does on the same page
        when the action is picked.
         */
        arraySpin.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                String selection;
                selection = parent.getItemAtPosition(position).toString();
                if( selection == "Civic Hatchback")
                    carIV.setImageResource(R.drawable.civic_hatch);
                else if ( selection == "Nissan 400Z" )
                    carIV.setImageResource(R.drawable.nissan400z);
                else if ( selection == "Ford focus RS" )
                    carIV.setImageResource(R.drawable.focus_rs);
                else if ( selection == "Nissan GT-R" )
                    carIV.setImageResource(R.drawable.gtr);
                else if ( selection == "Mazda Miata" )
                    carIV.setImageResource(R.drawable.mx5);
                else if ( selection == "Jaguar XF-S" )
                    carIV.setImageResource(R.drawable.xfs);
                x = selection;
                Intent photoPickerIntent = new Intent(Intent.ACTION_PICK);
                Toast.makeText(getApplicationContext(),"You picked the " + selection, Toast.LENGTH_LONG).show();
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });
    }

    //What happens when you press "Look under the hood"
    public void doPicture(View view) {
        Intent intent = new Intent(MainActivity.this, SpinnerView.class);
        if( x == "Civic Hatchback") {
            intent.putExtra("stats", "        Honda Civic Hatchback\n" +
                    "        180hp @ 5,500 rpm\n" +
                    "        177 lb-ft @ 1900-5000 rpm\n" +
                    "\n" +
                    "        Drivetrain -\n" +
                    "        In-Line 4-Cylinder with Turbocharger\n" +
                    "        6-Speed Manual Transmission (6MT)\n" +
                    "        Front-wheel drive\n" +
                    "\n" +
                    "        Tires -\n" +
                    "        18\" Allow wheels\n" +
                    "        Bridgestone all season tires\n" +
                    "\n" +
                    "        Weight - 2945 lbs\n" +
                    "        Distribution - 60/40");
        }
        else if ( x == "Nissan 400Z" )
            intent.putExtra("stats", "        Nissan 400Z\n" +
                    "        400hp @ ???\n" +
                    "        ??? lb-ft @ ???\n" +
                    "\n" +
                    "        Drivetrain -\n" +
                    "        twin-turbo V6 from an Infiniti Q50/Q60\n" +
                    "        Manual (6MT)\n" +
                    "        Rear-wheel drive\n" +
                    "\n" +
                    "        Tires -\n" +
                    "        ???\n" +
                    "        ???\n" +
                    "        ???\n" +
                    "\n" +
                    "        Weight ~ 3968 lbs\n" +
                    "        Distribution ~ 55/45");
        else if ( x == "Ford focus RS" )
            intent.putExtra("stats", "        Ford Focus RS\n" +
                    "        350hp @ 6000 rpm\n" +
                    "        350 lb-ft @ 3200 rpm\n" +
                    "\n" +
                    "        Drivetrain -\n" +
                    "        Intercooled Turbo Premium Unleaded I-4\n" +
                    "        Manual w/OD (6MT)\n" +
                    "        All-wheel drive\n" +
                    "\n" +
                    "        Tires -\n" +
                    "        4 wheel disk brakes\n" +
                    "        Forged Aluminum 19x8in P235/35YR19\n" +
                    "\n" +
                    "        Weight - 3434 lbs\n" +
                    "        Distribution - 55/45");
        else if ( x == "Nissan GT-R" )
            intent.putExtra("stats", "        Nissan GT-R\n" +
                    "        565 hp @ 6,800 rpm\n" +
                    "        467 lb-ft of torque @ 3,300 – 5,800 rpm\n" +
                    "\n" +
                    "        Drivetrain -\n" +
                    "        3.8-liter DOHC 24-valve twin-turbocharged V6\n" +
                    "        Dual-clutch 6-speed transmission with three driver-selectable modes\n" +
                    "        ATTESA E-TS® All-Wheel Drive (AWD) with patented independent rear-mounted transaxle\n" +
                    "\n" +
                    "        Tires -\n" +
                    "        255/40ZRF20 front and 285/35ZRF20 rear Dunlop® SP Sport Maxx® GT 600 DSST CTT high-performance run-flat tires\n" +
                    "        20\" RAYS® forged-alloy wheels\n" +
                    "        Nissan/Brembo® braking system\n" +
                    "\n" +
                    "        Weight - 3,935 lbs\n" +
                    "        Distribution - 55/45");
        else if ( x == "Mazda Miata" )
            intent.putExtra("stats", "        Mazada Miata\n" +
                    "        155 hp @ 6000 rpm\n" +
                    "        148 lb-ft @ 4600 rpm\n" +
                    "\n" +
                    "        Drivetrain -\n" +
                    "        SKYACTIV®-G1 2.0L DOHC 16-valve 4-cylinder with VVT\n" +
                    "        SKYACTIV®-MT1 6-speed manual transmission with short-throw shifter\n" +
                    "        Front-midship engine, rear-wheel drive\n" +
                    "\n" +
                    "        Tires -\n" +
                    "        4-wheel disc\n" +
                    "        11-inch vented disc with single piston calipers - front\n" +
                    "        11-inch solid disc with single piston calipers - rear\n" +
                    "        17 x 7 aluminum-alloy with Dark Gunmetal finish\n" +
                    "        P205/45 R17 high-performance tires\n" +
                    "\n" +
                    "        Weight - 2,445 lbs\n" +
                    "        Distribution 50/50\n");
        else if ( x == "Jaguar XF-S" )
            intent.putExtra("stats", "        Jaguar XF-S\n" +
                    "        250hp @ 5,500 rpm\n" +
                    "        269 lb-ft @ 1,300 - 4,500 rpm\n" +
                    "\n" +
                    "        Drivetrain -\n" +
                    "        2L inline four\n" +
                    "        8-speed automatic with paddle shifters\n" +
                    "        All-wheel drive\n" +
                    "\n" +
                    "        Tires -\n" +
                    "        Nothing special\n" +
                    "\n" +
                    "        Weight - 3,655 lbs\n" +
                    "        Distribution - 60/40");

        startActivity(intent);
        }
    }

    /*
    private View.OnClickListener carListener = new View.OnClickListener() {
        @Override
        public void onClick(View view) {
            startActivity(val);
        }
    };
     */
