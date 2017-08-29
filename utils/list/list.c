//
// Created by axoford12 on 8/29/17.
//

#include <stdlib.h>
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


void* list_get(list *l, void *target) {
    node* current = l->first;
    while(current->next != NULL){
        if(current->key == target){
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

void list_delete(list *l,void *target) {
    node *delete_node = l->get(l, target);
    if(target == NULL) return;
    if(delete_node->before != NULL){
        // 前驱是有的
        // 这个东西是在一个链表的中间位置,或者最后位置
        if(delete_node->next != NULL){
            // 中间位置
            delete_node->before->next = delete_node->next->next;

        } else {
            l->last = delete_node->before;
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
void list_add(list* l,void* pos,void* key,void* value){
    node* new = malloc(sizeof(node));
    new->key = key;
    new->value = value;
    if(pos == NULL){
        new->next = NULL;
        l->last = new;
        // 添加到最后
    } else {
        node* current = l->get(l,pos);
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


void list_construct(list* l) {
    l = malloc(sizeof(list));
    l->get = &list_get;
    l->destruct = &list_destruct;
    l->delete = &list_delete;
    l->add = &list_add;
    l->first = malloc(sizeof(node));
    l->last = malloc(sizeof(node));
}