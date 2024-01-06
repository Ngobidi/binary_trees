#include "binary_trees.h"

/**
 * binary_tree_insert_right - inputs a node as the
 *					right-child of another node
 *
 * @parent: node to input the right-child in
 * @value: value to save in the new_node
 *
 * Return: developed_node on successful, else Null
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = parent->right;
	parent->right = new;
	if (new->right)
		new->right->parent = new;
	return (new);
}
