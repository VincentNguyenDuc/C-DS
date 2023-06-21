#include <stdlib.h>
#include "../Include/LinkedList.h"

typedef struct Node
{
	void *item;
	struct Node *next;
} Node;

/**
 * Initialization of a linked list
 */
LinkedList *linked_list_init(int (*compare_function)(const void *, const void *))
{
	LinkedList *linked_list = (LinkedList *)malloc(sizeof(LinkedList));
	linked_list->head = NULL;
	linked_list->length = 0;
	linked_list->compare_function = compare_function;

	return linked_list;
}

/**
 * Free all item within the linked list
*/
void linked_list_clear(LinkedList *linked_list)
{
	Node *current = linked_list->head;
	Node *prev;
	while (current != NULL)
	{
		prev = current;
		current = current->next;
		free(prev->item);
		free(prev);
	}
	linked_list->head = NULL;
	linked_list->length = 0;
}

/**
 * Free all memory
*/
void linked_list_destroy(LinkedList *linked_list)
{
	linked_list_clear(linked_list);
	free(linked_list);
}

/**
 * Get node at a given index
*/
void *linked_list_get_item(LinkedList *linked_list, int index) {
	if (index >= 0 && index < linked_list->length) {
		Node* current = linked_list->head;
		while (index > 0) {
			current = current->next;
			index--;
		}
		return current->item;
	}
}

/**
 * Insert an item to a given index
*/
void linked_list_set_item(LinkedList *linked_list, int index, void *item) {
	if (index >= 0 && index < linked_list->length) {
		Node* current = linked_list->head;
		Node* prev = NULL;
		while (index > 0) {
			prev = current;
			current = current->next;
			index--;
		}
		Node *node_to_insert = (Node *)malloc(sizeof(Node));
		node_to_insert->item = item;
		node_to_insert->next = current;
		prev->next = node_to_insert;
	}
}

/**
 * Delete the item at a given index
*/
void linked_list_delete_at_index(LinkedList *linked_list, int index) {
	if (index >= 0 && index < linked_list->length) {
		Node* current = linked_list->head;
		Node* prev = NULL;
		while (index > 0) {
			prev = current;
			current = current->next;
			index--;
		}
		Node* node_to_delete = current;
		prev->next = current->next;
		free(node_to_delete->item);
		free(node_to_delete);
	}
}

