#include <stdlib.h>
#include "complex.h"

complex* complex_new(double x, double y) {
    complex* z = (complex*) malloc(sizeof(complex));
    z->x = x;
    z->y = y;
return z;
}