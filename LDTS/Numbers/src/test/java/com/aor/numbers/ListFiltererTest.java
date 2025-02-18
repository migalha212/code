package com.aor.numbers;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.Console;
import java.util.Arrays;
import java.util.List;

public class ListFiltererTest {
    private List<Integer> list;

    @BeforeEach
    public void helper(){
        list = Arrays.asList(1,6,3,4,2,0,-2,-3);
    }

    @Test
    public void positiveFilter(){
        GenericListFilter filter = new PositiveFilter();

        int i = -10;
        Assertions.assertFalse(filter.accept(i));

        int j = 0;
        Assertions.assertFalse(filter.accept(j));

        int k = 10;
        Assertions.assertTrue(filter.accept(k));
    }

    @Test
    public void divisibleByFilter(){
        GenericListFilter filter = new DivisibleByFilter(2);

        int i = 0;
        Assertions.assertTrue(filter.accept(i));

        int j = 10;
        Assertions.assertTrue(filter.accept(j));

        int k = -10;
        Assertions.assertTrue(filter.accept(k));

        Assertions.assertFalse(filter.accept(5));
    }

    @Test
    public void divisibleByFilter2(){
        GenericListFilter filter = new DivisibleByFilter(0);

        Assertions.assertFalse(filter.accept(10));
        Assertions.assertFalse(filter.accept(0));
        Assertions.assertFalse(filter.accept(-10));
    }

    @Test
    public void listFilterer(){
        ListFilterer listFilterer = new ListFilterer(new DivisibleByFilter(2));
        List<Integer> expected = Arrays.asList(6,4,2,0,-2);
        Assertions.assertEquals(expected,listFilterer.filter(list));

    }

    @Test
    public void listFilterer1(){
        ListFilterer listFilterer = new ListFilterer(new PositiveFilter());
        List<Integer> expected = Arrays.asList(1,6,3,4,2);
        Assertions.assertEquals(expected,listFilterer.filter(list));
    }
}
