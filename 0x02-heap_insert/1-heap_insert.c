#include "binary_trees.h"

/**
 * max_heap - sorted node in a max heap
 * @node: node pointer to be sorted
 * Return: pointer node in max heap
 */
heap_t *max_heap(heap_t *node)
{
	while (node->parent && node && node->n > node->parent->n)
	{
		node->parent->n -= node->n;
		node->n = node->parent->n + node->n;
		node->parent->n = node->n - node->parent->n;
		node = node->parent;
	}
	return (node);
}

/**
 * binary_tree_size - calculate binary tree's size
 * @root: pointer node binatry tree's root
 * Return: size binary tree or NULL on failure
 */
int binary_tree_size(const heap_t *root)
{
	if (!root)
		return (0);

	return (binary_tree_size(root->left) +
			binary_tree_size(root->right) + 1);
}

/**
 * sort_insert - insert node in a complete Binary Tree
 * @root: root node pointer
 * @value: value for new node
 * @index: index of node in binary tree
 * @size: binary tree size
 * Return: new node address
 */
heap_t *sort_insert(heap_t *root, int value, int index, int size)
{
	heap_t *left, *right;

	if (root == NULL)
		return (NULL);

	if ((size / 2) == index)
		return (root->left ? (root->right = binary_tree_node(root, value)) :
				(root->left = binary_tree_node(root, value)));

	left = sort_insert(root->left, value, index * 2, size);
	right = sort_insert(root->right, value, (index * 2) + 1, size);

	return (left ? left : right);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: is a double pointer to the root node of the Heap
 * @value: is the value to store in the node to be inserted
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;

	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	node = sort_insert(*root, value, 1, binary_tree_size(*root) + 1);
	return (max_heap(node));
}
