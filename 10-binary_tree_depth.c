#include "binary_trees.h"

/**
 * binary_tree_depth - computes the depth of a binary tree nodes
 * @tree: node to computes the depth
 *
 * Return: depth of the node on sucessfull, else 0 if Null
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
