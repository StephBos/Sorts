#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int n) {
		data = n;
		next = nullptr;
	}
};

class Sort
{
public:
	Sort(int size);
	Sort();
	~Sort();
	friend ostream& operator<< (ostream& out, const Sort& s);

	void InsertionSort();
	void InsertionSortList();
	void SelectionSort();
	void MergeSort();
	void QuickSort();
	int Partition(int pivot, int& highIndex, int& lowIndex);
	void VectorSort();

	void InitArray();
	void InitList();
	void InitVector();

	void SetRandomSeed(unsigned int seed);

private:
	vector<int> aVector;
	int* anArray;
	Node* linkedListHead;
	int linkedValue;
	int sizeOf;
	bool done = false;
	int high = sizeOf;
	int low = 0;

	//int Partition(int pivot, int lowIndex, int highIndex);
	void swap(int& x, int& y);
	void ListSwap(Node* currrent, Node* linkedListHead, int end);
	void Merge(int high, int low);
};