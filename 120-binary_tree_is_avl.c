#include "binary_trees.h"

/**
 * binary_tree_is_avl - obtains if a binary tree is an avl
 * @tree: root_node of the tree
 *
 * Return: 1 on sucessful, else 0 if avl is not available
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (btia_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btia_helper - helper that obtain if a binary tree is an avl
 * @tree: pointer to the root node of the tree
 * @min: minimum value
 * @max: maximum value
 *
 * Return: 1 sucessfull, else 0 if avl is not available
 */
int btia_helper(const binary_tree_t *tree, int min, int max)
{
	int path_l, path_r;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	path_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	path_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(path_l - path_r) > 1)
		return (0);

	return (btia_helper(tree->left, min, tree->n - 1) &&
		btia_helper(tree->right, tree->n + 1, max));
	/* This is part of the BST check logic */
}

/**
 * binary_tree_height - computes the height of a binary tree
 * @tree: tree height to evaluates.
 *
 * Return: height, else 0 when tree is null.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h1 = 0;
	size_t h2 = 0;

	if (!tree)
		return (0);

	h1 = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	h2 = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (h1 > h2 ? h1 : h2);
}
