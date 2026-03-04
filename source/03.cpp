#include "count_comparison.h"
#include "command.h"
#include "sort_runtime.h"

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    GenerateRandomData(arr, n);
    long count_comparison=0; radixSort_count_cmp(arr, n,count_comparison);
    auto time_run = count_runtime(radixSort, arr, n);
    cout << count_comparison << endl;
    cout << time_run << endl;
    delete[] arr;
    return 0;
}
