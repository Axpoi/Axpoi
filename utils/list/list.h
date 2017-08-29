//
// Created by axoford12 on 8/29/17.
//

#ifndef AXPOI_LIST_H
#define AXPOI_LIST_H
typedef struct node{
    void* key;
    void* value;
    struct node* next;
    struct node* before;
}node;

typedef struct  list{
    node* first;
    node* last;
    void*(*get)(struct list* l,void* target);
    void(*destruct)(struct list* l);
    void(*delete)(struct list* l,void* target);
    void(*add)(struct list* l,void* pos,void* key,void* value);
}list;
void list_construct(list* l);
#endif //AXPOI_LIST_H
