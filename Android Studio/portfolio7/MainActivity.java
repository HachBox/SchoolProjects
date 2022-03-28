package edu.niu.z1811457.portfolio7;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.res.ResourcesCompat;

import android.media.Image;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageButton;
import android.widget.LinearLayout;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private LinearLayout gallery;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //connect the gallery object with layout in the xml file
        gallery = findViewById(R.id.characterLayout);

        //fill the gallery with images
        fillGallery();
    }//end onCreate

    //method to populate the linear layout with images
    private void fillGallery() {
        ImageButton characterIB;

        //add the images to the gallery one at a time
        for(int sub = 0; sub < CharacterInformation.description.length; sub++ ) {
            //generate an ImageButton object
            characterIB = new ImageButton(this);

            //create a Character object with image information
            Character character = new Character(CharacterInformation.description[sub], CharacterInformation.id[sub]);

            //add the description to the imageButton
            characterIB.setContentDescription(character.getCharacterDescription());

            //add the image to the imagebutton
            characterIB.setImageDrawable(ResourcesCompat.getDrawable( getResources(), character.getCharacterID(), null));

            //handle clicking the imageButton
            characterIB.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    //get the content description from the specific image
                    String description = (String) view.getContentDescription();

                    //put the description in a Toast message
                    Toast.makeText(getApplicationContext(), description, Toast.LENGTH_LONG).show();
                }
            });

            //add the image button to the gallery (linear layout)
            gallery.addView(characterIB);
        }
    }
}