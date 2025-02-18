package com.up202304387.Lab05.sumProviders;

public class AreaXMLOutputter {

    private SumProvider sumProvider;

    public AreaXMLOutputter(SumProvider sumProvider) {
        this.sumProvider = sumProvider;
    }

    public String output() {
        return "<area>" + sumProvider.sum() + "</area>";
    }
}
