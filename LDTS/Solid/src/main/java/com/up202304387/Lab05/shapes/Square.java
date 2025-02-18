package com.up202304387.Lab05.shapes;

public class Square implements AreaShape {
    private final double side;

    public Square(double side){
        this.side = side;
    }

    public double getSide() {
        return side;
    }

    @Override
    public double getArea() {
        return Math.pow(side,2);
    }

    @Override
    public void draw() {
        System.out.println("Square");
    }
}
