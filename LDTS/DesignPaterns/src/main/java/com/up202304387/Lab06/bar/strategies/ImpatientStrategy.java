package com.up202304387.Lab06.bar.strategies;

import com.up202304387.Lab06.bar.StringBar;
import com.up202304387.Lab06.StringDrink;
import com.up202304387.Lab06.stringtranformers.StringRecipe;

public class ImpatientStrategy implements OrderingStrategy{
    @Override
    public void wants(StringDrink drink, StringRecipe recipe, StringBar bar) {
        bar.order(drink, recipe);
    }

    @Override
    public void happyHourStarted(StringBar bar) {

    }

    @Override
    public void happyHourEnded(StringBar bar) {

    }
}
