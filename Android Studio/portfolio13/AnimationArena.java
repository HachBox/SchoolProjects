package edu.niu.z1811457.portfolio13;

import android.graphics.Canvas;

public class AnimationArena {
    //The ball that is bouncing on the screen
    private Ball ball;

    //Constructor
    public AnimationArena() {
        //create the ball
        ball = new Ball();
    }//end constructor

    //method to update the movement of the ball within the animation arena
    //arguments - width and height of the canvas the ball will be drawn on
    //width - coordinate of the right side of the screen
    //height - coordinate of the bottom of the screen
    public void  update( int width, int height ){
        //move the ball object
        ball.move(0, 0, width, height);
    }//end update method

    //method to draw the ball on the screen
    //argument - canvas that is being drawn on
    public void draw(Canvas canvas) {
        //set the background color for the canvas - clearing the canvas
        canvas.drawRGB(69,69,69); //156, 174, 216 - light-ish  blue

        //draw the ball on the canvas - position
        ball.draw(canvas);
    }//end draw method

}//end AnimationArena
