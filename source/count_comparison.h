#include <iostream>
#include <algorithm>

long long selectionSort_count_cmp(int arr[], int n);

long long shakerSort_count_cmp(int arr[], int n);

int sortFirstMiddleLast_count_cmp(int arr[], int first, int last, long long &count_comparison);
int partition_count_cmp(int arr[], int first, int last, long long &count_comparison);
void quickSort_count_cmp(int arr[], int first, int last, long long &count_comparison);

void insertionSort_count_cmp(int arr[], int n, long long &count_comparison);

void heapify_count_cmp(int arr[], int end, int curNode, long long &count_comparison);
void heapSort_count_cmp(int arr[], int n, long long &count_comparison);

void radixSort_count_cmp(int arr[], int n, long long &count_comparison);

void countingSort_count_cmp(int a[], int n, long long& count_comparison);

void binaryInsertionSort_count_cmp(int a[], int n, long long& count_comparison);

void flashSort_count_cmp(int a[], int n, long long& count_comparison);

void bubbleSort_count_cmp(int*, int, long long&);

void shellSort_count_cmp(int*, int, long long&);

void mergeSort_count_cmp(int arr[], int l, int r, long long& count_comparison);
void merge_count_cmp(int arr[], int l, int m, int r, long long& count_comparison);
