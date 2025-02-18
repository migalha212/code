package com.up202304387.Lab06.transformers;

import com.up202304387.Lab06.StringDrink;
import com.up202304387.Lab06.stringtranformers.StringInverter;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class StringInverterTest {
    @Test
    public void stringInverter() {
        StringDrink drink = new StringDrink("ABCD");
        StringInverter si = new StringInverter();
        si.execute(drink);
        assertEquals("DCBA", drink.getText());
    }
}
