typedef struct Element
{
    void *key;  
    void *data;

} Element;

typedef struct LinearProbeTable
{
    Element **array;
    int count;
    int table_size;
    int (*comp_function)(const void *, const void *);
    int size_index;
    int (*hash_func)(const void *);

} LinearProbeTable;

LinearProbeTable *table_init(int (*comp_function)(const void *, const void *), int (*hash_func)(const void *));

void table_set_item(LinearProbeTable *table, void* key, void *item);

void *table_get_item(const LinearProbeTable *table, const void *key);

void table_del_item(LinearProbeTable *table, const void *key);

int table_contain(LinearProbeTable *table, char key[]);

int table_get_length(const LinearProbeTable *table);

void table_clear(LinearProbeTable *table);

void table_destroy(LinearProbeTable *table);

