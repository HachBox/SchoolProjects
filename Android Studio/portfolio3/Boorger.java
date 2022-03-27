package edu.niu.z1811457.portfolio3;

public class Boorger
{
    //constants
    static final Integer BEEF = 90, //types of patties
                         TURKEY = 170,
                         VEGGIE = 150,
                         CHEDDAR = 113,
                         MOZZARELLA = 78,
                         BACON = 86;

    //instance variables
    private Integer pattyCalories, cheeseCalories, baconCalories, sauceCalories;

    //Constructor generator
    public Boorger()
    {
        pattyCalories = VEGGIE; //this will be the default when you run the app.
        cheeseCalories = 0;
        baconCalories = 0;
        sauceCalories = 0; //this defaults so that the burger does not have these toppings.
    }//end Boorger constructor

    //Setters
    public void setPattyCalories(Integer newPattyCalories) //this setup works
    {
        pattyCalories = newPattyCalories;
    }

    public void setCheeseCalories(Integer cheeseCalories) //or this
    {
        this.cheeseCalories = cheeseCalories;
    }

    public void setBaconCalories(boolean hasBacon)
    {
        if(hasBacon)
            this.baconCalories = BACON;
        else
            baconCalories = 0;
    }

    public void setSauceCalories(Integer newSauceCalories)
    {
        sauceCalories = newSauceCalories;
    }

    //method to calculate the total number of calories
    public Integer getTotalCalories()
    {
        return pattyCalories + cheeseCalories + baconCalories + sauceCalories;
    }

}//end Boorger class
