package com.up202304387.Lab06.stringtranformers;

import com.up202304387.Lab06.StringDrink;

public class StringCaseChanger implements StringTransformer {

    @Override
    public void execute(StringDrink drink) {
        StringBuilder res = new StringBuilder();
        for(char c : drink.getText().toCharArray()){
            if(Character.isLowerCase(c)) res.append(Character.toUpperCase(c));
            else res.append(Character.toLowerCase(c));
        }
        drink.setText(res.toString());
    }

    @Override
    public void undo(StringDrink drink) {
        this.execute(drink);
    }
}
