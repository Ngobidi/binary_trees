#include "binary_trees.h"

/**
 * binary_tree_insert_left -  input a node as the left-child of another node
 *
 * @parent: pointer to the node to input the left-child in
 * @value:  value to store in the new_node
 *
 * Description - If parent already has a left-child, the new_node must
 *				take its place, and the old left-child must be set as
 *				the left-child of the new_node.
 *
 * Return: develop node on sucess, else NULL on failures.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->right = NULL;
	new->left = parent->left;
	parent->left = new;
	if (new->left)
		new->left->parent = new;
	return (new);
}
