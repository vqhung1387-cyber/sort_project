#include "command.h"
#include "sort_runtime.h"
#include "sorting.h"
#include "count_comparison.h"

sortFunction select_sort_func(char* sort_name) {
	sortFunction chosen_func = selectionSort;
	if (string(sort_name) == "selection-sort")
		chosen_func = selectionSort;
	else if (string(sort_name) == "shaker-sort")
		chosen_func = shakerSort;
	else if (string(sort_name) == "quick-sort")
		chosen_func = quickSort;
	else if (string(sort_name) == "insertion-sort")
		chosen_func = insertionSort;
	else if (string(sort_name) == "heap-sort")
		chosen_func = heapSort;
	else if (string(sort_name) == "radix-sort")
		chosen_func = radixSort;
	else if (string(sort_name) == "bubble-sort");

	else if (string(sort_name) == "shell-sort");

	else if (string(sort_name) == "merge-sort");

	else if (string(sort_name) == "counting-sort");

	else if (string(sort_name) == "binary-insertion-sort");

	else if (string(sort_name) == "flash-sort");

	return chosen_func;
}


void print_sorting_algorithm(char* sort_name) {
	if (string(sort_name) == "selection-sort")
		cout << "ALgorithm: Selection Sort" << endl;
	else if (string(sort_name) == "shaker-sort")
		cout << "ALgorithm: Shaker Sort" << endl;
	else if (string(sort_name) == "quick-sort")
		cout << "ALgorithm: Quick Sort" << endl;
	else if (string(sort_name) == "insertion-sort")
		cout << "ALgorithm: Insertion Sort" << endl;
	else if (string(sort_name) == "heap-sort")
		cout << "ALgorithm: Heap Sort" << endl;
	else if (string(sort_name) == "radix-sort")
		cout << "ALgorithm: Radix Sort" << endl;
	else if (string(sort_name) == "bubble-sort")
		cout << "ALgorithm: Bubble Sort" << endl;
	else if (string(sort_name) == "shell-sort")
		cout << "ALgorithm: Shell Sort" << endl;
	else if (string(sort_name) == "merge-sort")
		cout << "ALgorithm: Merge Sort" << endl;
	else if (string(sort_name) == "counting-sort")
		cout << "ALgorithm: Counting Sort" << endl;
	else if (string(sort_name) == "binary-insertion-sort")
		cout << "ALgorithm: Binary Insertion Sort" << endl;
	else if (string(sort_name) == "flash-sort")
		cout << "ALgorithm: Flash Sort" << endl;
}

long long perform_count_comp(char* sort_name, int arr[], int n)
{
	
	long long count_comp = 0;
	if (string(sort_name) == "selection-sort")
		count_comp = selectionSort_count_cmp(arr, n);
	else if (string(sort_name) == "shaker-sort")
		count_comp = shakerSort_count_cmp(arr, n);
	else if (string(sort_name) == "quick-sort")
		quickSort_count_cmp(arr, 0, n - 1, count_comp);
	else if (string(sort_name) == "insertion-sort")
		insertionSort_count_cmp(arr, n, count_comp);
	else if (string(sort_name) == "heap-sort")
		heapSort_count_cmp(arr, n, count_comp);
	else if (string(sort_name) == "radix-sort")
		radixSort_count_cmp(arr, n, count_comp);
	else if (string(sort_name) == "bubble-sort");

	else if (string(sort_name) == "shell-sort");

	else if (string(sort_name) == "merge-sort");

	else if (string(sort_name) == "counting-sort");

	else if (string(sort_name) == "binary-insertion-sort");

	else if (string(sort_name) == "flash-sort");

	return count_comp;
}

void output_param(char* param, char* sort_name, sortFunction sort_func, int n, int arr[])
{
	if (string(param) == "-time")
	{
		cout << "Running time: " << count_runtime(sort_func, arr, n);
	}
	else if (string(param) == "-comp")
	{
		long long cmp = perform_count_comp(sort_name, arr, n);
		cout << "Comparisons: " << cmp << endl;
		 
	}
	else if (string(param) == "-both")
	{
		int* arr_1 = new int[n];
		for (int i = 0; i < n; i++)
			arr_1[i] = arr[i];
		cout << "Running time: " << count_runtime(sort_func, arr, n) << endl;
		long long cmp = perform_count_comp(sort_name, arr_1, n);
		cout << "Comparisons: " << cmp << endl;
		delete[]arr_1;
	}
}

void do_command_1(int n, char* requirements[])
{
	ifstream fin(requirements[3], ios::in);
	if (!fin.is_open()) {
		cout << "Error: Cannot open file " << requirements[3] << endl;
		return;
	}
	int m;
	fin >> m;
	int* arr = new int[m];
	for (int i = 0; i < m; i++)
	{
		fin >> arr[i];
	}
	fin.close();
	cout << "ALGORITHM MODE" << endl;
	print_sorting_algorithm(requirements[2]);
	cout << "Input file: " << requirements[3] << endl;
	cout << "Input size: " << m << endl;
	for (int i = 0; i < 5; i++)
		cout << "-----";
	cout << endl;
	output_param(requirements[4], requirements[2], select_sort_func(requirements[2]), m, arr);
	ofstream fout("output.txt", ios::out);
	for (int i = 0; i < m; i++)
		fout << arr[i] << " ";
	fout << endl;
	fout.close();
	delete[]arr;
}

void do_command_2(int n, char* requirements[])
{

}

void do_command_3(int n, char* requirements[])
{

}

void do_command_4(int n, char* requirements[])
{

}

void do_command_5(int n, char* requirements[])
{

}

void getCommandLine(int argc, char* argv[])
{
	if (argc == 5)
	{
		if (string(argv[1]) == "-c")
		{
			do_command_4(argc, argv);
		}
		else if (string(argv[1]) == "-a")
		{
			char* temp = argv[3];

			while (*temp != '\0' && *temp != '.')
			{
				temp += 1;
			}
			if (*temp == '.')
			{
				do_command_1(argc, argv);
			}
			else
			{
				do_command_3(argc, argv);
			}
		}
	}
	else if (argc == 6)
	{
		if (string(argv[1]) == "-a")
		{
			do_command_2(argc, argv);
		}
		else if (string(argv[1]) == "-c")
		{
			do_command_5(argc, argv);
		}
	}
}
