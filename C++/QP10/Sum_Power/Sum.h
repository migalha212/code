#ifndef SUM_H
#define SUM_H

#include "Operation.h"

class Sum : public Operation{
public:
    Sum(int a, int b) : Operation(a,b) {}
    int operation() const{
        return get_op1() + get_op2();
    }
};

#endif 