#include "binary_trees.h"

/**
 * binary_tree_is_full - validates if a binary tree is full
 * @tree: tree to be validated starting from the root node
 *
 * Return: 1 on sucessfull, else 0 if tree is either null or not full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	if (tree->right && tree->left)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));

	return (0);
}
