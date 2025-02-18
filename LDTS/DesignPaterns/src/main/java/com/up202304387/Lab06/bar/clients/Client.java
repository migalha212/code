package com.up202304387.Lab06.bar.clients;

import com.up202304387.Lab06.StringDrink;
import com.up202304387.Lab06.bar.StringBar;
import com.up202304387.Lab06.stringtranformers.StringRecipe;

public interface Client extends BarObserver {
    void wants(StringDrink drink, StringRecipe recipe, StringBar
            bar);
}
