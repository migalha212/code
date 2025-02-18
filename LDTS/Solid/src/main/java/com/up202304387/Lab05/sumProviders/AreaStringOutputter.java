package com.up202304387.Lab05.sumProviders;

public class AreaStringOutputter {

    private SumProvider sumProvider;

    public AreaStringOutputter(SumProvider sumProvider) {
        this.sumProvider = sumProvider;
    }

    public String output() {
        return "" + sumProvider.sum();
    }

}
