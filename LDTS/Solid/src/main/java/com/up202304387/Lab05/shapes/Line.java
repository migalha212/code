package com.up202304387.Lab05.shapes;

public class Line implements Shape{
    private double length;

    public Line(double length){
        this.length = length;
    }

    public double getLength() {
        return length;
    }

    @Override
    public void draw() {
        System.out.println("Line");
    }
}
