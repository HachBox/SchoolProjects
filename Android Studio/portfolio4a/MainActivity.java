package edu.niu.z1811457.portfolio4a;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.graphics.Bitmap;
import android.net.Uri;
import android.os.Bundle;
import android.provider.MediaStore;
import android.view.View;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {

    static final int PICTURE_CODE = 7;
    private ImageView pictureIV;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //coonnect the imageview to the screen
        pictureIV = findViewById(R.id.pictureImageView);

    }

    //method to handle clicking the picture button
    public void doPicture(View view) {
        //Create the intent to open the camera
        Intent pictureIntent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);

        //start the activity if possible
        if(pictureIntent.resolveActivity(getPackageManager()) != null) {
            startActivityForResult(pictureIntent, PICTURE_CODE);
        }
    }
    //handle the returned value
    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if(requestCode == PICTURE_CODE && resultCode == RESULT_OK) {
            //get the image from thje intent
            Bundle bundle = data.getExtras();
            Bitmap bitmap = (Bitmap)bundle.get("data");

            //put the image into the imageview
            pictureIV.setImageBitmap(bitmap);
        }
    }//end onActivityResult

    //method to handle clicking the browser button
    public void doBrowser(View view) {
        //Create the intent to open the browser
        Intent browserIntent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://www.niu.edu"));

        //Start the activity - open the browser
        startActivity(browserIntent);
    }//end doBrowser

    //method to handle clicking the phone button
    public void doPhone(View view) {
        //Create the intent to open the dialer
        Intent phoneIntent = new Intent(Intent.ACTION_DIAL, Uri.parse("tel:815675309"));

        //start the activity - open the dialer with the phone number
        startActivity(phoneIntent);
    }//end doPhone

}