#include "binary_trees.h"

/**
 * binary_tree_is_leaf - validates if a node is a leaf
 * @node: node to validates
 *
 * Return: 1 if node is a leaf, 0 if not a leaf or node is Null.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return ((!node || node->left || node->right) ? 0 : 1);
}
