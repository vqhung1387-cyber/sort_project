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
void countingsort_count(int a[], int n, int& count_comparison);
void binaryinsertionsort_count(int a[], int n, int& count_comparison);
void flashsort_count(int a[], int n, int& count_comparison);
