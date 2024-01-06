#include "binary_trees.h"

/**
 * binary_tree_uncle - locates the uncle of a node
 * @node: node_uncle to locates
 *
 * Return: uncle_node on sucess, else Null if
 *         node is NULL
 *         the parent is NULL
 *         the node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - discover the sibling of a node
 * @node: sibling_node
 *
 * Return: sibling_node on sucess, else null if
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
