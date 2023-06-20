
/**
 * Struct of the vector
 */
struct ArrayList
{
    void **array;
    int length;
    int count;

    void (*free_function)(void *);
    int (*compare_function)(const void *, const void *);
};

typedef struct ArrayList ArrayList;

ArrayList *list_init(int length, void (*free_function)(void *), int (*compare_function)(const void *, const void *));

void *list_get_at_index(const ArrayList *list_ptr, int index);

void list_insert_at_index(ArrayList *list_ptr, void *item, int index);

void list_del_at_index(ArrayList *list_ptr, int index);

void list_append(ArrayList *list_ptr, void *item);

void *list_pop(ArrayList *list_ptr);

short list_contain(const ArrayList *list_ptr, const void *item);

int list_find_index(const ArrayList *list_ptr, const void *item);

int list_get_length(const ArrayList *list_ptr);

int list_is_empty(const ArrayList *list_ptr);

void list_clear(ArrayList *list_ptr);

void list_destroy(ArrayList *list_ptr);
