package edu.niu.z1811457.portfolio8;

import androidx.appcompat.app.AppCompatActivity;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    private Button drumsBtn, ukuleleBtn;
    private MediaPlayer drumsMP, ukuleleMP;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //connect the buttons
        drumsBtn = findViewById(R.id.drumsButton);
        ukuleleBtn = findViewById(R.id.ukuleleButton);

        //set ip the drums media player with the drums.mp3
        drumsMP = new MediaPlayer();
        drumsMP = MediaPlayer.create(this, R.raw.drums);

        //set up the ukelele media player with the ukelele.mp3
        ukuleleMP = new MediaPlayer();
        ukuleleMP = MediaPlayer.create(this, R.raw.ukulele);
    }//end onCreate

    //method to handle clicking the drums button
    public void playDrums(View view) {
        //pause the media player
        if (drumsMP.isPlaying()) {
            //pause the media player
            drumsMP.pause();

            //update the text button on the button
            drumsBtn.setText(R.string.drums_play_string);
        }

        else { //not playing
            //chcek if ukulele media is playing
            if (ukuleleMP.isPlaying()) {
                //pause the ukulele
                ukuleleMP.pause();
                //update the text on the ukulele button
                ukuleleBtn.setText(R.string.ukulele_play_string);
            }

            //start the drums media player
            drumsMP.start();

            //update the drums button
            drumsBtn.setText(R.string.drums_pause_string);
        }
    }//end playDrums

    //method to handle clicking the ukulele button
    public void playUkulele(View view) {
        //pause the media player
        if (ukuleleMP.isPlaying()) {
            //pause the media player
            ukuleleMP.pause();

            //update the text button on the button
            ukuleleBtn.setText(R.string.ukulele_play_string);
        }

        else { //not playing
            //chcek if drums media is playing
            if (drumsMP.isPlaying()) {
                //pause the ukulele
                drumsMP.pause();
                //update the text on the ukulele button
                drumsBtn.setText(R.string.drums_play_string);
            }

            //start the drums media player
            ukuleleMP.start();

            //update the drums button
            ukuleleBtn.setText(R.string.ukulele_pause_string);
        }
    }//end playUkulele

}//end MainActivity