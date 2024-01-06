#include "binary_trees.h"

/**
 * binary_tree_is_complete - validates if a binary tree is complete
 * @tree: tree to validates starting from root node
 *
 * Return: 1 on sucessful, else 0 if tree is null and incomplete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	return (btic_helper(tree, 0, size));
}

/**
 * btic_helper - validates if a binary tree is complete
 * @tree: tree to validates starting from root node
 * @index: node index to validates
 * @size: num_of_nodes in the tree
 *
 * Return: 1 tree on sucessfull, else 0 when
 *         0 tree is not complete or is null
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (btic_helper(tree->left, 2 * index + 1, size) &&
		btic_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - evaluates the size of a binary tree
 * @tree: tree size to evaluates
 *
 * Return: size on sucessfull, else 0 when tree is null
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
