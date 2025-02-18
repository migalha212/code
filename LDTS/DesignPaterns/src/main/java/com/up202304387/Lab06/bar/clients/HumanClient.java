package com.up202304387.Lab06.bar.clients;

import com.up202304387.Lab06.bar.Bar;
import com.up202304387.Lab06.bar.StringBar;
import com.up202304387.Lab06.bar.strategies.OrderingStrategy;
import com.up202304387.Lab06.StringDrink;
import com.up202304387.Lab06.stringtranformers.StringRecipe;

public class HumanClient implements Client {
    private OrderingStrategy orderingStrategy;

    public HumanClient(OrderingStrategy orderingStrategy){
        this.orderingStrategy = orderingStrategy;
    }

    @Override
    public void wants(StringDrink drink, StringRecipe recipe, StringBar bar) {
        orderingStrategy.wants(drink,recipe,bar);
    }

    @Override
    public void happyHourStarted(Bar bar) {
        orderingStrategy.happyHourStarted((StringBar) bar);
    }

    @Override
    public void happyHourEnded(Bar bar) {

    }
}
