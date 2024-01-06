#include "binary_trees.h"

/**
 * binary_trees_ancestor - locates the lowest common ancestor of two nodes
 * @first: first_node to locate the ancestor
 * @second: second_node to locates the ancestor
 *
 * Return: ancestor on sucessful, else Null when theres no ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t d1, d2;

	if (!first || !second)
		return (NULL);

	d1 = binary_tree_depth(first);
	d2 = binary_tree_depth(second);

	while (d1 > d2)
	{
		first = first->parent;
		d1--;
	}
	while (d2 > d1)
	{
		second = second->parent;
		d2--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - evaluates the depth of a node in a binary tree
 * @tree: node to be evaluated
 *
 * Return: depth on sucessful, else 0 if tree is null
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
