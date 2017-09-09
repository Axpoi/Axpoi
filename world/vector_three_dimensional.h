//
// Created by axoford12 on 9/9/17.
//


#ifndef AXPOI_VECTOR_THREE_DEMENSIONAL_H
#define AXPOI_VECTOR_THREE_DEMENSIONAL_H
typedef enum {
    VECTOR_3_SIDE_DOWN = 0,
    VECTOR_3_SIDE_UP,
    VECTOR_3_SIDE_NORTH,
    VECTOR_3_SIDE_SOUTH,
    VECTOR_3_SIDE_WEST,
    VECTOR_3_SIDE_EAST
} vector_3d_side;
typedef struct {
    double x, y, z;
} vector_three_dimensional;

vector_three_dimensional vector_3d_construct(double x, double y, double z);

void vector_3d_add(vector_three_dimensional *v, double x, double y, double z);

vector_three_dimensional vector_3d_get_side(vector_three_dimensional *v, double step, vector_3d_side side);

vector_3d_side vector_3d_oppo_side(vector_3d_side side);

double get_distance(vector_three_dimensional* from,vector_three_dimensional* to);

double get_distance_squared(vector_three_dimensional* from,vector_three_dimensional* to);
#endif //AXPOI_VECTOR_THREE_DEMENSIONAL_H
