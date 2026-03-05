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
		cout << "Running time: " << count_runtime(sort_func, arr, n) << endl;
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
	ifstream fin(requirements[3], ios::out);
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

void call_generated_func(char* input_order, int m, int arr[])
{
	if (string(input_order) == "-rand")
		GenerateData(arr, m, 0);
	else if (string(input_order) == "-sorted")
		GenerateData(arr, m, 1);
	else if (string(input_order) == "-rev")
		GenerateData(arr, m, 2);
	else if (string(input_order) == "-nsorted")
		GenerateData(arr, m, 3);
	else {
		cout << "Error: Cannot find the input order!" << endl;
		return;
	}
}

void do_command_2(int n, char* requirements[])
{
	cout << "ALGORITHM MODE" << endl;
	print_sorting_algorithm(requirements[2]);
	cout << "Input size: " << requirements[3] << endl;
	cout << "Input order: " << requirements[4] << endl;
	
	for (int i = 0; i < 5; i++)
		cout << "-----";
	cout << endl;

	int m = stoi(requirements[3]);
	int* arr = new int[m];
	call_generated_func(requirements[4], m, arr);
	
	ofstream fout_input("input.txt", ios::out);
	if (!fout_input.is_open())
	{
		cout << "Error: Cannot open input.txt" << endl;
		return;
	}

	fout_input << m << endl;
	for (int i = 0; i < m; i++)
	{
		fout_input << arr[i] << " ";
	}
	fout_input.close();

	output_param(requirements[5], requirements[2], select_sort_func(requirements[2]), m, arr);
	
	ofstream fout_output("output.txt", ios::in);
	for (int i = 0; i < m; i++)
	{
		fout_output << arr[i] << " ";
	}
	fout_output << endl;
	fout_output.close();

	delete[]arr;
}

void do_command_3(int n, char* requirements[])
{
	cout << "ALGORITHM MODE" << endl;
	print_sorting_algorithm(requirements[2]);
	cout << "Input size: " << requirements[3] << endl;
	cout << endl;
	int m = stoi(requirements[3]);
	int* arr_1 = new int[m];
	int* arr_2 = new int[m];
	int* arr_3 = new int[m];
	int* arr_4 = new int[m];

	char input_order_1[] = "-rand";
	char input_order_2[] = "-nsorted";
	char input_order_3[] = "-sorted";
	char input_order_4[] = "-rev";

	call_generated_func(input_order_1, m, arr_1);
	ofstream fout("input_1.txt", ios::out);
	fout << m << endl;
	for (int i = 0; i < m; i++)
		fout << arr_1[i] << " ";
	fout.close();

	call_generated_func(input_order_2, m, arr_2);
	fout.open("output_2.txt", ios::out);
	fout << m << endl;
	for (int i = 0; i < m; i++)
		fout << arr_2[i] << " ";
	fout.close();
	
	call_generated_func(input_order_3, m, arr_3);
	fout.open("output_3.txt", ios::out);
	fout << m << endl;
	for (int i = 0; i < m; i++)
		fout << arr_3[i] << " ";
	fout.close();
	
	call_generated_func(input_order_4, m, arr_4);
	fout.open("output_4.txt", ios::out);
	fout << m << endl;
	for (int i = 0; i < m; i++)
		fout << arr_4[i] << " ";
	fout.close();

	cout << "Input order: Randomize" << endl;
	for (int i = 0; i < 5; i++)
		cout << "-----";
	cout << endl;
	output_param(requirements[4], requirements[2], select_sort_func(requirements[2]), m, arr_1);

	cout << endl;
	cout << "Input order: Nearly Sorted" << endl;
	for (int i = 0; i < 5; i++)
		cout << "-----";
	cout << endl;
	output_param(requirements[4], requirements[2], select_sort_func(requirements[2]), m, arr_2);
	
	cout << endl;
	cout << "Input order: Sorted" << endl;
	for (int i = 0; i < 5; i++)
		cout << "-----";
	cout << endl;
	output_param(requirements[4], requirements[2], select_sort_func(requirements[2]), m, arr_3);
	
	cout << endl;
	cout << "Input order: Reversed" << endl;
	for (int i = 0; i < 5; i++)
		cout << "-----";
	cout << endl;
	output_param(requirements[4], requirements[2], select_sort_func(requirements[2]), m, arr_4);
}

void do_command_4(int n, char* requirements[])
{

}

void do_command_5(int n, char* requirements[])
{

}

