#include "binary_trees.h"

/**
 * is_leaf_node - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise.
 * If node is NULL, return (0)
 */
int is_leaf_node(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tree is NULL, return (0)
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);
	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_perfect_tree - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return (0)
 */
int is_perfect_tree(const binary_tree_t *tree)
{
	const binary_tree_t *left_child, *right_child;

	if (tree == NULL)
		return (0);

	if (is_leaf_node(tree))
		return (1);

	left_child = tree->left;
	right_child = tree->right;

	if (left_child == NULL || right_child == NULL)
		return (0);

	if (tree_height(left_child) != tree_height(right_child))
		return (0);

	return (is_perfect_tree(left_child) && is_perfect_tree(right_child));
}

/**
 * is_complete_tree -  checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0
 */
int is_complete_tree(const binary_tree_t *tree)
{
	const binary_tree_t *left_tree, *right_tree;
	size_t left_tree_height, right_tree_height;

	if (tree == NULL)
		return (0);

	if (is_leaf_node(tree))
		return (1);

	left_tree = tree->left;
	right_tree = tree->right;

	left_tree_height = tree_height(left_tree);
	right_tree_height = tree_height(right_tree);

	if (left_tree_height == right_tree_height)
		return (is_perfect_tree(left_tree) && is_complete_tree(right_tree));

	if (left_tree_height == right_tree_height + 1)
		return (is_complete_tree(left_tree) && is_perfect_tree(right_tree));

	return (0);
}
