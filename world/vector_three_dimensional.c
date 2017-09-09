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

double get_distance(vector_three_dimensional *from, vector_three_dimensional *to) {
    return sqrt(get_distance_squared(from,to));
}

double get_distance_squared(vector_three_dimensional *from, vector_three_dimensional *to) {
    return (from->x - to->x)*(from->x - to->x)
           +(from->y - to->y)*(from->y - to->y)
           +(from->z - to->z)*(from->z - to->z);
}
