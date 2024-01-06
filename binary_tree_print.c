#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"


/**
 * print_t - saves recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, j;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (j = 0; j < width; j++)
		s[depth][offset + left + j] = b[j];
	if (depth && is_left)
	{
		for (j = 0; j < width + right; j++)
			s[depth - 1][offset + left + width / 2 + j] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (j = 0; j < left + width; j++)
			s[depth - 1][offset - width / 2 + j] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - computes the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - displays a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, j, k;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (j = 0; j < height + 1; j++)
	{
		s[j] = malloc(sizeof(**s) * 255);
		if (!s[j])
			return;
		memset(s[j], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (j = 0; j < height + 1; j++)
	{
		for (k = 254; k > 1; --k)
		{
			if (s[j][k] != ' ')
				break;
			s[j][k] = '\0';
		}
		printf("%s\n", s[j]);
		free(s[j]);
	}
	free(s);
}
