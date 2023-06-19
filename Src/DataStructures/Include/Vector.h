struct Vector {
    void** array;
    int length;
    int count;

    void (*free_function)(void*);
    int (*compare_function)(const void*, const void*);
};

typedef struct Vector Vector;

Vector *vector_init(int length, void (*free_function)(void *), int (*compare_function)(const void *, const void *));

void vector_append(Vector* vector_ptr, void* item);

void vector_insert(Vector* vector_ptr, void* item, int index);

void* vector_del(Vector* vector_ptr, int index);

short vector_contain(Vector* vector_ptr, void* item);

int vector_index(Vector* vector_ptr);

int vector_get_length(Vector* vector_ptr);

int vector_is_empty(Vector* vector_ptr);

void vector_clear(Vector* vector_ptr);

void vector_destroy(Vector* vector_ptr);
