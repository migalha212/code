package com.up202304387.Lab05.shapes;

public class House implements HasArea {
    private final double area;

    public House(double area){
        this.area = area;
    }


    public double getArea() {
        return area;
    }
}
