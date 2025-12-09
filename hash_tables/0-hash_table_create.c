#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: Size of the array
 *
 * Return: Pointer to newly created hash table, or NULL if fails
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht = NULL;
	unsigned long int i;

	/* Allocate memory for hash table structure */
	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	/* Allocate memory for array */
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	/* Initialize each element of array to NULL */
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	/* Set size */
	ht->size = size;

	return (ht);
}
