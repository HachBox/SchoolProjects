package edu.niu.z1811457.portfolio12;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private TextView countTV;

    private Integer counter; //using an int because easier to convert to string later on

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //connect the textview to the item on the screen
        countTV = findViewById(R.id.countTextView);

        //initialize the counter to 0
        counter = 0;

        //Create a thread object and associate it with a runnable (countnumber)
        Thread thread = new Thread(countNumber);

        //start execution of the thread
        thread.start();
    }//end onCreate

    @Override
    protected void onStart() {
        super.onStart();

        //reset the counter to 0
        counter = 0;
    }//end onStart

    //create the handler to handle the messages that are passed to the main thread
    private Handler threadHandler = new Handler(new Handler.Callback() {
        @Override
        public boolean handleMessage(@NonNull Message msg) {
            //put the counter value into the textview
            countTV.setText( counter.toString() );

            return true; //can leave as false, because this is a simple app
        }
    }); //end threadHandler

    //Create the Runnable that holds the code being executed in the background thread
    private Runnable countNumber = new Runnable() {

        private static final int DELAY = 1000; //this is in milliseconds

        @Override
        public void run() {
            while(true) {
                //send a message to the thread object
                threadHandler.sendEmptyMessage(0); //can put any int value in there

                //increment the counter by 1
                counter++;

                //pause or delay the thread
                try {
                    Thread.sleep(DELAY);
                }
                catch( InterruptedException exception ) {
                    exception.printStackTrace();
                }
            }//end while loop
        }//end run
    }; //end countNumber

}//end MainActivity