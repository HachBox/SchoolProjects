package edu.niu.z1811457.portfolio11;

import android.content.Context;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link ButtonFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class ButtonFragment extends Fragment {

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String information;
    private OnItemSelectedListener listener;
    //private String mParam2; needs only one string

    public ButtonFragment() {
        // Required empty public constructor
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

    }//end onCreate

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_button, container, false);
    }//end onCreateView

    //this method is called after onCreateView
    //It's where the view set-up should be handled - could've been done in onCreate
    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        Button plumBtn = view.findViewById(R.id.plumButton),
               blueBtn = view.findViewById(R.id.blueButton),
               goldBtn = view.findViewById(R.id.goldButton);

        //attach a named listener to all the buttons
        plumBtn.setOnClickListener( colorSelect );
        blueBtn.setOnClickListener( colorSelect );
        goldBtn.setOnClickListener( colorSelect );
    }//end onViewCreated

    //The listener to handle button clicks
    private View.OnClickListener colorSelect = new View.OnClickListener() {
        @Override
        public void onClick(View view) {
            //get the color information from the button that was clicked
            information = (String)view.getContentDescription();

            //pass the color information to the activity so it can be displayed
            listener.onShadeItemSelected(information);
        }
    }; //end colorSelect listener

    //This interface is needed so the fragment can communicate with the activity.
    //The method between the curly braces has to be implemented by the activity
    public interface OnItemSelectedListener {
        public void onShadeItemSelected( String colorInfo ); //semicolon because prototype
    }//end OnItemSelectedListener

    //this method that is called when the fragment is associated with an activity
    @Override
    public void onAttach(@NonNull Context context) {
        super.onAttach(context);
        //put a decision statement - make sure the activity attached to the fragment has implemented the OnItemSelectedListener interface
        if (context instanceof OnItemSelectedListener) {
            listener = (OnItemSelectedListener)context;
        }
        else {
            throw new ClassCastException(context.toString() + " must implement the ButtonFragment.OnItemSelectedListener");
        }
    }//end onAttach
}//end ButtonFragment