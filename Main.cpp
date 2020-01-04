/********************************************************************************************
**	Project: Sort
**  Programmer: Stephen Bos
**  Course:		cs2420
**	Section:	002
**	Assignment: 5
**	Data:		February 14, 2018
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/

#include <iostream>
#include "Sort.h"
#include "Timer.h"

using namespace std;

int main()
{
	const int DATA_SIZE = 10;	// you will have to adjust this to suit the speed of your machine.
	Sort *sort = new Sort(DATA_SIZE);
	Timer ti;

	sort->SetRandomSeed(12345);

	sort->InitArray();
	cout << "starting InsertionSort" << endl;
	ti.Start();
	sort->InsertionSort();
	ti.End();
	cout << "Insertion sort duration: " << ti.DurationInMilliSeconds() << "ms" << endl;

	sort->InitList();
	cout << "starting InsertionSortList()" << endl;
	ti.Start();
	sort->InsertionSortList();
	ti.End();
	cout << "Insertion sort list duration: " << ti.DurationInMilliSeconds() << "ms" << endl;

	sort->InitArray();
	cout << "starting SelectionSort" << endl;
	ti.Start();
	sort->SelectionSort();
	ti.End();
	cout << "SelectionSort duration: " << ti.DurationInMilliSeconds() << "ms" << endl;

	//sort->InitArray();
	//cout << "starting MergeSort" << endl;
	//ti.Start();
	//sort->MergeSort();
	//ti.End();
	//cout << "MergeSort duration: " << ti.DurationInMilliSeconds() << "ms" << endl;

	sort->InitArray();
	cout << "starting QuickSort" << endl;
	ti.Start();
	sort->QuickSort();
	cout << *sort;
	ti.End();
	cout << "QuickSort duration: " << ti.DurationInMilliSeconds() << "ms" << endl;

	sort->InitVector();
	cout << "starting std::sort() of Vector<int>" << endl;
	ti.Start();
	sort->VectorSort();
	ti.End();
	cout << "std::sort() duration: " << ti.DurationInMilliSeconds() << "ms" << endl;

	delete sort;

	cout << endl <<"Press [Enter] key to exit";
	getchar();

}