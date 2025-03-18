/*This is the list.h file for my code*/

typedef struct list List;
struct list{
    int data;
    List *next;
};

List *list_prepend(List *l,int data);
List *list_add_after_first(List *l,int data);
List *list_merge(List *l1,List *l2);