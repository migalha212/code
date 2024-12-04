#include "vector.h"

double vector_sprod(vector* v, vector* c){
    return (v->x * c->x + v->y * c->y + v->z * c->z);
}