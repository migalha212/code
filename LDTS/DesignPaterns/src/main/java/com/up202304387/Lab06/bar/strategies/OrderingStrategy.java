package com.up202304387.Lab06.bar.strategies;

import com.up202304387.Lab06.bar.StringBar;
import com.up202304387.Lab06.StringDrink;
import com.up202304387.Lab06.stringtranformers.StringRecipe;

public interface OrderingStrategy {
    void wants(StringDrink drink, StringRecipe recipe, StringBar
            bar);
    void happyHourStarted(StringBar bar);
    void happyHourEnded(StringBar bar);

}
