package edu.niu.z1811457.portfolio9;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.graphics.Color;
import android.graphics.Point;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.GridLayout;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;

public class MainActivity extends AppCompatActivity {

    private Button [][] buttons;

    private TicTacToe game;

    private TextView gameStatus;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.activity_main);

        //create the TicTacToe object
        game = new TicTacToe();

        buildGUI();
    }//end onCreate

    //method that generates the gameboard and puts it in the layout
    public void buildGUI() {

        //Determine the width of the screen
        Point size = new Point();
        getWindowManager().getDefaultDisplay().getSize(size);

        //Determine the width of ta single button
        int buttonWidth = size.x / TicTacToe.SIDE;

        //Create the grid layout to hold the buttons
        GridLayout gridLayout = new GridLayout(this);

        //set the number of rows and columns for the grid
        gridLayout.setRowCount(TicTacToe.SIDE + 1);
        gridLayout.setColumnCount(TicTacToe.SIDE);

        //create the array of buttons
        buttons = new Button[TicTacToe.SIDE][TicTacToe.SIDE];

        //create the buttonhandler object to handle button clicks
        ButtonHandler buttonHandler = new ButtonHandler();

        //add the buttons to the grid layout
        for (int row = 0; row < TicTacToe.SIDE; row++) {
            for (int col = 0; col < TicTacToe.SIDE; col++) {
                //generate a single button
                buttons[row][col] = new Button(this);

                //set the text size for the button text
                buttons[row][col].setTextSize((float)(buttonWidth * 0.2));

                //attach the button handler to the button
                buttons[row][col].setOnClickListener(buttonHandler);

                //add the button to the gridLayout
                gridLayout.addView(buttons[row][col], buttonWidth, buttonWidth);
            }//end inner for
        }//end outer for

        //create the textview that holds the status of the game
        gameStatus = new TextView(this);

        //create some parameters to display the textview in the gridlayout
        GridLayout.Spec rowSpec = GridLayout.spec(TicTacToe.SIDE, 1);
        GridLayout.Spec colSpec = GridLayout.spec(0, TicTacToe.SIDE);

        GridLayout.LayoutParams layoutParams = new GridLayout.LayoutParams(rowSpec, colSpec);

        //apply the parameters to the textview
        gameStatus.setLayoutParams(layoutParams);

        //format the textview
        gameStatus.setWidth(TicTacToe.SIDE * buttonWidth);
        gameStatus.setHeight(buttonWidth);

        gameStatus.setGravity(Gravity.CENTER);
        gameStatus.setBackgroundColor(Color.MAGENTA);

        gameStatus.setTextSize((float)(buttonWidth * 0.15));

        //put the status of the game in the textview
        gameStatus.setText(game.result());

        //add the textview to the gridlayout
        gridLayout.addView(gameStatus);

        //make the gridlayout visible
        setContentView(gridLayout);
    }//end buildGUI

    //method to update the display on the buitton
    public void update(int row, int column) {
        //to test, Toast message to check where you are at (column row)
        //Toast.makeText(this, "Update", Toast.LENGTH_SHORT).show(); //comment out if displayed

        //buttons[row][column].setText("A");

        //determine who is playing the game
        int currentPlayer = game.play(row, column);

        //put a character on the button based on who is playing the game
        if(currentPlayer == 1)
            buttons[row][column].setText("X");
        else if (currentPlayer == 2)
            buttons[row][column].setText("O");

        //is the game over? if so, disable all the buttons
        //and update the textview
        //and displaying the dialog box
        if (game.isGameOver()) {
            enableButtons(false);
            gameStatus.setBackgroundColor(Color.CYAN);
            gameStatus.setText(game.result());
            showNewGameDialog();
        }
    }//end update

    //method to disable/enable the buttons
    public void enableButtons( boolean enabled ) {
        for (int row = 0; row < TicTacToe.SIDE; row++)
            for (int col = 0; col < TicTacToe.SIDE; col++)
                buttons[row][col].setEnabled(enabled);
    }//end enableButtons

    public void resetButtons() {
        for (int row = 0; row < TicTacToe.SIDE; row++)
            for (int col = 0; col < TicTacToe.SIDE; col++)
                buttons[row][col].setText("");
    }//end resetButtons

    //method to create the dialouge box to play the game again or quit
    public void showNewGameDialog() {
        AlertDialog.Builder alert = new AlertDialog.Builder(this);

        //add the title to the dialog
        alert.setTitle(R.string.dialog_title);

        //add the message to the dialog
        alert.setMessage(R.string.dialog_message);

        //set up the "Yes" button so the user can play the game again
        alert.setPositiveButton(R.string.dialog_yes, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                //reset the TicTacToe game
                game.resetGame();

                //enable the buttons on the game board
                enableButtons(true );

                //reset the button text
                resetButtons();

                //resetTextview back to tthe inital values (+color)
                gameStatus.setBackgroundColor(Color.MAGENTA);
                gameStatus.setText(game.result());
            }
        }); //end positive button

        //set up the "No" button to close the application
        alert.setNegativeButton(R.string.dialog_no, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                //end/finish the main activity
                MainActivity.this.finish();
            }
        }); //end negative button

        //display the dialog box
        alert.show();

    }//end showNewGameDialog

    //listener to handle button click
    //create a custom class to handle the button clicks
    private class ButtonHandler implements View.OnClickListener {
        @Override
        public void onClick(View view) {
            //find the specific button that was clicked and update its display
            for (int row = 0; row < TicTacToe.SIDE; row++) {
                for (int col = 0;  col < TicTacToe.SIDE; col++) {
                    if (view == buttons[row][col]) {
                        update(row, col);
                    }
                }//end inner for
            }//end outer for
        }//end onClick
    }//end ButtonHandler
}//end MainActivity

