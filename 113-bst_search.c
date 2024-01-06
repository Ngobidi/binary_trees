#include "binary_trees.h"

/**
 * bst_search - find for a value in a Binary Search Tree
 * @tree: root_node of the BST to find
 * @value: the value to find in the tree
 * Return: node containing an int equal to `value` on sucessfull, else
 *         NULL if no match is found or tree is null
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (node)
	{
		if (value == node->n)
			return (node);
		if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
	}

	return (NULL);
}
