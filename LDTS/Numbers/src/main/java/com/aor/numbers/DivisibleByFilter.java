package com.aor.numbers;

public class DivisibleByFilter implements GenericListFilter{
    private Integer denominator;
    public DivisibleByFilter(Integer denominator){
        this.denominator = denominator;
    }

    @Override
    public boolean accept(Integer number){
        if(denominator == 0) return false;
        return (number % denominator == 0);
    }
}
