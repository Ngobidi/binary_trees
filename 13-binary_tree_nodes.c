#include "binary_trees.h"

/**
 * binary_tree_nodes - compiles the nodes with at least 1 child in a binary tree
 * @tree: tree nodes to compiled
 *
 * Return: num of nodes compiled on sucess, else 0 if tree is null
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);

	return (binary_tree_size(tree) - binary_tree_leaves(tree));
}

/**
 * binary_tree_size - evaluates the binary tree size
 * @tree: tree size to be evaluated
 *
 * Return: tree size on sucess, else 0 if tree is null
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_leaves - compiles a binary tree leaves
 * @tree: tree leaves to be complied
 *
 * Return: num of leaves on sucess, else 0 if tree is null
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
