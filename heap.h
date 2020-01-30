#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <climits>
#include <iostream>
using namespace std;

struct node{
	int key;
	string data;
};

class heap
{
	public:
	node* array;
	unsigned size;
	unsigned max_size;
	
	heap(int max);
	void insert(int k, string d);
	node remove();
};

heap::heap(int max)
{
	max_size = max;
	array = new node[max];
	size = 0;
}

//INSERTS NODE INTO HEAP
void heap::insert(int k, string d)
{
	if(size >= max_size){
		cout << "We don't have enough space to insert a new value.\n\n";
		return;
	}
	
	array[size].key = k;
	array[size].data = d;
	
	size++;
	
	//REHEAP UP
	int current_loc = size-1;
	int parent = (current_loc-1)/2;
	while(current_loc != 0 && array[current_loc].key < array[parent].key)
	{
		node temp = array[current_loc];
		array[current_loc] = array[parent];
		array[parent] = temp;
		
		current_loc = parent;
		parent = (current_loc-1)/2;
	}
}

//REMOVES NODE FROM HEAP
node heap::remove()
{
	node root = array[0];
	array[0] = array[size-1];
	size--;
	
	int rightValue;
	int largestChild;
	int current_loc = 0;
	int leftIndex = 2 * current_loc + 1;
	while(leftIndex < size)
	{
		int leftValue = array[leftIndex].key;
		int rightIndex = 2 * current_loc + 2;
		if(rightIndex < size)
			rightValue = array[rightIndex].key;
		else
			rightValue = INT_MIN;
		
		largestChild = (leftValue < rightValue) ? leftIndex : rightIndex;
		
		if(array[largestChild].key < array[current_loc].key){
			swap(array[largestChild], array[current_loc]);
			current_loc = largestChild;
			leftIndex = 2*current_loc+1;
		}else
			break;
	}
	return root;
}

#endif