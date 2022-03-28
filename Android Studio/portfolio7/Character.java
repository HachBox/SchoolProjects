package edu.niu.z1811457.portfolio7;

public class Character {
    private String characterDescription;
    private int characterID;

    public Character(String description, int id) {
        characterDescription = description;
        characterID = id;
    }//end constructor

    public String getCharacterDescription() {
        return characterDescription;
    }

    public void setCharacterDescription(String description) { //this format works
        characterDescription = description;
    }

    public int getCharacterID() {
        return characterID;
    }

    public void setCharacterID(int characterID) { //or this format works too
        this.characterID = characterID;
    }
}
