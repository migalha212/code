package com.up202304387.Lab06.bar.clients;

import com.up202304387.Lab06.StringDrink;
import com.up202304387.Lab06.bar.Bar;
import com.up202304387.Lab06.bar.StringBar;
import com.up202304387.Lab06.stringtranformers.StringRecipe;
import com.up202304387.Lab06.bar.strategies.*;
public abstract class AlienClient implements Client{

    private OrderingStrategy strategy;
    public AlienClient() {
        this.strategy = createOrderingStrategy();
    }

    @Override
    public void wants(StringDrink drink, StringRecipe recipe, StringBar bar) {
        strategy.wants(drink,recipe,bar);
    }

    @Override
    public void happyHourStarted(Bar bar) {
        strategy.happyHourStarted((StringBar) bar);
    }

    @Override
    public void happyHourEnded(Bar bar) {
        strategy.happyHourEnded((StringBar) bar);
    }

    protected abstract OrderingStrategy createOrderingStrategy();
}
