package com.up202304387.Lab06.stringtranformers;

import com.up202304387.Lab06.StringDrink;

import java.util.List;

public class StringTransformerGroup implements StringTransformer{
    private List<StringTransformer> group;

    public StringTransformerGroup(List<StringTransformer> group){
        this.group = group;
    }

    @Override
    public void execute(StringDrink drink){
        for(StringTransformer st : group){
            st.execute(drink);
        }
    }
    @Override
    public void undo(StringDrink drink){
        for(StringTransformer st :group){
            st.undo(drink);
        }
    }
}
