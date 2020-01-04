#include <iostream>
#include <vector>
#include <algorithm>

#include "Sort.h"


Sort::Sort(int size)
{
	this->sizeOf = size;
	linkedValue = 0;
}

Sort::Sort()
{
	this->sizeOf = 1000;
	linkedValue = 0;
}

Sort::~Sort()
{
	delete linkedListHead;
}

void Sort::InsertionSort()
{
	for (int i = 1; i < sizeOf; i++)
	{
		int j = i;
		while (j > 0 && anArray[j] < anArray[j - 1])
		{
			swap(anArray[j], anArray[j - 1]);
			j--;
		}
	}
}

void Sort::InsertionSortList()
{
	Node* current = linkedListHead;
	
	for (int i = 0; i < sizeOf; i++)
	{
		if (current->next != nullptr)
		{
			ListSwap(current, linkedListHead, i);
			current = current->next;
		}
	}
}

void Sort::ListSwap(Node* current, Node* linkedListHead, int end)
{
	for (int i = 0; i < end; i++)
	{
		if (current->data <= linkedListHead->data)
		{
			int temp = current->data;
			current->data = linkedListHead->data;
			linkedListHead->data = temp;
		}
		linkedListHead = linkedListHead->next;
	}
}


void Sort::SelectionSort()
{
	for (int i = 0; i < sizeOf; i++)
	{
		for (int j = i; j < sizeOf; j++)
		{
			if (anArray[i] > anArray[j])
			{
				swap(anArray[i], anArray[j]);
			}
		}
	}
}

void Sort::MergeSort()
{
	int mid = sizeOf / 2;
	MergeSort();
}

void Sort::Merge(int high, int low)
{

}

void Sort::QuickSort()
{
	int pivot = anArray[0];
	if (sizeOf == low || low > sizeOf)
	{
		return;
	}

	int mid = Partition(pivot, sizeOf, low);
	
	Partition(pivot, mid, low);
	Partition(pivot, sizeOf, mid);
	QuickSort();
}





int Sort::Partition(int pivot, int& highIndex, int& lowIndex)
{
	while (done == false)
	{
		while (anArray[lowIndex] < pivot)
		{
			lowIndex++;
		}

		while (pivot < anArray[highIndex])
		{
			highIndex--;
		}

		if (lowIndex >= highIndex)
		{
			swap(anArray[lowIndex], pivot);
			done = true;
		}
		else
		{
			swap(anArray[lowIndex], anArray[highIndex]);
			lowIndex++;
			highIndex--;
		}
	}
	return highIndex;
}

void Sort::VectorSort()
{
	std::sort(aVector.begin(), aVector.end());
}

void Sort::InitArray()
{
	anArray = new int[sizeOf];
	for (int i = 0; i < sizeOf; i++)
	{
		anArray[i] = rand() % sizeOf;
	}
}

void Sort::InitList()
{
	Node* temp;
	linkedListHead = new Node(rand() % sizeOf);
	temp = linkedListHead;
	for (int i = 1; i < sizeOf - 1; i++)
	{
		temp->next = new Node(rand() % sizeOf);
		temp = temp->next;
	}
}

void Sort::InitVector()
{
	for (int i = 0; i < sizeOf; i++)
	{
		aVector.push_back(rand() % sizeOf);
	}
}

void Sort::SetRandomSeed(unsigned int seed)
{
	srand(seed);
}

ostream & operator<<(ostream & out, const Sort & s)
{
	for (int i = 0; i < s.sizeOf; i++)
	{
		out << s.anArray[i] << ", ";
	}
	return out;
}

void Sort::swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}