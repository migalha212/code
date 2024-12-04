#include "vector.h"

vector* vector_sub(vector* v, vector*c){
    return vector_new(v->x - c->x, v->y - c->y, v->z - c->z);
}