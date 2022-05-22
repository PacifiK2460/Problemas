/*
    Martinez Lara Santiago de la cruz

    A linked List is a array where u dont have to worry about the lenght, only about the memory (it uses double of it)
    - To create one just type; struct linked list *[var_name];
    meths:
    - append(&[var_name], thing_to_append (int)) / Well, it appends someting to the list.
    - item(index (int)) / Returns the value at indicated index.
*/
#include <stdlib.h>
short int initialized = 0;
struct linked_list{
    int value;
    struct linked_list *next;
};
void append(struct linked_list **list,int n){
    if(initialized){
        struct linked_list *tmp = (struct linked_list*)(malloc(sizeof(struct linked_list)));
        tmp -> value = n;
        while(*list != NULL)
            list = &((*list) -> next);
        *list = tmp;
    }
    else{
        *list = (struct linked_list*)(malloc(sizeof(struct linked_list)));
        (*list) -> value = n;
        initialized = 1;
    }
}
int item(struct linked_list *list,int n){
    for(int i=0;i<n;i++)
        list = list -> next;
    return list -> value;
}
