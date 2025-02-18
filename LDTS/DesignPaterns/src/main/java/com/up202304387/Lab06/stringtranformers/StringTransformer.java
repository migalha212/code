package com.up202304387.Lab06.stringtranformers;

import com.up202304387.Lab06.StringDrink;

public interface StringTransformer {
    void execute(StringDrink drink);
    void undo(StringDrink drink);
}
