package edu.niu.z1811457.portfolio13;

import android.graphics.Canvas;
import android.view.SurfaceHolder;

public class BounceThread extends Thread {
    private SurfaceHolder surfaceHolder;
    private AnimationArena animationArena;
    private boolean isRunning;

    //Constructor
    public BounceThread(SurfaceHolder holder) {
        surfaceHolder = holder;

        animationArena = new AnimationArena();

        isRunning = true;
    }//end BounceThread

    //the run method
    public void run(){
        super.run();
        try {
            while(isRunning) {
                //use the surface holder to create a canvas for drawing
                //by locking the canvas that is on the surface holder
                Canvas canvas = surfaceHolder.lockCanvas();

                //update the location of the ball based on hte size of the canvas
                animationArena.update(canvas.getWidth(), canvas.getHeight());

                //draw the ball at the new location
                animationArena.draw(canvas);

                //unlock the canvas that has been drawn on and display it
                surfaceHolder.unlockCanvasAndPost(canvas);
            }//end while loop
        }
        catch(NullPointerException npe) {
            npe.printStackTrace(); //makes sure the info is generated in the logcat
        }
    }//end run method

    //method that stops the thread
    public void endBounce() {
        isRunning = false;
    }//end endBounce
}//end Bouncethread
