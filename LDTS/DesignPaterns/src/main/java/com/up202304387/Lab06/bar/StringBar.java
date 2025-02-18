package com.up202304387.Lab06.bar;

import com.up202304387.Lab06.StringDrink;
import com.up202304387.Lab06.stringtranformers.StringRecipe;

public class StringBar extends Bar {
    private boolean happyHour;

    public StringBar() {
        super();
    }

    @Override
    public boolean isHappyHour() {
        return happyHour;
    }

    @Override
    public void startHappyHour() {
        this.happyHour = true;
        super.notifyObservers();
    }

    @Override
    public void endHappyHour() {
        this.happyHour = false;
        super.notifyObservers();
    }

    public void order(StringDrink drink, StringRecipe str){
        str.mix(drink);
    }
}
