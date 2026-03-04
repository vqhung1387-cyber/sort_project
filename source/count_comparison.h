#include <iostream>
#include <algorithm>

int selectionSort_count_cmp(int arr[], int n);

int shakerSort_count_cmp(int arr[], int n);

int sortFirstMiddleLast_count_cmp(int arr[], int first, int last, int &count_comparison);
int partition_count_cmp(int arr[], int first, int last, int &count_comparison);
void quickSort_count_cmp(int arr[], int first, int last, int &count_comparison);

void insertionSort_count_cmp(int arr[], int n, long& count_comparison);

void heapify_count_cmp(int arr[], int end, int curNode, long& count_comparison);
void heapSort_count_cmp(int arr[], int n, long& count_comparison);

void radixSort_count_cmp(int arr[], int n, long& count_comparison);
