package edu.niu.z1811457.portfolio15;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

import java.lang.annotation.Target;
import java.util.ArrayList;
import java.util.Arrays;

public class DataBaseManager extends SQLiteOpenHelper {
    //constantss
    private static final String DATABASE_NAME = "candyDB",
                                TABLE_NAME = "candyTab",
                                ITEM_ID = "id",
                                ITEM_NAME = "name",
                                ITEM_PRICE = "price";

    private static final int DATABASE_VERSION = 1;

    //constructor
    public DataBaseManager(@Nullable Context context) { //@Nullable String name, @Nullable SQLiteDatabase.CursorFactory factory, int version) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }//end constructor

    //onCreate method


    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        //sql statement to create the table in the database
        String sqlCreate = "create table " + TABLE_NAME + "( " + //spacing is very important here
                           ITEM_ID + " integer primary key autoincrement, " +
                           ITEM_NAME + " text, " +
                           ITEM_PRICE + " real )";

        //create the table in the database
        sqLiteDatabase.execSQL(sqlCreate);
    }//end onCreate

    //onUpgrade Method
    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
        //string that drops the table if it exists
        String sqlDrop = "drop table if exists " + TABLE_NAME;

        //drop the table
        sqLiteDatabase.execSQL(sqlDrop);

        //re-create the table in the database
        onCreate(sqLiteDatabase);
    }//end onUpgrade

    //Method to insert a Candy object into the database
    public void insertCandy(Candy candy) {
        //String with insert command
        String sqlInsert = "insert into " + TABLE_NAME +
                           " values( null, '" + candy.getName() + "', '" + candy.getPrice() + "' )";

        //get the database
        SQLiteDatabase database = getWritableDatabase();

        //insert the candy into the database
        database.execSQL(sqlInsert);

        //close the database
        database.close();
    }//end insertCandy method

    //method to retrieve all the information from the database
    public ArrayList<Candy> selectAll() {
        //String with select command
        String sqlSelect = "select * from " + TABLE_NAME;

        //get the database
        SQLiteDatabase database = getWritableDatabase();

        //get the information from the database
        Cursor cursor = database.rawQuery(sqlSelect, null);

        //create the arraylist to hold the info
        ArrayList<Candy> candies = new ArrayList<>();

        //Divide the cursor object into the individual candy objects
        while (cursor.moveToNext()) {
            //Divide the current database item into its 3 parts
            Integer currentID = cursor.getInt(0);
            String currentName = cursor.getString(1);
            Double currentPrice = cursor.getDouble(2);

            //Create a candy object
            Candy candy = new Candy(currentID, currentName, currentPrice);

            //add the candy object to the arraylist
            candies.add(candy);
        }//end while

        //close the database
        database.close();

        return candies;
    }//end selectAll

    //method to delete an item from the database (by id number)
    public void deleteByID(int id) {
        //sql delete command
        String sqlDelete = "delete from " + TABLE_NAME + " where " + ITEM_ID + " = " + id;

        SQLiteDatabase database = getWritableDatabase();

        //apply the sql command to the database
        database.execSQL(sqlDelete);

        //close the database
        database.close();
    }//end deletebyID

    //method to update an item in the database (by id number)
    public void updateByID(int id, String updatedName, Double updatedPrice) {
        String sqlUpdate = "update " + TABLE_NAME + " set " +
                           ITEM_NAME + " = '" + updatedName + "', " +
                           ITEM_PRICE + " ='" + updatedPrice + "'" +
                           " where " + ITEM_ID + " = " + id;

        SQLiteDatabase database = getWritableDatabase();
        database.execSQL(sqlUpdate);
        database.close();
    }//end updateByID method
}//end DataBaseManager
