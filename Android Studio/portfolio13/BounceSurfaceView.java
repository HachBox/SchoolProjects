package edu.niu.z1811457.portfolio13;

import android.content.Context;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import androidx.annotation.NonNull;

public class BounceSurfaceView extends SurfaceView implements SurfaceHolder.Callback {
    private BounceThread bounceThread;

    //constructor
    public BounceSurfaceView(Context context) {
        super(context);

        //GEt the surface hold that is associated with the surface view
        SurfaceHolder holder = getHolder();

        //use the callback methods with the surface holder
        holder.addCallback(this);

        //create the bounce thread and connect it with the surface holder
        bounceThread = new BounceThread(holder);
    }//end constructor

    @Override
    public void surfaceCreated(@NonNull SurfaceHolder holder) {
        //start the tread
        bounceThread.start();
    }//end surfaceCreated method

    @Override
    public void surfaceDestroyed(@NonNull SurfaceHolder holder) {
        //stop the thread
        bounceThread.endBounce();

        //nullify the thread
        Thread dummyThread = bounceThread;
        bounceThread = null;
        dummyThread.interrupt();
    }//end surfaceDestroyed

    //surfaceHolder - surface holder whose surface changed
    //i = format - pixel format - type of pixel on device
    //i2 = width - new width of the surface
    //i3 = height - new height of the surface

    @Override
    public void surfaceChanged(@NonNull SurfaceHolder holder, int format, int width, int height) {

    }//end surfaceChanged method
}//end BounceSurfaceView
