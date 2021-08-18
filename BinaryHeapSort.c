/*
 * BinaryHeapSort.c
 *
 *  Created on: 25 Jun 2020
 *      Author: Grant
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_HEAP_SIZE 50

int heap[MAX_HEAP_SIZE];
int last_heap_element;

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct MinHeapNode
{
    int vertex;
    int weight;
}MinHeapNode;

typedef struct MinHeap
{
    MinHeapNode **nodes;
}MinHeap;

MinHeapNode* newMinHeapNode(int v, int w)
{
    MinHeapNode* minHeapNode = malloc(sizeof(struct MinHeapNode));
    minHeapNode->vertex = v;
    minHeapNode->weight = w;
    return minHeapNode;
}

MinHeap* createMinHeap(int capacity)
{
    MinHeap* minHeap = malloc(sizeof(struct MinHeap));
    minHeap->nodes = malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void BubbleUp(MinHeap* heaps, int current_index)
{
	int parent_index = (int)(floor((current_index + 1) / 2)) - 1;
	MinHeapNode* temp;

	if (parent_index < 0)
	{
		parent_index = 0;
	}

	while (heaps->nodes[current_index]->weight < heaps->nodes[parent_index]->weight)
	{
		temp = heaps->nodes[current_index];
		heaps->nodes[current_index] = heaps->nodes[parent_index];
		heaps->nodes[parent_index] = temp;

		current_index = parent_index;
		parent_index = (int)(floor((current_index + 1) / 2)) - 1;

		if (parent_index < 0)
		{
			break;
		}
	}

}

void BubbleDown(MinHeap* heaps, int starting_index)
{
	int current_index = starting_index;
	int left_child_index = (current_index + 1) * 2 - 1;
	int right_child_index = (current_index + 1) * 2;

	int selection_index;

	if (heaps->nodes[left_child_index] == NULL || heaps->nodes[right_child_index] == NULL)
	{
		if (heaps->nodes[left_child_index] != NULL && heaps->nodes[current_index]->weight > heaps->nodes[left_child_index]->weight)
		{
			MinHeapNode* temp = heaps->nodes[current_index];
			heaps->nodes[current_index] = heaps->nodes[left_child_index];
			heaps->nodes[left_child_index] = temp;
		}

		return;
	}

	while (heaps->nodes[current_index]->weight > heaps->nodes[left_child_index]->weight || heaps->nodes[current_index]->weight > heaps->nodes[right_child_index]->weight)
	{
		if (heaps->nodes[left_child_index]->weight < heaps->nodes[right_child_index]->weight)
		{
			selection_index = left_child_index;
		}
		else
		{
			selection_index = right_child_index;
		}

		MinHeapNode* temp2 = heaps->nodes[current_index];
		heaps->nodes[current_index] = heaps->nodes[selection_index];
		heaps->nodes[selection_index] = temp2;

		current_index = selection_index;
		left_child_index = (current_index + 1) * 2 - 1;
		right_child_index = (current_index + 1) * 2;

		if (heaps->nodes[left_child_index] == NULL || heaps->nodes[right_child_index] == NULL)
		{
			if (heaps->nodes[left_child_index] != NULL && heaps->nodes[current_index]->weight > heaps->nodes[left_child_index]->weight)
			{
				MinHeapNode* temp3 = heaps->nodes[current_index];
				heaps->nodes[current_index] = heaps->nodes[left_child_index];
				heaps->nodes[left_child_index] = temp3;
			}

			break;
		}
	}
}

void InsertHeap(MinHeap* heaps, MinHeapNode* temp_node)
{
	heaps->nodes[last_heap_element] = temp_node;
	int current_element_index = last_heap_element;
	last_heap_element++;

	BubbleUp(heaps, current_element_index);
}

int ExtractMin(MinHeap* heaps)
{
	int last_index = last_heap_element - 1;
	int min = heaps->nodes[0]->weight;

	heaps->nodes[0] = heaps->nodes[last_index];
	heaps->nodes[last_index] = NULL;
	last_heap_element--;

	BubbleDown(heaps, 0);

	return min;
}

void DeleteKey(MinHeap* heaps, int vertex)
{
	int location = 50;

	for (int i = 0; i < last_heap_element; i++)
	{
		if (heaps->nodes[i]->vertex == vertex)
		{
			location = i;
		}
	}

	if (location == 50)
	{
		return;
	}

	int last_index = last_heap_element - 1;

	heaps->nodes[location] = heaps->nodes[last_index];
	heaps->nodes[last_index] = NULL;
	last_heap_element--;

	BubbleDown(heaps, location);
}

void ReduceKey(MinHeap* heaps, int vertex, int new_reduction_weight)
{
	int location = 50;

	for (int i = 0; i < last_heap_element; i++)
	{
		if (heaps->nodes[i]->vertex == vertex)
		{
			location = i;
		}
	}

	if (location == 50)
	{
		return;
	}

	heaps->nodes[location]->weight = new_reduction_weight;

	BubbleUp(heaps, location);
}

int main(void)
{
	int inputs[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

	MinHeap* heaps = createMinHeap(50);

	last_heap_element = 0;

	for (int i = 0; i < 50; i++)
	{
		heaps->nodes[i] = NULL;
	}

	for (int i = 0; i < 9; i++)
	{
		MinHeapNode* new_node = newMinHeapNode(i, inputs[i]);
		InsertHeap(heaps, new_node);
	}

	for (int j = 0; j < 9; j++)
	{
		printf("%d ", heaps->nodes[j]->weight);
	}

	printf("\n");

	//for (int j = 0; j < 9; j++)
	//{
	//	printf("%d ", ExtractMin(heaps));
	//}

	ReduceKey(heaps, 6, 1);

	for (int j = 0; j < 9; j++)
	{
		printf("%d ", heaps->nodes[j]->weight);
	}

	return 0;
}
