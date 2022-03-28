package edu.niu.z1811457.portfolio14_letters;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.View;

import java.util.Arrays;

public class LetterView extends View {
    //after extends View, it will be red because we need onDraw method
    //constants
    private static final int NUM_CIRCLES = 19;
    private static final int NUM_COORDS = 2;

    private Paint paint;
    private int [][] letterPosition;

    public LetterView(Context context) {
        super(context);

        //allocate the array of integers
        letterPosition = new int[NUM_CIRCLES][NUM_COORDS];

        //set the paint color for drawing the circles (optional)
        int circleColor = Color.argb(255, 148, 205, 204);

        //create the paint object for drawing the circles
        paint = new Paint();

        //apply the color
        paint.setColor(circleColor); //circleColor is optional, can just put a default color in there.

        //set the type of line style for drawing the circles
        paint.setStyle(Paint.Style.STROKE);

        //set the width of the line that draws the circle (smaller == thinner)
        paint.setStrokeWidth(10.0f);
    }//end constructor

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);

        //draw all the circles on the canvas
        for(int sub = 0; sub < NUM_CIRCLES; sub++) {
            canvas.drawCircle(letterPosition[sub][0] + 300,letterPosition[sub][1] + 400, 80, paint);
        }// end for loop
    }//end onDraw

    public void update( int [][] values ) {
        //copy all the values into letterPosition
        letterPosition = Arrays.copyOf(values, values.length);

        //re-draw the canvas
        //the canvas must be invalidated before it can be re-drawn
        //this automatically calls the onDraw method (needed since the method will be called from the UI thread)
        invalidate();
    }//end update

}//end LetterView
