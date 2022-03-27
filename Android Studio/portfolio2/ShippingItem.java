package edu.niu.z1811457.portfolio2;

public class ShippingItem
{
    //Constants
    static final Double BASE_AMOUNT = 3.00;
    static final Double ADDED_AMOUNT = 0.50;
    static final int BASE_WEIGHT = 16;
    static final double EXTRA_OUNCES = 4.0;

    //Instance Variables
    private Integer weight;
    private Double baseCost, addedCost, totalCost;

    public ShippingItem()
    {
        weight = 0;
        baseCost = BASE_AMOUNT;
        addedCost = 0.0;
        totalCost = 0.0;
    }//end Constructor

    public void computeCost()
    {
        addedCost = 0.0;
        baseCost = BASE_AMOUNT;

        if ( weight <= 0 )
            baseCost = 0.00;
        else if ( weight > BASE_WEIGHT )
            addedCost = Math.ceil( (double)(weight - BASE_WEIGHT) / (EXTRA_OUNCES) ) * ADDED_AMOUNT;

        totalCost = baseCost + addedCost;
    }//end ComputeCost

    public void setWeight(Integer newWeight)
    {
        weight = newWeight;
        computeCost();
    }

    public Double getBaseCost() {
        return baseCost;
    }

    public Double getAddedCost() {
        return addedCost;
    }

    public Double getTotalCost() {
        return totalCost;
    }
}//end ShippingItem
