package com.up202304387.Lab05.shapes;

public class Circle implements AreaShape {
    private final double radius;

    public Circle(double radius){
        this.radius = radius;
    }
    public double getRadius() {
        return this.radius;
    }

    @Override
    public double getArea() {
        return Math.PI * Math.pow(radius,2);
    }

    @Override
    public void draw() {
        System.out.println("Circle");
    }
}
