package edu.niu.z1811457.portfolio10b_scenes;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Build;
import android.os.Bundle;
import android.transition.Scene;
import android.transition.Transition;
import android.transition.TransitionInflater;
import android.transition.TransitionManager;
import android.view.View;
import android.view.ViewGroup;

public class MainActivity extends AppCompatActivity {

    private ViewGroup paintingCountainer;
    private Transition transition;

    private Scene activeScene, passiveScene1, passiveScene2, passiveScene3;

    @RequiresApi(api = Build.VERSION_CODES.KITKAT)
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //connect the Layout to the viewgroup
        paintingCountainer = findViewById(R.id.paintingLayout);

        //Create the transition
        transition = TransitionInflater.from(this).inflateTransition(R.transition.transition);

        //Create the 4 scene object and associate an XML file with each one
        activeScene = Scene.getSceneForLayout(paintingCountainer,R.layout.scene1, this);
        passiveScene1 = Scene.getSceneForLayout(paintingCountainer,R.layout.scene2, this);
        passiveScene2 = Scene.getSceneForLayout(paintingCountainer,R.layout.scene3, this);
        passiveScene3 = Scene.getSceneForLayout(paintingCountainer,R.layout.scene4, this);

        //make the active scene visible
        activeScene.enter();
    }//end onCreate

    //method that handles the button clicks
    public void changeScene(View view) {
        //swap the scenes to make the 1st passive scene the active scene
        Scene temp;
        temp = activeScene;
        activeScene = passiveScene1;
        passiveScene1 = passiveScene2;
        passiveScene2 = passiveScene3;
        passiveScene3 = temp;

        //make the updated active scene visible
        TransitionManager.go(activeScene, transition);
    }//end changeScene
}//end MainActivity