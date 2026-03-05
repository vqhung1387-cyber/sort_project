#include "sorting.h"

using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIdx] > arr[j])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

void shakerSort(int arr[], int n)
{
    int left = 0;
    int right = n - 1;
    int k = 0;
    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                k = i;
            }
        }
        right = k;
        for (int i = right; i > left; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
                k = i;
            }
        }
        left = k;
    }
}

int sortFirstMiddleLast(int arr[], int first, int last)
{
    int mid = (first + last) / 2;
    if (arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    if (arr[mid] > arr[last])
        swap(arr[mid], arr[last]);
    if (arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    return mid;
}

int partition(int arr[], int first, int last)
{
    int pivotIndex = sortFirstMiddleLast(arr, first, last);
    swap(arr[pivotIndex], arr[last - 1]);
    pivotIndex = last - 1;
    int pivot = arr[pivotIndex];

    int indexFromLeft = first + 1;
    int indexFromRight = last - 2;
    bool done = false;

    while (!done)
    {
        while (arr[indexFromLeft] < pivot)
            indexFromLeft++;
        while (arr[indexFromRight] > pivot)
            indexFromRight--;
        if (indexFromLeft > indexFromRight)
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

void quickSort(int arr[], int first, int last)
{
    if (last - first == 1)
    {
        if (arr[first] > arr[last])
        {
            swap(arr[first], arr[last]);
        }
        return;
    }
    if (first < last)
    {
        int pivotIndex = partition(arr, first, last);
        quickSort(arr, first, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, last);
    }
}

void quickSort(int arr[], int n)
{
    quickSort(arr, 0, n - 1);
}

// ------------------------------------------------

void insertionSort(int arr[], int n) {
    for (int i = 1;i < n;i++) {
        int numKeep = arr[i];
        for (int j = i;j >= 1;j--) {
            if (arr[j - 1] > numKeep) {
                arr[j] = arr[j - 1];
                arr[j - 1] = numKeep;
            }
            else break;
        }
    }
}

void heapify(int arr[], int end, int curNode) {
    int leftNode = curNode * 2 + 1, rightNode = curNode * 2 + 2;
    int bigNode = curNode;

    if (arr[leftNode] > arr[bigNode] && leftNode < end) bigNode = leftNode;
    if (arr[rightNode] > arr[bigNode] && rightNode < end) bigNode = rightNode;

    if (bigNode != curNode) {
        swap(arr[curNode], arr[bigNode]);
        heapify(arr, end, bigNode);
    }
}

void heapSort(int arr[], int n) {
    for (int i = (n - 1) / 2;i >= 0;i--) heapify(arr, n, i);
    for (int i = n - 1;i > 0;i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void radixSort(int arr[], int n) {
    int maxNum = arr[0];
    for (int i = 1;i < n;i++) maxNum = max(maxNum, arr[i]);
    for (int exp = 1;maxNum / exp > 0;exp *= 10) {
        int* storage[10]; int cnt[10];
        for (int i = 0;i < 10;i++) {
            storage[i] = new int[n];
            cnt[i] = 0;
        }

        for (int i = 0;i < n;i++) {
            int idx = (arr[i] / exp) % 10;
            storage[idx][cnt[idx]++] = arr[i];
        }

        int idx = 0;
        for (int i = 0;i < 10;i++) {
            for (int j = 0;j < cnt[i];j++) {
                arr[idx++] = storage[i][j];
            }
        }
    }
}
//---------------------------------------------
void countingsort(int a[], int n) {
    int max_val = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }
    int f[max_val];
    for (int i = 0; i < n; i++) {
        f[a[i]]++;
    }
    for (int i = 1; i < max_val; i++) {
        f[i] = f[i - 1] + f[i];
    }
    int b[n + 1];
    for (int i = n - 1; i >= 0; i--) {
        b[f[a[i]] - 1] = a[i];
        f[a[i]]--;
    }
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }

}
void binaryinsertionsort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int fi = 0, las = i - 1;
        while (fi <= las) {
            int mid = (las + fi) / 2;
            if (key < a[mid]) las = mid - 1;
            else fi = mid + 1;
        }
        for (int j = i - 1; j >= fi; j--) {
            a[j + 1] = a[j];
        }
        a[fi] = key;
    }
}
void flashSort(int a[], int n) {
    if (n <= 1) return;

    int minVal = a[0], maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < minVal) minVal = a[i];
        if (a[i] > a[maxIdx]) maxIdx = i;
    }

    if (a[maxIdx] == minVal) return;

    int m = n / 2;
    if (m < 2) m = 2;

    int* L = new int[m];
    for (int i = 0; i < m; i++) L[i] = 0;

    for (int i = 0; i < n; i++) {
        int k = (long long)(m - 1) * (a[i] - minVal) / (a[maxIdx] - minVal);
        L[k]++;
    }

    for (int i = 1; i < m; i++)
        L[i] += L[i - 1];

    swap(a[maxIdx], a[0]);

    int move = 0, j = 0, k = m - 1;
    while (move < n - 1) {
        while (j >= L[k]) {
            j++;
            k = (long long)(m - 1) * (a[j] - minVal) / (a[maxIdx] - minVal);
        }
        int flash = a[j];
        while (j != L[k]) {
            k = (long long)(m - 1) * (flash - minVal) / (a[maxIdx] - minVal);
            int pos = --L[k];
            swap(flash, a[pos]);
            move++;
        }
    }

    delete[] L;

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
