/*
 * BinaryTreeSearch.c
 *
 *  Created on: 27 Jun 2020
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
	TreeNode *trace_node = NULL;

	if (tree->root == NULL)
	{
		tree->root = newTreeNode(insert_key);
		tree->root->size++;
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
					trace_node = current_node->left;
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
					trace_node = current_node->right;
					break;
				}
			}
		}
	}

	while (trace_node->parent != NULL)
	{
		trace_node->size++;
		trace_node = trace_node->parent;
	}

	trace_node->size++;

	return;
}

void Select(TreeNode* node, int order)
{
	int a;

	if (node->left == NULL)
	{
		a = 0;
	}
	else
	{
		a = node->left->size;
	}

	if (a == order - 1)
	{
		printf("%d", node->key);
		return;
	}

	if (a >= order)
	{
		Select(node->left, order);
	}

	if (a < order - 1)
	{
		Select(node->right, order - a - 1);
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

	Select(new_tree->root, 1);

	return 0;
}
