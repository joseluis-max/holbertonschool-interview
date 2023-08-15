#include "binary_trees.h"

/**
 * binary_tree_node - create a binary tree
 * @parent: is a pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->right = NULL;
	node->left = NULL;
	node->parent = NULL;
	node->n = value;

	if (parent == NULL)
		return (node);

	node->parent = parent;
	return (node);
}
