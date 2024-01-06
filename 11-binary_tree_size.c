#include "binary_trees.h"

/**
 * binary_tree_size - computes the binary tree sizes
 * @tree: tree size to computes
 *
 * Return: size of the tree on sucess, else 0 if Null
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
