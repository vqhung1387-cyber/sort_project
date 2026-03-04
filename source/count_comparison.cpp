#include "count_comparison.h"

using namespace std;

int selectionSort_count_cmp(int arr[], int n)
{
    int count_comparison = 0;
    for (int i = 0; i < n - 1; i++)
    {
        count_comparison++;
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            count_comparison++;
            if (++count_comparison && arr[minIdx] > arr[j])
                minIdx = j;
        }
        swap(arr[minIdx], arr[i]);
    }
    return count_comparison;
}

int shakerSort_count_cmp(int arr[], int n)
{
    int count_comparison = 0;
    int left = 0;
    int right = n - 1;
    int k = 0;
    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            ++count_comparison;
            if (++count_comparison && arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                k = i;
            }
        }
        right = k;
        for (int i = right; i > left; i--)
        {
            ++count_comparison;
            if (++count_comparison && arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
                k = i;
            }
        }
        left = k;
    }
    return count_comparison;
}

int sortFirstMiddleLast_count_cmp(int arr[], int first, int last, int &count_comparison)
{
    int mid = (first + last) / 2;
    if (++count_comparison && arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    if (++count_comparison && arr[mid] > arr[last])
        swap(arr[mid], arr[last]);
    if (++count_comparison && arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    return mid;
}

int partition_count_cmp(int arr[], int first, int last, int &count_comparison)
{
    int pivotIndex = sortFirstMiddleLast_count_cmp(arr, first, last, count_comparison);
    swap(arr[pivotIndex], arr[last - 1]);
    pivotIndex = last - 1;
    int pivot = arr[pivotIndex];

    int indexFromLeft = first + 1;
    int indexFromRight = last - 2;
    bool done = false;

    while (!done)
    {
        while (++count_comparison && arr[indexFromLeft] < pivot)
            indexFromLeft++;
        while (++count_comparison && arr[indexFromRight] > pivot)
            indexFromRight--;
        if (++count_comparison && indexFromLeft > indexFromRight)
            done = true;
        else
        {
            swap(arr[indexFromRight], arr[indexFromLeft]);
            indexFromRight--, indexFromLeft++;
        }
    }

    swap(arr[indexFromLeft], arr[pivotIndex]);
    return indexFromLeft;
}

void quickSort_count_cmp(int arr[], int first, int last, int &count_comparison)
{
    if (last - first == 1)
    {
        if (++count_comparison && arr[first] > arr[last])
        {
            swap(arr[first], arr[last]);
        }
        return;
    }
    if (first < last)
    {
        int pivotIndex = partition_count_cmp(arr, first, last, count_comparison);
        quickSort_count_cmp(arr, first, pivotIndex - 1, count_comparison);
        quickSort_count_cmp(arr, pivotIndex + 1, last, count_comparison);
    }
}

// ------------------------

void insertionSort_count_cmp(int arr[], int n, long& count_comparison) {
    for (int i = 1;i < n;i++, ++count_comparison) {
        int numKeep = arr[i];
        for (int j = i;j >= 1;j--, ++count_comparison) {
            if (arr[j - 1] > numKeep) {
                ++count_comparison;
                arr[j] = arr[j - 1];
                arr[j - 1] = numKeep;
            }
            else break;
        }
    }
}

void heapify_count_cmp(int arr[], int end, int curNode, long& count_comparison) {
    int leftNode = curNode * 2 + 1, rightNode = curNode * 2 + 2;
    int bigNode = curNode;

    if (arr[leftNode] > arr[bigNode]) {
        count_comparison++;
        if (leftNode < end) {
            count_comparison++;
            bigNode = leftNode;
        }
    }
    if (arr[rightNode] > arr[bigNode]) {
        count_comparison++;
        if (rightNode < end) {
            count_comparison++;
            bigNode = rightNode;
        }
    }

    if (bigNode != curNode) {
        swap(arr[curNode], arr[bigNode]);
        heapify_count_cmp(arr, end, bigNode, count_comparison);
    }

    count_comparison++;
}

void heapSort_count_cmp(int arr[], int n, long& count_comparison) {
    for (int i = (n - 1) / 2;i >= 0;i--, ++count_comparison) heapify_count_cmp(arr, n, i, count_comparison);
    for (int i = n - 1;i > 0;i--, ++count_comparison) {
        swap(arr[0], arr[i]);
        heapify_count_cmp(arr, i, 0, count_comparison);
    }
}

void radixSort_count_cmp(int arr[], int n, long& count_comparison) {
    int maxNum = arr[0];
    for (int i = 1;i < n;i++, ++count_comparison) {
        maxNum = max(maxNum, arr[i]);
        ++count_comparison;
    }
    for (int exp = 1;maxNum / exp > 0;exp *= 10, ++count_comparison) {
        int* storage[10]; int cnt[10];
        for (int i = 0;i < 10;i++, ++count_comparison) {
            storage[i] = new int[n];
            cnt[i] = 0;
        }

        for (int i = 0;i < n;i++, ++count_comparison) {
            int idx = (arr[i] / exp) % 10;
            storage[idx][cnt[idx]++] = arr[i];
        }

        int idx = 0;
        for (int i = 0;i < 10;i++, ++count_comparison) {
            for (int j = 0;j < cnt[i];j++, ++count_comparison) {
                arr[idx++] = storage[i][j];
            }
        }
    }
}

