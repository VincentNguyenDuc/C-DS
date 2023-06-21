struct ArraySet
{
    int capacity;
    void **array;
    int count;

    int (*compare_function)(const void *, const void *);
};

typedef struct ArraySet ArraySet;

ArraySet *set_init(int max_capacity, int (*comp)(const void *, const void *));

int set_get_length(const ArraySet *set_ptr);

int set_is_empty(const ArraySet *set_ptr);

int set_contain(const ArraySet *set_ptr, const void *item);

void set_clear(ArraySet *set_ptr);

int set_is_full(const ArraySet *set_ptr);

void set_add(ArraySet *set_ptr, void *item);

void set_remove(ArraySet *set_ptr, const void *item);

ArraySet *set_union(const ArraySet *this_set_ptr, const ArraySet *other_set_ptr);

ArraySet *set_intersection(const ArraySet *this_set_ptr, const ArraySet *other_set_ptr);

ArraySet *set_difference(const ArraySet *this_set_ptr, const ArraySet *other_set_ptr);

void set_destroy(ArraySet *set_ptr);
