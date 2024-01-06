#include "binary_trees.h"

/**
 * binary_tree_is_perfect - validates if a binary tree is perfect
 * @tree: tree to validates starting from root node
 *
 * Return: 1 on sucess, else 0 if tree is Null or not perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h = 0;
	size_t nodes = 0;
	size_t p = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	h = binary_tree_height(tree);
	nodes = binary_tree_size(tree);

	p = (size_t)_pow_recursion(2, h + 1);
	return (p - 1 == nodes);
}

/**
 *_pow_recursion - returns the value of x raised to the power of y
 *@x: the value to exponentiate
 *@y: the power to raise x to
 *Return: x to the power of y, or -1 if y is negative
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * _pow_recursion(x, y - 1));

}

/**
 * binary_tree_size - evaluates the binary tree size
 * @tree: tree size to be evaluated
 *
 * Return: size on sucessfull, else 0 if tree is null
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - evaluates a binary tree height
 * @tree: tree height to be evaluated
 *
 * Return: height on sucess, else 0 if tree is null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h1 = 0;
	size_t h2 = 0;

	if (!tree)
		return (0);

	h1 = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	h2 = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (h1 > h2 ? h1 : h2);
}
