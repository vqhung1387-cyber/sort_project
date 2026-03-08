#include "count_comparison.h"

using namespace std;

unsigned long long selectionSort_count_cmp(int arr[], int n)
{
    unsigned long long count_comparison = 0;
    for (int i = 0;  ++count_comparison && i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; ++count_comparison && j < n; j++)
        {
            if (++count_comparison && arr[minIdx] > arr[j])
                minIdx = j;
        }
        swap(arr[minIdx], arr[i]);
    }
    return count_comparison;
}

unsigned long long shakerSort_count_cmp(int arr[], int n)
{
    unsigned long long count_comparison = 0;
    int left = 0;
    int right = n - 1;
    int k = 0;
    while (++count_comparison && left < right)
    {
        for (int i = left; ++count_comparison && i < right; i++)
        {
            if (++count_comparison && arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                k = i;
            }
        }
        right = k;
        for (int i = right; ++count_comparison && i > left; i--)
        {
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

int sortFirstMiddleLast_count_cmp(int arr[], int first, int last, unsigned long long &count_comparison)
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

int partition_count_cmp(int arr[], int first, int last, unsigned long long &count_comparison)
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

void quickSort_count_cmp(int arr[], int first, int last, unsigned long long &count_comparison)
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

void insertionSort_count_cmp(int arr[], int n, unsigned long long &count_comparison)
{
    for (int i = 1; i < n; i++, ++count_comparison)
    {
        int numKeep = arr[i];
        for (int j = i; j >= 1; j--, ++count_comparison)
        {
            if (arr[j - 1] > numKeep)
            {
                ++count_comparison;
                arr[j] = arr[j - 1];
                arr[j - 1] = numKeep;
            }
            else
                break;
        }
    }
}

void heapify_count_cmp(int arr[], int end, int curNode, unsigned long long &count_comparison)
{
    int leftNode = curNode * 2 + 1, rightNode = curNode * 2 + 2;
    int bigNode = curNode;

    if (++count_comparison && leftNode < end)
    {
        if (++count_comparison && arr[leftNode] > arr[bigNode])
        {
            bigNode = leftNode;
        }
    }
    if (++count_comparison && rightNode < end)
    {
        if (++count_comparison && arr[rightNode] > arr[bigNode])
        {
            bigNode = rightNode;
        }
    }

    if (++count_comparison && bigNode != curNode)
    {
        swap(arr[curNode], arr[bigNode]);
        heapify_count_cmp(arr, end, bigNode, count_comparison);
    }

    count_comparison++;
}

void heapSort_count_cmp(int arr[], int n, unsigned long long &count_comparison)
{
    for (int i = (n - 1) / 2; ++count_comparison && i >= 0; i--)
        heapify_count_cmp(arr, n, i, count_comparison);
    for (int i = n - 1; ++count_comparison && i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify_count_cmp(arr, i, 0, count_comparison);
    }
}

void radixSort_count_cmp(int arr[], int n, unsigned long long &count_comparison)
{
    int maxNum = arr[0];
    for (int i = 1; i < n; i++, ++count_comparison)
    {
        maxNum = max(maxNum, arr[i]);
        ++count_comparison;
    }
    for (int exp = 1; maxNum / exp > 0; exp *= 10, ++count_comparison)
    {
        int *storage[10];
        int cnt[10];
        for (int i = 0; i < 10; i++, ++count_comparison)
        {
            storage[i] = new int[n];
            cnt[i] = 0;
        }

        for (int i = 0; i < n; i++, ++count_comparison)
        {
            int idx = (arr[i] / exp) % 10;
            storage[idx][cnt[idx]++] = arr[i];
        }

        int idx = 0;
        for (int i = 0; i < 10; i++, ++count_comparison)
        {
            for (int j = 0; j < cnt[i]; j++, ++count_comparison)
            {
                arr[idx++] = storage[i][j];
            }
        }
        for (int i = 0; i < 10; i++)
            delete[]storage[i];
    }
}
//---------------------------------
void countingSort_count_cmp(int a[], int n, unsigned long long& count_comparison) {
    int max_val = a[0];
    for (int i = 1; i < n; i++) {
        ++count_comparison;
        if (++count_comparison && a[i] > max_val) {
            max_val = a[i];
        }
    }
    int *f = new int[max_val + 1]();
    for (int i = 0; i < n; i++) {
        ++count_comparison;
        f[a[i]]++;
    }
    for (int i = 1; i <= max_val; i++) {
        ++count_comparison;
        f[i] = f[i - 1] + f[i];
    }
    int *b = new int[n + 1];
    for (int i = n - 1; i >= 0; i--) {
        ++count_comparison;
        b[f[a[i]] - 1] = a[i];
        f[a[i]]--;
    }
    for (int i = 0; i < n; i++) {
        ++count_comparison;
        a[i] = b[i];
    }
    delete[]f;
    delete[]b;
}
void binaryInsertionSort_count_cmp(int a[], int n, unsigned long long& count_comparison) {
    for (int i = 1; i < n; i++) {
        ++count_comparison;
        int key = a[i];
        int fi = 0, las = i - 1;
        while (++count_comparison && fi <= las) {
            int mid = (las + fi) / 2;
            if (++count_comparison && key < a[mid]) las = mid - 1;
            else fi = mid + 1;
        }
        for (int j = i - 1; j >= fi; j--) {
            ++count_comparison;
            a[j + 1] = a[j];
        }
        a[fi] = key;
    }
}
void flashSort_count_cmp(int a[], int n, unsigned long long& count_comparison) {
    if (++count_comparison && n <= 1) return;

    int minVal = a[0], maxIdx = 0;

    for (int i = 1; i < n; i++) {
        ++count_comparison;
        if (++count_comparison && a[i] < minVal) minVal = a[i];
        if (++count_comparison && a[i] > a[maxIdx]) maxIdx = i;
    }

    int maxVal = a[maxIdx];
    if (++count_comparison && maxVal == minVal) return;

    int m = n / 2;
    if (++count_comparison && m < 2) m = 2;

    int* L = new int[m];

    for (int i = 0; i < m; i++) {
        ++count_comparison;
        L[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        ++count_comparison;
        int k = (long long)(m - 1) * (a[i] - minVal) / (maxVal - minVal);
        L[k]++;
    }

    for (int i = 1; i < m; i++) {
        ++count_comparison;
        L[i] += L[i - 1];
    }

    swap(a[maxIdx], a[0]);

    int move = 0, j = 0, k = m - 1;

    while (++count_comparison && move < n - 1) {

        while (++count_comparison && j >= L[k]) {
            j++;
            if (++count_comparison && j >= n) break;
            k = (long long)(m - 1) * (a[j] - minVal) / (maxVal - minVal);
        }

        if (++count_comparison && j >= n) break;

        int flash = a[j];

        while (++count_comparison && j != L[k]) {
            k = (long long)(m - 1) * (flash - minVal) / (maxVal - minVal);
            int pos = --L[k];
            swap(flash, a[pos]);
            move++;
        }
    }

    delete[] L;

    for (int i = 1; i < n; i++) {
        ++count_comparison;
        int key = a[i];
        int j = i - 1;

        while (++count_comparison && j >= 0 && (++count_comparison && a[j] > key)) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void bubbleSort_count_cmp(int* a, int n, unsigned long long& count_comparison)
{
    for (int i = 1; ++count_comparison && i < n; ++i)
    {
        for (int j = 0; ++count_comparison && j < n - i; ++j)
            if (++count_comparison && a[j] > a[j + 1]) swap(a[j], a[j + 1]);
    }
}

void shellSort_count_cmp(int* a, int n, unsigned long long& count_comparison)
{
    int interval = n / 2;
    while (interval > 0)
    {
        for (int i = interval; ++count_comparison && i < n; ++i)
        {
            int temp = a[i];
            int j = i;
            while ((++count_comparison && j >= interval) && (++count_comparison && a[j - interval] > temp))
            {
                a[j] = a[j - interval];
                j -= interval;
            }
            a[j] = temp;
        }
        interval /= 2;
    }
}

void mergeSort_count_cmp(int arr[], int l, int r, unsigned long long &count_comparison)
{
    if (++count_comparison && l < r)
    {
        int m = (l + r) / 2;
        mergeSort_count_cmp(arr, l, m, count_comparison);
        mergeSort_count_cmp(arr, m + 1, r, count_comparison);
        merge_count_cmp(arr, l, m, r, count_comparison);
    }
}

void merge_count_cmp(int arr[], int l, int m, int r, unsigned long long &count_comparison)
{
    int* LEFT = new int[m - l + 1];
    int* RIGHT = new int[r - m];
    int a = 0, b = 0;
    for (int i = l; ++count_comparison && i <= m; i++)
    {

        LEFT[a] = arr[i];
        a++;
    }
    for (int i = m + 1; ++count_comparison && i <= r; i++)
    {
        RIGHT[b] = arr[i];
        b++;
    }
    int i = 0, j = 0, k = l;
    while (++count_comparison && i < a && ++count_comparison && j < b)
    {
        if (++count_comparison && LEFT[i] <= RIGHT[j])
        {
            arr[k] = LEFT[i];
            i++, k++;
        }
        else
        {
            arr[k] = RIGHT[j];
            j++, k++;
        }
    }
    while (++count_comparison && i < a)
    {
        arr[k] = LEFT[i];
        i++, k++;
    }
    while (++count_comparison && j < b)
    {
        arr[k] = RIGHT[j];
        k++, j++;
    }
    delete[] LEFT;
    delete[] RIGHT;
}
