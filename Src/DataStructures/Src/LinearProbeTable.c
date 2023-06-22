#include <stdlib.h>
#include <assert.h>
#include "../Include/LinearProbeTable.h"

int TABLE_SIZES[10] = {5, 13, 29, 53, 97, 193, 389, 769, 1543, 3079};

/**
 * Find the correct position of a key within a table using linear probing
*/
int _linear_probe(const LinearProbeTable *table, const void *key, int is_insert)
{
    int position = table->hash_func(key);
    for (int i = 0; i < table->table_size; ++i)
    {
        if (table->array[position] == NULL)
        {
            if (is_insert)
            {
                return position;
            }
            else
            {
                assert("Key Error");
            }
        }
        else if (table->comp_function(table->array[position]->key, key))
        {
            return position;
        }
        else
        {
            position = (position + 1) % table->table_size;
        }
    }
    if (is_insert)
    {
        assert("Full Error");
    }
    else
    {
        assert("Key Error");
    }
}

/**
 * Move all items from the old table to a new table, and destroy the old table
*/
LinearProbeTable *_rehash(LinearProbeTable* old_table) {
    LinearProbeTable *new_table = (LinearProbeTable *)malloc(sizeof(LinearProbeTable));
    new_table->size_index = old_table->size_index + 1;
    new_table->table_size = TABLE_SIZES[new_table->size_index];
    new_table->array = (Element **)calloc(sizeof(Element *), new_table->table_size);
    new_table->comp_function = old_table->comp_function;
    new_table->hash_func = old_table->hash_func;
    for (int i = 0; i < new_table->table_size; ++i)
    {
        new_table->array[i] = NULL;
    }
    for (int i = 0; i < old_table->table_size; ++i) 
    {
        if (old_table->array[i] != NULL) {
            void* key = old_table->array[i]->key;
            void* item = old_table->array[i]->data;
            table_set_item(new_table, key, item);
        }
    }
    table_destroy(old_table);
    return new_table;
}

/**
 * Table initialization
*/
LinearProbeTable *table_init(int (*comp_function)(const void *, const void *), int (*hash_func)(const void *))
{
    LinearProbeTable *table = (LinearProbeTable *)malloc(sizeof(LinearProbeTable));
    table->size_index = 0;
    table->count = 0;
    table->table_size = TABLE_SIZES[table->size_index];
    table->array = (Element **)calloc(sizeof(Element *), table->table_size);
    table->comp_function = comp_function;
    table->hash_func = hash_func;

    for (int i = 0; i < table->table_size; ++i)
    {
        table->array[i] = NULL;
    }

    return table;
}

/**
 * Find the data using a given key 
*/
void* table_get_item(const LinearProbeTable *table, const void *key) {
    int position = _linear_probe(table, key, 0);
    return table->array[position]->data;
}

/**
 * Insert a key-item pair (Element struct) into the table
*/
void table_set_item(LinearProbeTable *table, void *key, void *item) {
    int position = _linear_probe(table, key, 1);
    if (table->array[position] == NULL) {
        table->count += 1;
    }

    Element element = {.key=key, .data=item};
    table->array[position] = &element;  
}

/**
 * Delete an Element using a given key
*/
void table_del_item(LinearProbeTable *table, const void *key) {
    int position = _linear_probe(table, key, 0);
    Element* element = table->array[position];
    table->array[position] = NULL;
    free(element->data);
    free(element->key);
    free(element);

    position = (position + 1) % table->table_size;
    while (table->array[position] != NULL) {
        Element* next_element = table->array[position];
        int new_position = _linear_probe(table, key, 1);
        table->array[new_position] = next_element;
    }
}

/**
 * Return the number of items within the table
*/
int table_get_length(const LinearProbeTable *table) {
    return table->count;
}

/**
 * Set every position within the table to NULL and free all Elements
*/
void table_clear(LinearProbeTable *table) {
    for (int i = 0; i < table->table_size; ++i) {
        if (table->array[i] != NULL) {
            Element *element = table->array[i];
            table->array[i] = NULL;
            free(element->data);
            free(element->key);
            free(element);
        }
    }
    table->count = 0;
}

/**
 * Destroy the table
*/
void table_destroy(LinearProbeTable *table) {
    table_clear(table);
    free(table->array);
    free(table);
}