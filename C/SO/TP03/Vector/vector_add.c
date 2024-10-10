#include "vector.h"

vector* vector_add(vector* v, vector* c){
    return vector_new(v->x + c->x, v->y + c->y, v->z+ c->z);
}