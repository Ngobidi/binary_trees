#include "binary_trees.h"

/**
 * binary_tree_is_root - validates if a node is a root
 * @node: node to validates
 *
 * Return: 1 if node is a root
 *         0 if not a root or node is Null.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return ((!node || node->parent) ? 0 : 1);
}
