#include "hash_tables.h"

/**
 * create_shash_node - creates a sorted hash node
 */
shash_node_t *create_shash_node(const char *key, const char *value)
{
    shash_node_t *node = malloc(sizeof(shash_node_t));
    if (!node) return NULL;
    
    node->key = strdup(key);
    if (!node->key) {
        free(node);
        return NULL;
    }
    
    node->value = strdup(value);
    if (!node->value) {
        free(node->key);
        free(node);
        return NULL;
    }
    
    node->next = NULL;
    node->sprev = NULL;
    node->snext = NULL;
    return node;
}

/**
 * insert_sorted - inserts node in sorted position
 * Return: 1 on success
 */
int insert_sorted(shash_table_t *ht, shash_node_t *node)
{
    shash_node_t *tmp;
    
    if (!ht->shead || strcmp(node->key, ht->shead->key) < 0) {
        node->snext = ht->shead;
        if (ht->shead) ht->shead->sprev = node;
        else ht->stail = node;
        ht->shead = node;
        return 1;
    }
    
    tmp = ht->shead;
    while (tmp->snext && strcmp(node->key, tmp->snext->key) > 0)
        tmp = tmp->snext;
    
    node->snext = tmp->snext;
    node->sprev = tmp;
    if (tmp->snext) tmp->snext->sprev = node;
    else ht->stail = node;
    tmp->snext = node;
    
    return 1;
}

/**
 * shash_table_create - creates sorted hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht = malloc(sizeof(shash_table_t));
    if (!ht) return NULL;
    
    ht->size = size;
    ht->array = calloc(size, sizeof(shash_node_t *));
    if (!ht->array) {
        free(ht);
        return NULL;
    }
    
    ht->shead = NULL;
    ht->stail = NULL;
    return ht;
}

/**
 * shash_table_set - adds element to sorted hash table
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *node, *tmp;
    char *new_val;
    
    if (!ht || !key || !*key || !value) return 0;
    
    index = key_index((const unsigned char *)key, ht->size);
    
    /* Check if key exists */
    tmp = ht->array[index];
    while (tmp) {
        if (strcmp(tmp->key, key) == 0) {
            new_val = strdup(value);
            if (!new_val) return 0;
            free(tmp->value);
            tmp->value = new_val;
            return 1;
        }
        tmp = tmp->next;
    }
    
    /* Create new node */
    node = create_shash_node(key, value);
    if (!node) return 0;
    
    /* Insert into hash array */
    node->next = ht->array[index];
    ht->array[index] = node;
    
    /* Insert into sorted list */
    return insert_sorted(ht, node);
}

/**
 * shash_table_get - retrieves value by key
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    shash_node_t *node;
    unsigned long int index;
    
    if (!ht || !key || !*key) return NULL;
    
    index = key_index((const unsigned char *)key, ht->size);
    node = ht->array[index];
    
    while (node) {
        if (strcmp(node->key, key) == 0)
            return node->value;
        node = node->next;
    }
    
    return NULL;
}

/**
 * shash_table_print - prints sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;
    int first = 1;
    
    if (!ht) return;
    
    printf("{");
    node = ht->shead;
    while (node) {
        if (!first) printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        first = 0;
        node = node->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - prints in reverse order
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;
    int first = 1;
    
    if (!ht) return;
    
    printf("{");
    node = ht->stail;
    while (node) {
        if (!first) printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        first = 0;
        node = node->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - deletes sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
    unsigned long int i;
    shash_node_t *node, *next;
    
    if (!ht) return;
    
    for (i = 0; i < ht->size; i++) {
        node = ht->array[i];
        while (node) {
            next = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = next;
        }
    }
    
    free(ht->array);
    free(ht);
}
