package edu.niu.z1811457.portfolio10a_sliding;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;

public class AnswerActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_answer);
    }//end onCreate

    //method to handle button click
    public void getQuestion(View view) {
        //go back to the main activity and apply the transition
        finish();
        overridePendingTransition(R.anim.question_on, R.anim.answer_off);
    }

}//end AnswerActivity