package com.up202304387.Lab06.transformers;

import com.up202304387.Lab06.StringDrink;
import com.up202304387.Lab06.stringtranformers.StringCaseChanger;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class StringCaseChangerTest {
    @Test
    public void stringCaseChanger() {
        StringDrink drink = new StringDrink("aBcD");
        StringCaseChanger cc = new StringCaseChanger();
        cc.execute(drink);
        assertEquals("AbCd", drink.getText());
    }
}
