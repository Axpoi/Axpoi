//
// Created by axoford12 on 8/29/17.
//

#ifndef AXPOI_LIST_H
#define AXPOI_LIST_H

#include<stddef.h>

typedef struct node {
    void *key;
    void *value;
    struct node *next;
    struct node *before;
} node;

typedef struct {
    node *first;
} list;

void list_construct(list **l);

node *list_get(list *l, void *target, size_t mem_cmp_len);

void list_destruct(list *l);

void list_delete(list *l, void *target, size_t target_mem_length);

void list_add(list *l, void *pos, size_t pos_mem_len, void *key, void *value);

#endif //AXPOI_LIST_H
