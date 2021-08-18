/*
 * TreeSort.c
 *
 *  Created on: 26 Jun 2020
 *      Author: Grant
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct TreeNode {
	int key;
	int size;
	struct TreeNode *parent;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

typedef struct Tree{
	TreeNode *root;
} Tree;

TreeNode *newTreeNode(int k)
{
	TreeNode *new;
	new = malloc(sizeof(TreeNode));
	assert(new != NULL);
	new->key = k;
	new->size = 0;
	new->left = NULL;
	new->right = NULL;
	new->parent = NULL;
	return new;
}

Tree *newTree()
{
	Tree *T;
	T = malloc(sizeof (Tree));
	assert(T != NULL);
	T->root = NULL;
	return T;
}

void Insert(Tree* tree, int insert_key)
{
	TreeNode *current_node = tree->root;
	TreeNode *previous_node = NULL;

	if (tree->root == NULL)
	{
		tree->root = newTreeNode(insert_key);
		return;
	}
	else
	{
		while (current_node != NULL)
		{
			if (current_node->key >= insert_key)
			{
				if (current_node->left != NULL)
				{
					current_node = current_node->left;
				}
				else
				{
					current_node->left = newTreeNode(insert_key);
					current_node->left->parent = current_node;
					break;
				}
			}
			else
			{
				if (current_node->right != NULL)
				{
					current_node = current_node->right;
				}
				else
				{
					current_node->right = newTreeNode(insert_key);
					current_node->right->parent = current_node;
					break;
				}
			}
		}
	}
	return;
}

void InOrderTraversal(Tree* tree, int n)
{
	TreeNode *current_node = tree->root;

	while (current_node->left != NULL)
	{
		current_node = current_node->left;
	}

	printf("%d ", current_node->key);

	int count = 1;

	while (count < n)
	{
		if (current_node->right != NULL)
		{
			current_node = current_node->right;

			while (current_node->left != NULL)
			{
				current_node = current_node->left;
			}

			printf("%d ", current_node->key);
		}
		else
		{
			int key = current_node->key;

			while (current_node->parent != NULL)
			{
				current_node = current_node->parent;

				if (current_node->key > key)
				{
					break;
				}
			}

			printf("%d ", current_node->key);
		}
		count++;
	}
}

int main()
{
	int inputs[5] = {3, 1, 2, 5, 4};

	Tree* new_tree = newTree();

	for (int i = 0; i < 5; i++)
	{
		Insert(new_tree, inputs[i]);
	}

	InOrderTraversal(new_tree, 5);

	return 0;
}
