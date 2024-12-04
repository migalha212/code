#include "vector.h"

vector* vector_vprod(vector* v, vector* c){
    	return vector_new(v->y * c->z - v->z * c->y,
                           v->z * c->x - v->x * c->z,
                            v->x * c->y - v->y * c->x);
}