#include <math.h>
#include "complex.h"
double complex_arg(complex* z){
    return atan2(z->y,z->x);
}
