#include "binary_trees.h"

/**
 * binary_tree_nod - creates a binary tree node
 * @parent: parent of the node to create
 * @value: value to store in new node
 *
 * Return: pointer to the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *created_node = NULL;

	created_node = malloc(sizeof(binary_tree_t));
	if (!created_node)
		return (NULL);
	created_node->n = value;
	created_node->parent = parent;
	created_node->left = NULL;
	created_node->right = NULL;

	return (created_node);
}
