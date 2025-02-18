package com.up202304387.Lab05.shapes;

public class Rectangle implements AreaShape {
    private double height;
    private double width;

    public Rectangle(double height, double width){
        this.height = height;
        this.width = width;
    }


    public double getHeight() {
        return height;
    }

    public double getWidth() {
        return width;
    }

    @Override
    public double getArea() {
        return height * width;
    }

    @Override
    public void draw() {
        System.out.println("Rectangle");
    }
}
