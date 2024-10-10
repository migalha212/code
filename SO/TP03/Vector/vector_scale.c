#include "vector.h"

vector* vector_scale(double i, vector* v){
    return vector_new(v->x * i, v->y * i, v->z * i);
}