#include "hash_tables.h"

void insert_sorted_list(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *cur;

	if (!ht->shead)
	{
		ht->shead = node;
		ht->stail = node;
		return;
	}

	cur = ht->shead;
	while (cur && strcmp(node->key, cur->key) > 0)
		cur = cur->snext;

	if (!cur)
	{
		node->sprev = ht->stail;
		ht->stail->snext = node;
		ht->stail = node;
	}
	else if (!cur->sprev)
	{
		node->snext = cur;
		cur->sprev = node;
		ht->shead = node;
	}
	else
	{
		node->snext = cur;
		node->sprev = cur->sprev;
		cur->sprev->snext = node;
		cur->sprev = node;
	}
}

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *tmp;
	unsigned long int i;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			tmp = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = tmp;
		}
	}

	free(ht->array);
	free(ht);
}

