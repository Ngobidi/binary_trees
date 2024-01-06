#include "binary_trees.h"

/**
 * tree_size - computes the sum of heights of a binary tree
 * @tree: root_node of the tree to computes the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t h1 = 0;
	size_t h2 = 0;

	if (!tree)
		return (0);

	if (tree->left)
		h1 = 1 + tree_size(tree->left);

	if (tree->right)
		h2 = 1 + tree_size(tree->right);

	return (h1 + h2);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a filtered array of int
 * @heap: root_node of the heap to convert
 * @size: an address to store the size of the array
 *
 * Return: the generated array
 *         NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int j, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (j = 0; heap; j++)
		a[j] = heap_extract(&heap);

	return (a);
}
