package com.up202304387.Lab06.stringtranformers;

import com.up202304387.Lab06.StringDrink;

public class StringReplacer implements StringTransformer {
    private char target;
    private char sub;
    public StringReplacer(char target, char sub){
        this.target = target;
        this.sub = sub;
    }


    @Override
    public void execute(StringDrink drink) {
        drink.setText(drink.getText().replace(target,sub));
    }
    @Override
    public void undo(StringDrink drink){
        drink.setText((drink.getText().replace(sub,target)));
    }
}
