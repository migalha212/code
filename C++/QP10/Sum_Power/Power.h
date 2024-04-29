#ifndef POWER_H
#define POWER_H

#include "Operation.h"

class Power : public Operation {
public: 
    Power(int a,int b) : Operation(a,b) {}
    int operation() const {
        int res = 1;
        for(int i = 0; i < get_op2();i++){
            res *= get_op1();
        }
        return res;
    }
};
#endif