#include "binary_trees.h"

/**
 * binary_tree_node - develops a new binary tree node
 *
 * @parent: - pointer to the parent_node of the new node to developed
 * @value: - values to insert in the new_developed_node
 * Return: new_developed_node on successful, else Null
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/* declarations of the new_developed_node with its parameter type */
	binary_tree_t *newNode;

	/* assigned memory space for that node */
	newNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (newNode == NULL)
	{
		return (NULL);
	}

	/* allocates values to the property of the node */
	newNode->parent = parent;
	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;

	/* return a pointer to the node */
	return (newNode);
}
