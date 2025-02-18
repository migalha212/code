package com.up202304387.Lab05.sumProviders;

import com.up202304387.Lab05.shapes.House;

import java.util.ArrayList;
import java.util.List;

public class City implements SumProvider {
    private List<House> houseList = new ArrayList<>();

    public void addHouse(House house){
        houseList.add(house);
    }

    public City(List<House> houseList){
        this.houseList = houseList;
    }
    public double sum(){
        double sum = 0;
        for (House house : houseList){
            sum += house.getArea();
        }
        return sum;
    }
}
