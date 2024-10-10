#include "list.h"
#include <stdlib.h>

void list_add_first(int val, list *l) {
    node* p = node_new(val,NULL);
    if(l->size == 0) l->first = p;
    else{
        node* q = l->first;
        l->first = p;
        while(q->next != NULL){
            q = p;

        }
    }
}