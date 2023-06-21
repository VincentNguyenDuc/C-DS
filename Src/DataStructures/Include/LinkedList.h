struct LinkedList {
    struct Node *head;
    int length;

    int (*compare_function)(const void *, const void *);
};

typedef struct LinkedList LinkedList;

LinkedList *linked_list_init(int (*compare_function)(const void *, const void *));

void linked_list_clear(LinkedList *linked_list_ptr);

void linked_list_destroy(LinkedList *linked_list_ptr);

void linked_list_set_item(LinkedList *linked_list_ptr, int index, void *item);

void *linked_list_get_item(LinkedList *linked_list_ptr, int index);

void linked_list_delete_at_index(LinkedList *linked_list_ptr, int index);



