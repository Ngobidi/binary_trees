#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverst a binary tree using level-orders method
 * @tree: tree to be traversed
 * @func: each_node function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t l, max_l;

	if (!tree || !func)
		return;

	max_l = binary_tree_height(tree) + 1;

	for (l = 1; l <= max_l; l++)
		btlo_helper(tree, func, l);
}

/**
 * btlo_helper - negivates a binary tree using post-order traverse
 * @tree: tree to be traversed
 * @func: each_node functions
 * @level: tree level for the function
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		btlo_helper(tree->left, func, level - 1);
		btlo_helper(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - compute the height of a binary tree
 * @tree: tree height to be computed
 *
 * Return: height on sucess, else 0 if tree is null
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
