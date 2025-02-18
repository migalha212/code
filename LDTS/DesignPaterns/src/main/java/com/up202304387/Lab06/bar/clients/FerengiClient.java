package com.up202304387.Lab06.bar.clients;

import com.up202304387.Lab06.bar.strategies.OrderingStrategy;
import com.up202304387.Lab06.bar.strategies.SmartStrategy;

public class FerengiClient extends AlienClient{
    public FerengiClient(){
        super();
    }
    @Override
    protected OrderingStrategy createOrderingStrategy() {
        return new SmartStrategy();
    }
}
