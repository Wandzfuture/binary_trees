#include "binary_trees.h"

/**
 * binary_tree_levelorder - Perform a level-order traversal on a binary tree
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node. The value in the node
 * must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void(*func)(int))
{
	size_t height = binary_tree_height(tree);

	if (tree == NULL || func == NULL)
		return;

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * height);

	if (queue == NULL)
		return;

	int front = 0, rear = 0;
	binary_tree_t *current = (binary_tree_t *) tree;

	while (current != NULL)
	{
		func(current->n);

		if (current->left != NULL)
			queue[rear++] = current->left;

		if (current->right != NULL)
			queue[rear++] = current->right;

		if (front == rear)
			break;

		current = queue[front++];
	}

	free(queue);
}
