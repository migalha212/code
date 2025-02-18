package com.aor.numbers;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;
import sun.jvm.hotspot.utilities.Assert;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ListAggregatorTest {
    private  List<Integer> list;
    private  ListAggregator aggregator;

    class StubDeduplicator implements GenericListDeduplicator {
        @Override
        public List<Integer> deduplicate(List<Integer> list) {

            return Arrays.asList(1,2,4); // Return the distinct elements
        }
    }
    @BeforeEach
    public void helper(){
        list = Arrays.asList(1,2,4,2,5); // lista a ser usada nos testes
        aggregator = new ListAggregator(); //instanciar o aggregator uma unica vez
    }

    @Test
    public void sum() {
        int sum = aggregator.sum(list);

        Assertions.assertEquals(14, sum);
    }

    @Test
    public void max() {
        int max = aggregator.max(list);

        Assertions.assertEquals(5, max);
    }

    @Test
    public void max2(){
        List<Integer> list1 = Arrays.asList(-1,-4,-5);

        int max = aggregator.max(list1);

        Assertions.assertEquals(-1,max);
    }

    @Test
    public void min() {
        int min = aggregator.min(list);

        Assertions.assertEquals(1, min);
    }

    @Test
    public void distinct() {
        GenericListDeduplicator deduplicator = new ListDeduplicator();
        int distinct = aggregator.distinct(list,deduplicator);

        Assertions.assertEquals(4, distinct);
    }

    @Test
    public void distinct2(){

        aggregator = new ListAggregator();
        GenericListDeduplicator deduplicator = Mockito.mock(GenericListDeduplicator.class);
        Mockito.when(deduplicator.deduplicate(Mockito.anyList())).thenReturn(Arrays.asList(1, 2, 4));
        int distinct = aggregator.distinct(Arrays.asList(1,2,4,2),deduplicator);

        Assertions.assertEquals(3,distinct);
    }

    @Test
    public void sorted(){
        ListSorter listSorter = new ListSorter();
        List<Integer> sorted = listSorter.sort(Arrays.asList(1,2,4,2));
        List<Integer> solution = Arrays.asList(1, 2, 2, 4);
        Assertions.assertEquals(solution,sorted);

    }
}
