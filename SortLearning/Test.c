#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"
#include "Stack.h"
#include "Queue.h"

void TestInsertSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestShellSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestSelectSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestHeapSortSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestBubbleSortSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestQuickSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	QuickSort(a, 0, (sizeof(a) / sizeof(a[0])) - 1);
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestQuickSortPlus()
{
	int a[] = { 6, 6, 3, 6, 7, 8, 9, 10, 1, 0, 4, 8, 7, 6 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	QuickSortPlus(a, 0, (sizeof(a) / sizeof(a[0])) - 1);
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestQuickSortNonR()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	QuickSortNonR(a, 0, (sizeof(a) / sizeof(a[0])) - 1);
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
		
void TestMergeSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	MergeSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestMergeSortNonR()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	MergeSortNonR(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestCountSort()
{
	int a[] = { 20, 24, 20, 19, 5, 30, 24, 25, 19, 33, 35,33};
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	CountSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestRadixSort()
{
	int a[] = { 278, 109, 63, 930, 589, 184, 505, 269, 8, 83};
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	RadixSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
int main()
{
	srand((unsigned int)time(NULL));
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSortSort();
	//TestBubbleSortSort();
	//TestQuickSort();
	TestQuickSortPlus();
	//TestQuickSortNonR();
	//TestMergeSort();
	//TestMergeSortNonR();
	//TestCountSort();
	//TestRadixSort();
	return 0;
}