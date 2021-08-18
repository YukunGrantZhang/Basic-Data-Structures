/*
 * RedBlackTreeSort.c
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
	int colour; // 0 for black, 1 for red
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

TreeNode* LeftRotation (Tree* tree, TreeNode* parent_node, TreeNode* right_child_node)
{
	int root = 0;

	if (parent_node == tree->root)
	{
		root = 1;
	}

	if (root == 0)
	{
		if (parent_node->parent->left == parent_node)
		{
			parent_node->parent->left = right_child_node;
		}

		if (parent_node->parent->right == parent_node)
		{
			parent_node->parent->right = right_child_node;
		}
	}

	right_child_node->parent = parent_node->parent;
	parent_node->parent = right_child_node;

	if (right_child_node->left != NULL)
	{
		parent_node->right = right_child_node->left;
		right_child_node->left->parent = parent_node;
	}
	right_child_node->left = parent_node;


	if (root == 1)
	{
		tree->root = right_child_node;
	}

	return right_child_node;
}

TreeNode* RightRotation (Tree* tree, TreeNode* parent_node, TreeNode* left_child_node)
{
	int root = 0;

	if (parent_node == tree->root)
	{
		root = 1;
	}

	if (root == 0)
	{
		if (parent_node->parent->left == parent_node)
		{
			parent_node->parent->left = left_child_node;
		}

		if (parent_node->parent->right == parent_node)
		{
			parent_node->parent->right = left_child_node;
		}
	}

	left_child_node->parent = parent_node->parent;
	parent_node->parent = left_child_node;

	if (left_child_node->right != NULL)
	{
		parent_node->left = left_child_node->right;
		left_child_node->right->parent = parent_node;
	}
	left_child_node->right = parent_node;


	if (root == 1)
	{
		tree->root = left_child_node;
	}

	return left_child_node;
}

int CASE1(Tree* tree, TreeNode* middle_node, int direction)
{
	middle_node->colour = 0;

	if (direction == 0)
	{
		middle_node->parent->left->colour = 0;
		middle_node->parent->colour = 1;

		if (middle_node->parent == tree->root)
		{
			middle_node->parent->colour = 0;
			return 1;
		}

		if (middle_node->parent->parent->colour == 1)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		middle_node->parent->right->colour = 0;
		middle_node->parent->colour = 1;

		if (middle_node->parent == tree->root)
		{
			middle_node->parent->colour = 0;
			return 1;
		}

		if (middle_node->parent->parent->colour == 1)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

void CASE2(Tree* tree, TreeNode* middle_node, int direction)
{
	if (direction == 0)
	{
		TreeNode* middle = middle_node;
		TreeNode* right = middle_node->right;

		TreeNode* subroot = LeftRotation(tree, middle, right);

		subroot->colour = 0;
		subroot->left->colour = 1;
	}
	else
	{
		TreeNode* middle = middle_node;
		TreeNode* left = middle_node->left;

		TreeNode* subroot = RightRotation(tree, middle, left);

		subroot->colour = 0;
		subroot->right->colour = 1;
	}
}

void CASE3(Tree* tree, TreeNode* middle_node, int direction)
{
	if (direction == 0)
	{
		TreeNode* middle = middle_node;
		TreeNode* right = middle_node->right;

		TreeNode* subroot = LeftRotation(tree, middle, right);

		subroot->colour = 0;
		subroot->left->left->colour = 1;
	}
	else
	{
		TreeNode* middle = middle_node;
		TreeNode* left = middle_node->left;

		TreeNode* subroot = RightRotation(tree, middle, left);

		subroot->colour = 0;
		subroot->right->right->colour = 1;
	}

}

void restoreInvariant(Tree* tree, TreeNode* middle_node)
{
	if (middle_node->parent == NULL)
	{
		return;
	}

	if (middle_node->parent->left != middle_node)
	{
		if (middle_node->parent->left == NULL)
		{
			CASE2(tree, middle_node, 0); //left side
			return;
		}

		if (middle_node->parent->left->colour == 1)
		{

			int out = CASE1(tree, middle_node, 0);

			if (out == 0)
			{
				restoreInvariant(tree, middle_node->parent->parent);
			}
			else
			{
				return;
			}
		}

		if (middle_node->parent->left->colour == 0)
		{
			CASE3(tree, middle_node, 0);
			return;
		}
	}

	if (middle_node->parent->right != middle_node)
	{
		if (middle_node->parent->right == NULL)
		{
			CASE2(tree, middle_node, 1); //right side
			return;
		}

		if (middle_node->parent->right->colour == 1)
		{

			int out = CASE1(tree, middle_node, 1);

			if (out == 0)
			{
				restoreInvariant(tree, middle_node->parent->parent);
			}
			else
			{
				return;
			}

		}

		if (middle_node->parent->right->colour == 0)
		{
			CASE3(tree, middle_node, 1);
			return;
		}
	}
}

void Insert(Tree* tree, int insert_key)
{
	TreeNode *current_node = tree->root;
	TreeNode *previous_node = NULL;

	if (tree->root == NULL)
	{
		tree->root = newTreeNode(insert_key);
		tree->root->colour = 0;
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
					current_node->left->colour = 1;

					if (current_node->colour == 1 && current_node->parent != tree->root)
					{
						restoreInvariant(tree, current_node);
					}

					if (current_node->parent == tree->root)
					{
						current_node->colour = 0;
					}
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
					current_node->right->colour = 1;

					if (current_node->colour == 1 && current_node->parent != tree->root)
					{
						restoreInvariant(tree, current_node);
					}

					if (current_node->parent == tree->root)
					{
						current_node->colour = 0;
					}
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
	int inputs[8] = {4, 2, 1, 3, 6, 5, 7, 8};

	Tree* new_tree = newTree();

	for (int i = 0; i < 8; i++)
	{
		Insert(new_tree, inputs[i]);
	}

	InOrderTraversal(new_tree, 8);

	return 0;
}
