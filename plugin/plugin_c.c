//
// Created by axoford12 on 9/8/17.
//

#include "plugin_c.h"
#include <stdio.h>
void plugin_init(list *config) {
    node * path_node = list_get(config,"plugin_path",sizeof("plugin_path"));
    if (path_node == NULL){
#ifdef DEBUG
        printf("[DEBUG]Plugin config not found.\n");
#endif
        return;
    }
    char * path = path_node->value;
#ifdef DEBUG
    printf("[DEBUG]got path:%s\n",path);
#endif
}
