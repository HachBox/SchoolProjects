package edu.niu.z1811457.portfolio10a_sliding;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }//end onCreate

    //the entire code should just be about sliding/transitions

    //method to handle button click
    public void getAnswer(View view) {
        //create the intent to go to the answer activity
        Intent answerIntent = new Intent(MainActivity.this,AnswerActivity.class);

        //start the activity and apply the transition
        startActivity(answerIntent);

        overridePendingTransition(R.anim.answer_on, R.anim.question_off);

    }//end getAnswer

}//end MainActivity