package com.aor.numbers;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class ListFilterer {
    private final GenericListFilter filter;
    public ListFilterer(GenericListFilter filter) {
        this.filter = filter;
        }


    public List<Integer> filter(List<Integer> list){
        List<Integer> sol = new java.util.ArrayList<>(Collections.emptyList());
        for(Integer i : list){
            if(filter.accept(i))
                sol.add(i);
        }
        return sol;
    }

}
