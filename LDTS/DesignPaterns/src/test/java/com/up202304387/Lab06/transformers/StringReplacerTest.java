package com.up202304387.Lab06.transformers;

import com.up202304387.Lab06.StringDrink;
import com.up202304387.Lab06.stringtranformers.StringReplacer;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class StringReplacerTest {
    @Test
    public void stringReplacer() {
        StringDrink drink = new StringDrink("ABCDABCD");
        StringReplacer sr = new StringReplacer('A', 'X');
        sr.execute(drink);
        assertEquals("XBCDXBCD", drink.getText());
    }
}
