#include "../Include/ArraySet.h"
#include <stdlib.h>

/**
 * Create and return a pointer to the array set
 */
ArraySet *set_init(int max_capacity, int (*comp)(const void *, const void *))
{
    ArraySet *set = (ArraySet *)malloc(sizeof(ArraySet));
    set->capacity = max_capacity < 10 ? 10 : max_capacity; // default capacity is 10
    set->array = (void **)malloc(sizeof(void *) * set->capacity);
    set->count = 0;
    set->compare_function = comp;
    return set;
}

/**
 * Get the number of items within the set
*/
int set_get_length(const ArraySet *set_ptr)
{
    return set_ptr->count;
}

/**
 * Check if the set is empty or not
*/
int set_is_empty(const ArraySet *set_ptr)
{
    return set_ptr->count == 0;
}

/**
 * Check if an item is within the set or not
*/
int set_contain(const ArraySet *set_ptr, const void *item)
{
    for (int i = 0; i < set_ptr->count; i++) {
        if (set_ptr->compare_function(set_ptr->array[i], item) != 0) {
            return 1;
        }
    }
    return 0;
}

/**
 * Clear every items within the set
*/
void set_clear(ArraySet *set_ptr) {
    for (int i = 0; i < set_ptr->count; i++) {
        free(set_ptr->array[i]);
    }
    set_ptr->count = 0;
}

/**
 * Check if the set is full or not
*/
int set_is_full(const ArraySet *set_ptr) {
    return set_ptr->count == set_ptr->capacity;
}

/**
 * Add an item into the set
*/
void set_add(ArraySet *set_ptr, void *item) {
    if (!set_contain(set_ptr, item)) {
        if (set_is_full(set_ptr)) {
            set_ptr->capacity *= 2;
            set_ptr->array = (void **)realloc(set_ptr->array, sizeof(void *) * set_ptr->capacity);
        } else {
            set_ptr->array[set_ptr->count] = item;
            set_ptr->count += 1;
        }
    }
}

/**
 * Remove an item from the set
*/
void set_remove(ArraySet *set_ptr, const void *item) {
    for (int i = 0; i < set_ptr->count; i++) {
        if (set_ptr->compare_function(set_ptr->array[i], item) != 0) {
            set_ptr->array[i] = set_ptr->array[set_ptr->count - 1];
            set_ptr->count -= 1;
            break;
        }
    }
}

/**
 * Return the union set of 2 given sets
*/
ArraySet *set_union(const ArraySet *this_set_ptr, const ArraySet *other_set_ptr)
{
    int total_capacity = this_set_ptr->capacity + other_set_ptr->capacity;
    ArraySet *result_set = set_init(total_capacity, this_set_ptr->compare_function);

    for (int i = 0; i < this_set_ptr->count; i++) {
        void *item = this_set_ptr->array[i];
        set_add(result_set, item);
    }

    for (int i = 0; i < other_set_ptr->count; i++)
    {
        void *item = other_set_ptr->array[i];
        set_add(result_set, item);
    }

    return result_set;
}

/**
 * Return the intersection set of 2 given sets
*/
ArraySet *set_intersection(const ArraySet *this_set_ptr, const ArraySet *other_set_ptr) {
    int min_capacity = this_set_ptr->capacity <= other_set_ptr->capacity ? this_set_ptr->capacity : other_set_ptr->capacity;
    ArraySet *result_set = set_init(min_capacity, this_set_ptr->compare_function);
    for (int i = 0; i < this_set_ptr->count; i++) {
        void *item = this_set_ptr->array[i];
        if (set_contain(other_set_ptr, item)) {
            set_add(result_set, item);
        }
    }
    return result_set;
}

/**
 * Return the difference set of this set to other set (items in this_set but not in other_set)
*/
ArraySet *set_difference(const ArraySet *this_set_ptr, const ArraySet *other_set_ptr) {
    int capacity = this_set_ptr->capacity;
    ArraySet *result_set = set_init(capacity, this_set_ptr->compare_function);
    for (int i = 0; i < this_set_ptr->count; i++) {
        void *item = this_set_ptr->array[i];
        if (!set_contain(other_set_ptr, item)) {
            set_add(result_set, item);
        }
    }
    return result_set;
}

/**
 * Free all space
*/
void set_destroy(ArraySet *set_ptr) {
    set_clear(set_ptr);
    free(set_ptr->array);
    free(set_ptr);
}