#include "hash_tables.h"

/**
 * key_index - Get the index at which the key/value pair should
 *             be stored in the array of the hash table
 * @key: The key to get the index of
 * @size: The size of the array of the hash table
 *
 * Return: The index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    if (size == 0)
        return (0);
    
    return (hash_djb2(key) % size);
}
