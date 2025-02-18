package com.up202304387.Lab06.bar;

import com.up202304387.Lab06.bar.clients.BarObserver;

import java.util.ArrayList;
import java.util.List;

public abstract class Bar {
    private boolean happyHour;
    private List<BarObserver> observers;
    abstract public boolean isHappyHour();
    abstract public void startHappyHour();
    abstract public void endHappyHour();
    public Bar(){
        this.happyHour = false;
        this. observers = new ArrayList<>();
    }
    public void addObserver(BarObserver observer) {
        observers.add(observer);
    }
    public void removeObserver(BarObserver observer) {
        observers.remove(observer);
    }
    public void notifyObservers() {
        for (BarObserver observer : observers)
            if (isHappyHour()) observer.happyHourStarted(this);
            else observer.happyHourEnded(this);
    }
}
