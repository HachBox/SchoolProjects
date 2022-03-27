package edu.niu.z1811457.assignment4;

import androidx.appcompat.app.AppCompatActivity;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;

public class MainActivity extends AppCompatActivity {

    private ImageButton gtrBtn, hellkittyBtn, lfaBtn, supraBtn, termiBtn, gt500Btn;
    private MediaPlayer gtrMP, hellkittyMP, lfaMP, supraMP, termiMP, gt500MP;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //connect the buttons
        gtrBtn = findViewById(R.id.gtrImageButton);
        hellkittyBtn = findViewById(R.id.hellkittyImageButton);
        lfaBtn = findViewById(R.id.lfaImageButton);
        supraBtn = findViewById(R.id.supraImageButton);
        termiBtn = findViewById(R.id.terminatorImageButton);
        gt500Btn = findViewById(R.id.gt500ImageButton);


        //set ip the gtr media player with the gtr.mp3
        gtrMP = new MediaPlayer();
        gtrMP = MediaPlayer.create(this, R.raw.gtr);

        //set ip the hellkitty media player with the hellkitty.mp3
        hellkittyMP = new MediaPlayer();
        hellkittyMP = MediaPlayer.create(this, R.raw.hellkitty);

        //set ip the lfa media player with the lfa.mp3
        lfaMP = new MediaPlayer();
        lfaMP = MediaPlayer.create(this, R.raw.lfa);

        //set ip the supra media player with the supra.mp3
        supraMP = new MediaPlayer();
        supraMP = MediaPlayer.create(this, R.raw.supra);

        //set ip the temrmi media player with the termi.mp3
        termiMP = new MediaPlayer();
        termiMP = MediaPlayer.create(this, R.raw.terminator);

        //set ip the gt500 media player with the gt500.mp3
        gt500MP = new MediaPlayer();
        gt500MP = MediaPlayer.create(this, R.raw.gt500);
    }

    //method to handle clicking the gtr button
    public void playGtr(View view) {
        //pause the media player
        if (gtrMP.isPlaying()) {
            //pause the media player
            gtrMP.pause();
        }

        else { //not playing
            //start the drums media player
            gtrMP.start();
        }
    }//end playGtr

    //method to handle clicking the Hellkitty button
    public void playHellkitty(View view) {
        //pause the media player
        if (hellkittyMP.isPlaying()) {
            //pause the media player
            hellkittyMP.pause();
        }

        else { //not playing
            //start the drums media player
            hellkittyMP.start();
        }
    }//end playHellkitty

    //method to handle clicking the Lfa button
    public void playLfa(View view) {
        //pause the media player
        if (lfaMP.isPlaying()) {
            //pause the media player
            lfaMP.pause();
        }

        else { //not playing
            //start the drums media player
            lfaMP.start();
        }
    }//end playLfa

    //method to handle clicking the Supra button
    public void playSupra(View view) {
        //pause the media player
        if (supraMP.isPlaying()) {
            //pause the media player
            supraMP.pause();
        }

        else { //not playing
            //start the drums media player
            supraMP.start();
        }
    }//end playSupra

    //method to handle clicking the Terminator button
    public void playTerminator(View view) {
        //pause the media player
        if (termiMP.isPlaying()) {
            //pause the media player
            termiMP.pause();
        }

        else { //not playing
            //start the drums media player
            termiMP.start();
        }
    }//end playTerminator

    //method to handle clicking the Gt500 button
    public void playGt500(View view) {
        //pause the media player
        if (gt500MP.isPlaying()) {
            //pause the media player
            gt500MP.pause();
        }

        else { //not playing
            //start the drums media player
            gt500MP.start();
        }
    }//end playGt500
}
