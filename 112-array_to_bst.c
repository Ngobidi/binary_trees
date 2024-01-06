#include "binary_trees.h"

/**
 * array_to_bst - develop a Binary Search Tree from an array
 * @array: first elem of the array to be changed
 * @size: num of element in the array
 * Return: root_node of the develop BST on sucessful
 *         else NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int j;
	bst_t *root = NULL;

	for (j = 0; j < size; j++)
		bst_insert(&root, array[j]);

	return (root);
}
