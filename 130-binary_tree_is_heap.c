#include "binary_trees.h"

/**
 * binary_tree_is_heap - validates if a binary tree is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 on sucess, else 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btih_helper(tree));
}

/**
 * btih_helper - validates if a binary tree is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 on sucess or when tree is null, else 0
 */
int btih_helper(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (btih_helper(tree->left) &&
		btih_helper(tree->right));
}

/**
 * binary_tree_is_complete - validate if a binary tree is complete
 * @tree: root_node of the tree to validates
 *
 * Return: 1 on sucess, else 0 when tree is incomplete or null
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
 * @tree: root_node of the tree to check
 * @index: node index to check
 * @size: num of nodes in the tree
 *
 * Return: 1 on sucess, else 0 when tree is incomplete or null
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
 * @tree: tree to evaluates the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
