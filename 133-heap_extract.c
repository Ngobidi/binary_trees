#include "binary_trees.h"

/**
 * tree_height - computes the height of a binary tree
 * @tree: root_node height to compute
 *
 * Return: Height on sucess else 0 when tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t h1 = 0;
	size_t h2 = 0;

	if (!tree)
		return (0);

	if (tree->left)
		h1 = 1 + tree_height(tree->left);

	if (tree->right)
		h2 = 1 + tree_height(tree->right);

	if (h1 > h2)
		return (h1);
	return (h2);
}
/**
 * tree_size_h - computes the sum of heights of a binary tree
 * @tree: root_node height tree to computes
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t h1 = 0;
	size_t h2 = 0;

	if (!tree)
		return (0);

	if (tree->left)
		h1 = 1 + tree_size_h(tree->left);

	if (tree->right)
		h2 = 1 + tree_size_h(tree->right);

	return (h1 + h2);
}

/**
 * _preorder - navigates to binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last note in traverse
 * @height: height of tree
 *
 * Return: No Return
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *tmp1, *tmp2;

	if (!root)
		return;

	tmp1 = root;

	while (1)
	{
		if (!tmp1->left)
			break;
		if (!tmp1->right)
			tmp2 = tmp1->left;
		else
		{
			if (tmp1->left->n > tmp1->right->n)
				tmp2 = tmp1->left;
			else
				tmp2 = tmp1->right;
		}
		if (tmp1->n > tmp2->n)
			break;
		value = tmp1->n;
		tmp1->n = tmp2->n;
		tmp2->n = value;
		tmp1 = tmp2;
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: a double pointer to the root node of heap
 *
 * Return: the value stored in the root node
 *         0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}

	_preorder(heap_r, &node, tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (value);
}
