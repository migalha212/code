package com.up202304387.Lab06.bar.clients;

import com.up202304387.Lab06.bar.strategies.ImpatientStrategy;
import com.up202304387.Lab06.bar.strategies.OrderingStrategy;

public class RomulanClient extends AlienClient{
    public RomulanClient(){
        super();
    }
    @Override
    protected OrderingStrategy createOrderingStrategy() {
        return new ImpatientStrategy();
    }
}
