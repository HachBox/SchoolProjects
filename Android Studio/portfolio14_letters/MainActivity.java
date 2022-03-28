package edu.niu.z1811457.portfolio14_letters;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.widget.FrameLayout;

public class MainActivity extends AppCompatActivity {

    //constants
    private static final int NUM_OBJECTS = 19;
    private static final int X_SUB = 0, Y_SUB = 1;

    //thread
    // - one is used to calculate the movement
    // - one is used to draw the movement of the circles
    private Thread calcMoveThread;
    private Thread drawMoveThread;

    //custom view object
    private LetterView letterView;

    //layout where the circles will be drawn
    private FrameLayout letterLayOut;

    //two two-dimentional arrays of integers (current position, final destination)
    private int[][] currentPostion;
    private int[][] finalDestination;

    private void initialize() {
        //create the 2-dimentional arrays
        currentPostion = new int[NUM_OBJECTS][2];
        finalDestination = new int[NUM_OBJECTS][2];

        //initialie the arrays
        for (int sub = 0; sub < NUM_OBJECTS; sub++) {
            //current position will be starting position for all circles
            currentPostion[sub][X_SUB] = 20;
            currentPostion[sub][Y_SUB] = 20;

            //initialize the final destination array
            finalDestination[sub][X_SUB] = 200;
            finalDestination[sub][Y_SUB] = 200;
        }
    }//end initialize method

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //initializing the starting and ending points for the circles
        initialize();

        //connect the layouts
        letterLayOut = findViewById(R.id.letterLayout);

        //create the custom view
        letterView = new LetterView(this);

        //add the custom view to the layout
        letterLayOut.addView(letterView);

        //create the threads
        calcMoveThread = new Thread(calcMove);
        drawMoveThread = new Thread(drawMove);

        //start the threads
        calcMoveThread.start();
        drawMoveThread.start();
    }//end onCreate

    //Handle the messages by updating the letter drawing
    public Handler threadHandler = new Handler(new Handler.Callback() {
        @Override
        public boolean handleMessage(@NonNull Message msg) {
            letterView.update(currentPostion);
            return false;
        }
    });//end threadHandler

    // Runnables
    // calcMove compuiute the positions of the circles on the canvas
    // - positions will be calculated every 200 milliseconds
    // - current positions are based on the distance to the final destination divided by 5
    // 5 is so that it travels 1/5th of the distance to the final destination every 200milliseconds (faster)

    private Runnable calcMove = new Runnable() {

        private static final int DELAY = 200;

        @Override
        public void run() {
            try {
                //infinite loop to re-draw/position the circles every 200 milliseconds
                while(true) {
                    for (int sub = 0; sub < NUM_OBJECTS; sub++) {
                        currentPostion[sub][X_SUB] += (finalDestination[sub][X_SUB] - currentPostion[sub][X_SUB])/5; //calculate the distance between the two
                        currentPostion[sub][Y_SUB] += (finalDestination[sub][Y_SUB] - currentPostion[sub][Y_SUB])/5;
                    }//end for loop

                    Thread.sleep(DELAY);
                }//end while
            }
            catch (InterruptedException ie) {
                ie.printStackTrace(); //can be blank, just make sure curly braces are there
            }
        }//end run
    };//end calcMove runnable

    //runnable - sends a message every 200 milliseconds that will cause the circles to be re-drawn
    private Runnable drawMove = new Runnable() {
        private static final int DELAY = 200;

        @Override
        public void run() {
            try {
                while (true) {
                    //make the thread sleep for 200 milliseconds
                    Thread.sleep(DELAY);

                    //send a message to re-draw the circles
                    threadHandler.sendEmptyMessage(69);

                }//end while
            }
            catch (InterruptedException ie) {
                ie.printStackTrace();
            }
        }//end run
    };//end drawMove

    //Methods to handle button clicks
    public void createA(View view) {
        //set up the final destination array with the final coordinates for the 19 circles
        for(int sub = 0; sub < NUM_OBJECTS; sub++) {
            finalDestination[sub][X_SUB] = LetterDesign.artA[sub][X_SUB];
            finalDestination[sub][Y_SUB] = LetterDesign.artA[sub][Y_SUB];
        }
    }//end createA

    public void createB(View view) {
        //set up the final destination array with the final coordinates for the 19 circles
        for(int sub = 0; sub < NUM_OBJECTS; sub++) {
            finalDestination[sub][X_SUB] = LetterDesign.artB[sub][X_SUB];
            finalDestination[sub][Y_SUB] = LetterDesign.artB[sub][Y_SUB];
        }
    }//end createB

    public void createC(View view) {
        //set up the final destination array with the final coordinates for the 19 circles
        for(int sub = 0; sub < NUM_OBJECTS; sub++) {
            finalDestination[sub][X_SUB] = LetterDesign.artC[sub][X_SUB];
            finalDestination[sub][Y_SUB] = LetterDesign.artC[sub][Y_SUB];
        }
    }//end createC
}