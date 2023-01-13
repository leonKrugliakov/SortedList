//****************************************************************************************************
//
//      File:                Stock.h
//
//      Student:             Leon Krugliakov
//
//      Assignment:          Program #
//
//      Course Name:         Data Structures II
//
//      Course Number:       COSC 3100 - 11
//
//      Due:                 December 1st, 2020
//
//
//      This program creates two arrays. One full of integers and the other
//		full of stock objects. Then it randomizes the order of the elements
//		in the array and presents them. Then it proceeds to do four different
//		sorting algorithems on both arrays and displaying them each time.
//		Those algorithems are QuickSort and HeapSort both in forward and
//		reverse orders.
//
//      Other files required:
//		    1.    SortedList.cpp - contains the main function
//			3.	  SortedList.h - Contains the SortedList class
//
//****************************************************************************************************

#ifndef SORTEDLIST_H
#define SORTEDLIST_H

//****************************************************************************************************

#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

//****************************************************************************************************

template<typename T>
class SortedList
{
public:
	SortedList(int size);
	~SortedList();
	void insert(const T& item);
	void randomise();
	void quickSortA();
	void quickSortD();
	void heapSortA();
	void heapSortD();
	void display();
private:
	int size;
	T* list;
	int capacity;
	int partitionA(T arr[], int low, int high);
	int partitionD(T arr[], int low, int high);
	void quickSortA(T arr[], int low, int high);
	void quickSortD(T arr[], int high, int low);
	void heapifyA(T arr[], int n, int root);
	void heapifyD(T arr[], int n, int root);
	void heapSortA(T arr[], int n);
	void heapSortD(T arr[], int n);
};

//****************************************************************************************************

template<typename T>
SortedList<T>::SortedList(int size)
{
	this->size = size;
	list = new T[size];
	capacity = -1;
}

//****************************************************************************************************

template<typename T>
SortedList<T>::~SortedList()
{
	delete[] list;
	size = 0;
	capacity = -1;
}

//****************************************************************************************************

template<typename T>
void SortedList<T>::insert(const T& item)
{
	capacity++;
	list[capacity] = item;
}

//****************************************************************************************************

template<typename T>
void SortedList<T>::randomise()
{
	using namespace std;

	int index;
	T temp;

	srand(time(0));
	
	for (int i = 0; i < size; i++)
	{
		index = rand() % size;
		temp = list[i];
		list[i] = list[index];
		list[index] = temp;
	}
}

//****************************************************************************************************

template<typename T>
int SortedList<T>::partitionA(T arr[], int low, int high)
{
	using namespace std;

	T pivot = arr[(low + high) / 2];

	swap(arr[low], arr[(low + high) / 2]);

	int smallIndex = low;
	int index;

	for (int i = low + 1; i <= high; ++i)
	{
		index = i;
		
		if (pivot > arr[index])
		{
			++smallIndex;
			swap(arr[smallIndex], arr[index]);
		}
	}

	swap(arr[low], arr[smallIndex]);

	return smallIndex;
}

//****************************************************************************************************

template<typename T>
void SortedList<T>::quickSortA()
{
	quickSortA(list, 0, size - 1);
}

//****************************************************************************************************

template<typename T>
void SortedList<T>::quickSortA(T arr[], int low, int high)
{
	if (low < high)
	{
		int pivot = partitionA(arr, low, high);
		quickSortA(arr, low, pivot - 1);
		quickSortA(arr, pivot + 1, high);
	}
}

//****************************************************************************************************

template<typename T>
int SortedList<T>::partitionD(T arr[], int low, int high)
{
	using namespace std;

	T pivot = arr[(low + high) / 2];

	swap(arr[low], arr[(low + high) / 2]);

	int smallIndex = low;
	int index;

	for (int i = low + 1; i <= high; ++i)
	{
		index = i;

		if (pivot < arr[index])
		{
			++smallIndex;
			swap(arr[smallIndex], arr[index]);
		}
	}

	swap(arr[low], arr[smallIndex]);

	return smallIndex;
}

//****************************************************************************************************

template<typename T>
void SortedList<T>::quickSortD()
{
	quickSortD(list, 0, size - 1);
}

//****************************************************************************************************

template<typename T>
void SortedList<T>::quickSortD(T arr[], int low, int high)
{
	if (low < high)
	{
		int pivot = partitionD(arr, low, high);
		quickSortD(arr, low, pivot - 1);
		quickSortD(arr, pivot + 1, high);
	}
}

//****************************************************************************************************

template <typename T>
void SortedList<T>::heapifyA(T arr[], int n, int root)
{
	using namespace std;

	int largest = root;
	int l = 2 * root + 1;
	int r = 2 * root + 2;

	if ((l < n) && (arr[l] > arr[largest]))
	{
		largest = l;
	}

	if ((r < n) && (arr[r] > arr[largest]))
	{
		largest = r;
	}

	if (largest != root)
	{
		swap(arr[root], arr[largest]);
		heapifyA(arr, n, largest);
	}
}

//****************************************************************************************************

template <typename T>
void SortedList<T>::heapSortA()
{
	heapSortA(list, size);
}

//****************************************************************************************************

template <typename T>
void SortedList<T>::heapSortA(T arr[], int n)
{
	using namespace std;

	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapifyA(arr, n, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapifyA(arr, i, 0);
	}
}

//****************************************************************************************************

template <typename T>
void SortedList<T>::heapifyD(T arr[], int n, int root)
{
	using namespace std;

	int smallest = root;
	int l = 2 * root + 1;
	int r = 2 * root + 2;

	if ((l < n) && (arr[l] < arr[smallest]))
	{
		smallest = l;
	}

	if ((r < n) && (arr[r] < arr[smallest]))
	{
		smallest = r;
	}

	if (smallest != root)
	{
		swap(arr[root], arr[smallest]);
		heapifyD(arr, n, smallest);
	}
}

//****************************************************************************************************

template <typename T>
void SortedList<T>::heapSortD()
{
	heapSortD(list, size);
}

//****************************************************************************************************

template <typename T>
void SortedList<T>::heapSortD(T arr[], int n)
{
	using namespace std;

	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapifyD(arr, n, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapifyD(arr, i, 0);
	}
}

//****************************************************************************************************

template <typename T>
void SortedList<T>::display()
{
	using namespace std;

	for (int i = 0; i < size; i++)
	{
		cout << list[i] << endl;
	}
}

//****************************************************************************************************

#endif SORTEDLIST_H
