#include "binary_trees.h"

/**
 * is_leaf_node - checks if a node is a leaf node in a binary tree
 *
 * @node: pointer to the binary tree node
 *
 * Return: 1 if the node is a leaf node, 0 otherwise
 */
int is_leaf_node(const binary_tree_t *node)
{
	return (node->left == NULL && node->right == NULL);
}

/**
 * get_tree_size - calculates the number of nodes in a binary tree
 *
 * @tree: pointer to the root node of the binary tree
 *
 * Return: the size of the binary tree, or 0 if the tree is NULL
 */
size_t get_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (get_tree_size(tree->left) + get_tree_size(tree->right) + 1);
}

/**
 * check_tree_completeness - checks if a binary tree is complete
 *
 * @tree: pointer to the root node of the binary tree
 * @node_index: index of the current node
 * @tree_size: number of nodes in the binary tree
 *
 * Return: 1 if the binary tree is complete, 0 otherwise
 */
int check_tree_completeness(const binary_tree_t *tree, int node_index,
	size_t tree_size)
{
	if (tree == NULL)
		return (0);

	if (node_index >= tree_size)
		return (0);

	if (is_leaf_node(tree))
		return (1);

	return (check_tree_completeness(tree->left, 2 *node_index + 1, tree_size) &&
		check_tree_completeness(tree->right, 2 *node_index + 2,
			tree_size));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: pointer to the root node of the binary tree
 *
 * Return: 1 if the binary tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t tree_size;

	if (tree == NULL)
		return (0);

	tree_size = get_tree_size(tree);

	return (check_tree_completeness(tree, 0, tree_size));
}
