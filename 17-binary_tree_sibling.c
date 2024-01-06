#include "binary_trees.h"

/**
 * binary_tree_sibling - discover the siblings of a node
 * @node: node_siblings to locates
 *
 * Return: sibling_node on sucess, else Null if
 *         node is NULL
 *         the parent is NULL
 *         the node has no siblings
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
