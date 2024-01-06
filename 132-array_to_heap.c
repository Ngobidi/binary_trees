#include "binary_trees.h"

/**
 * array_to_heap - develop a Max Binary Heap tree from an array
 * @array: first element of the array to be changed
 * @size: the num of element in the array
 *
 * Return: root_node of the build Binary Heap
 *         NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int j;
	heap_t *root = NULL;

	for (j = 0; j < size; j++)
		heap_insert(&root, array[j]);

	return (root);
}
