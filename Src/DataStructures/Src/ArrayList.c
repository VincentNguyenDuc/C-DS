#include <stdlib.h>
#include "../Include/ArrayList.h"

/**
 * Initialization
 */
ArrayList *list_init(int length, int (*compare_function)(const void *, const void *))
{
    ArrayList *list_ptr = (ArrayList *)malloc(sizeof(ArrayList));
    list_ptr->array = (void **)malloc(sizeof(void *) * length);
    list_ptr->length = length > 0 ? length : 1;
    list_ptr->count = 0;
    list_ptr->compare_function = compare_function;
    return list_ptr;
}

/**
 * Return the item at a given index
 */
void *list_get_at_index(const ArrayList *list_ptr, int index)
{
    void *item = list_ptr->array[index];
    return item;
}

/**
 * Insert an item at a given index 
 */
void list_insert_at_index(ArrayList *list_ptr, void *item, int index)
{
    if (list_ptr->count == list_ptr->length)
    {
        list_ptr->length *= 2;
        list_ptr->array = (void **)realloc(list_ptr->array, sizeof(void *) * list_ptr->length);
    }
    for (int i = list_ptr->count; i > index; i--)
    {
        list_ptr->array[i] = list_ptr->array[i - 1];
    }
    list_ptr->count++;
    list_ptr->array[index] = item;
}

/**
 * Remove the element at a given index
 */
void list_del_at_index(ArrayList *list_ptr, int index)
{
    free(list_ptr->array[index]);
    list_ptr->count--;
    for (int i = index; i < list_ptr->count; i++) {
        list_ptr->array[i] = list_ptr->array[i + 1];
    }
}

/**
 * Append to the end
 */
void list_append(ArrayList *list_ptr, void *item)
{
    if (list_ptr->count == list_ptr->length)
    {
        list_ptr->length *= 2;
        list_ptr->array = (void **)realloc(list_ptr->array, sizeof(void *) * list_ptr->length);
    }
    list_ptr->array[list_ptr->count++] = item;
}

/**
 * Remove and return the last element
*/
void *list_pop(ArrayList *list_ptr) {
    void *item = list_ptr->array[list_get_length(list_ptr) - 1];
    list_ptr->count -= 1;
    return item;
}

/**
 * Check if an item is in the list
 * Return 1 if True, 0 otherwise
*/
short list_contain(const ArrayList *list_ptr, const void *item) {
    for (int i = 0; i < list_ptr->count; i++) {
        // True
        if (list_ptr->compare_function(item, list_ptr->array[i]) != 0) {
            return 1;
        }
    }
    // False
    return 0;
}

/**
 * Find the index of a given item.
 * Return the index if found, otherwise return -1
*/
int list_find_index(const ArrayList *list_ptr, const void *item) {
    for (int i = 0; i < list_ptr->count; i++) {
        if (list_ptr->compare_function(list_ptr->array[i], item)) {
            return i;
        }
    }
    return -1;
}

/**
 * Return the number of items
*/
int list_get_length(const ArrayList *list_ptr) {
    return list_ptr->count;
}

/**
 * Check if the list is empty or not
*/
int list_is_empty(const ArrayList *list_ptr) {
    return list_ptr->count == 0;
}

/**
 * Clear every items 
*/
void list_clear(ArrayList *list_ptr) {
    for (int i = 0; i < list_get_length(list_ptr); i++)
        free(list_ptr->array[i]);

    list_ptr->count = 0;
}

/**
 * Destroy everything 
*/
void list_destroy(ArrayList *list_ptr) {
    list_clear(list_ptr);
    free(list_ptr->array);
    free(list_ptr);
}
