#include "hash_tables.h"
#include <string.h>

/**
 * update_node - Updates the value of an existing key
 * @node: Pointer to the node to update
 * @value: The new value (string)
 *
 * Return: 1 on success, 0 on failure
 */
int update_node(hash_node_t *node, const char *value)
{
	char *value_dup = strdup(value);

	if (!value_dup)
		return (0);

	free(node->value);
	node->value = value_dup;

	return (1);
}

/**
 * add_node - Adds a new node to the beginning of a list
 * @head: Pointer to the head of the linked list
 * @key: The key
 * @value: The value
 *
 * Return: 1 on success, 0 on failure
 */
int add_node(hash_node_t **head, const char *key, const char *value)
{
	hash_node_t *new_node = malloc(sizeof(hash_node_t));

	if (!new_node)
		return (0);

	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	if (!new_node->value)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	new_node->next = *head;
	*head = new_node;

	return (1);
}

/**
 * hash_table_set - Adds or updates an element in a hash table
 * @ht: Pointer to the hash table
 * @key: Key (cannot be an empty string)
 * @value: Value associated with the key (duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node;

	if (!ht || !key || !(*key) || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (update_node(node, value));

		node = node->next;
	}

	return (add_node(&(ht->array[index]), key, value));
}

