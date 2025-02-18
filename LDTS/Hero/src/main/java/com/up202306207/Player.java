package com.up202306207;

import com.googlecode.lanterna.TextCharacter;
import com.googlecode.lanterna.screen.Screen;

public class Player {
    private int x;
    private int y;

    Player(int x, int y){
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int moveUp(){
        return y--;
    }

    public int moveDown(){
        return y++;
    }

    public int moveLeft(){
        return x--;
    }

    public int moveRight(){
        return x++;
    }

    public void draw(Screen screen){
        screen.setCharacter(x, y, TextCharacter.fromCharacter('S')[0]);
    }


}
