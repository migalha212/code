package com.up202304387.Lab06.stringtranformers;

import com.up202304387.Lab06.StringDrink;

import java.util.List;

public class StringRecipe {
    private List<StringTransformer> recipe;

    public StringRecipe(List<StringTransformer> recipe){
        this.recipe = recipe;
    }

    public void mix(StringDrink drink){
        for(StringTransformer stringTransformer : recipe){
            stringTransformer.execute(drink);
        }
    }
}
