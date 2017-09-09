//
// Created by axoford12 on 9/9/17.
//

#include "vector_three_dimensional.h"
#include <math.h>
vector_three_dimensional vector_3d_construct(double x, double y, double z) {
    vector_three_dimensional v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

void vector_3d_add(vector_three_dimensional *v, double x, double y, double z) {
    v->x += x;
    v->y += y;
    v->z += z;
}

vector_three_dimensional vector_3d_get_side(vector_three_dimensional *v, double step,vector_3d_side side) {
    vector_three_dimensional result = *v;
    switch(side){
        case VECTOR_3_SIDE_DOWN:
            result.y -= step;
            break;
        case VECTOR_3_SIDE_UP:
            result.y += step;
            break;
        case VECTOR_3_SIDE_NORTH:
            result.z -= step;
            break;
        case VECTOR_3_SIDE_SOUTH:
            result.z += step;
            break;
        case VECTOR_3_SIDE_WEST:
            result.x -= step;
            break;
        case VECTOR_3_SIDE_EAST:
            result.x += step;
            break;
    }
    return result;
}

vector_3d_side vector_3d_oppo_side(vector_3d_side side) {
    if(side % 2 == 0){
        return side + 1;
    }
    return side - 1;
}

double vector_3d_get_distance(vector_three_dimensional *from, vector_three_dimensional *to) {
    return sqrt(vector_3d_get_distance_squared(from, to));
}

double vector_3d_get_distance_squared(vector_three_dimensional *from, vector_three_dimensional *to) {
    return (from->x - to->x)*(from->x - to->x)
           +(from->y - to->y)*(from->y - to->y)
           +(from->z - to->z)*(from->z - to->z);
}

double vector_3d_length_squared(vector_three_dimensional *v) {
    return v->x * v->x
           + v->y * v->y
           + v->z * v->z;
}

double vector_3d_length(vector_three_dimensional *v) {
    return sqrt(vector_3d_length_squared(v));
}

vector_three_dimensional vector_3d_cross(vector_three_dimensional *v, vector_three_dimensional *to) {
    vector_three_dimensional result;
    result.x = v->y * to->z - v->z * to->y;
    result.y = v->z * to->x - v->x * to->z;
    result.z = v->x * to->y - v->y * to->x;
    return result;
}

int vector_3d_equals(vector_three_dimensional *current, vector_three_dimensional *cmp) {
    return current->x == cmp->x
           && current->y == cmp->y
           && current->x == cmp->y;
}
