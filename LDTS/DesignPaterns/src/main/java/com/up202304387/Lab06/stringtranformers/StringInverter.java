package com.up202304387.Lab06.stringtranformers;

import com.up202304387.Lab06.StringDrink;

public class StringInverter implements StringTransformer {

    @Override
    public void execute(StringDrink drink){
        String result = new StringBuilder(drink.getText()).reverse().toString();
        drink.setText(result);
    }

    @Override
    public void undo(StringDrink drink) {
        this.execute(drink);
    }
}
