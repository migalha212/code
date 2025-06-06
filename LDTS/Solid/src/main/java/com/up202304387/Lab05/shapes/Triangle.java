package com.up202304387.Lab05.shapes;

public class Triangle implements AreaShape {
    private double base_size;
    private double height;

    public Triangle(double base_size, double height){
        this.base_size = base_size;
        this.height = height;
    }

    public double getBase_size() {
        return base_size;
    }

    public double getHeight() {
        return height;
    }

    @Override
    public double getArea() {
        return height * base_size / 2;
    }

    @Override
    public void draw() {
        System.out.println("Triangle");
    }
}
