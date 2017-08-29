//
// Created by axoford12 on 8/29/17.
//

#include <stdlib.h>
#include <memory.h>
#include "list.h"



void list_destruct(list *l) {
    if(l == NULL)
        return;
    if(l->first == NULL){
        free(l);
        return;
    }
    node* first = l->first;
    l->first = l->first->next;
    free(first->key);
    free(first->value);
    free(first);
    list_destruct(l);
}




void *list_get(list *l, void *target, size_t mem_cmp_len) {
    node* current = l->first;
    while(current->next != NULL){
        if(!memcmp(current->key,target,mem_cmp_len)){
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}



void list_delete(list *l, void *target, size_t target_mem_length) {
    node *delete_node = list_get(l, target,target_mem_length);
    if(target == NULL) return;
    if(delete_node->before != NULL){
        // 前驱是有的
        // 这个东西是在一个链表的中间位置,或者最后位置
        if(delete_node->next != NULL){
            // 中间位置
            delete_node->before->next = delete_node->next->next;

        } else {
            delete_node->before->next = NULL;
        }

    } else {
        // 前驱没有,说明在first.
        if(delete_node->next != NULL)
            l->first = l->first->next;
        else
            // 后继也没有
            l->first = NULL;
    }
    free(delete_node->value);
    free(delete_node->key);
    free(delete_node);
}



void list_add(list *l, void *pos, size_t pos_mem_len, void *key, void *value) {
    node* new = malloc(sizeof(node));
    new->key = key;
    new->value = value;
    if(pos == NULL){
        new->next = l->first;
        l->first->before = new;
        l->first = new;
        // 添加到最前
    } else {
        node* current = list_get(l,pos,pos_mem_len);
        if(current == NULL){
            return;
        }
        new->next = current;
        if(current->before == NULL)
            l->first = new;
        else
            new->before = current->before;
        current->before->next = new;
    }


}


void list_construct(list** l) {
    *l = malloc(sizeof(list));
    node* first = malloc(sizeof(node));
    first->next = NULL;
    (*l)->first = first;
    first->before = NULL;
}