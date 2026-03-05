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
		cout << "Algorithm: Selection Sort" << endl;
	else if (string(sort_name) == "shaker-sort")
		cout << "Algorithm: Shaker Sort" << endl;
	else if (string(sort_name) == "quick-sort")
		cout << "Algorithm: Quick Sort" << endl;
	else if (string(sort_name) == "insertion-sort")
		cout << "Algorithm: Insertion Sort" << endl;
	else if (string(sort_name) == "heap-sort")
		cout << "Algorithm: Heap Sort" << endl;
	else if (string(sort_name) == "radix-sort")
		cout << "Algorithm: Radix Sort" << endl;
	else if (string(sort_name) == "bubble-sort")
		cout << "Algorithm: Bubble Sort" << endl;
	else if (string(sort_name) == "shell-sort")
		cout << "Algorithm: Shell Sort" << endl;
	else if (string(sort_name) == "merge-sort")
		cout << "Algorithm: Merge Sort" << endl;
	else if (string(sort_name) == "counting-sort")
		cout << "Algorithm: Counting Sort" << endl;
	else if (string(sort_name) == "binary-insertion-sort")
		cout << "Algorithm: Binary Insertion Sort" << endl;
	else if (string(sort_name) == "flash-sort")
		cout << "Algorithm: Flash Sort" << endl;
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
	int* arr = new int[m];
	
	char input_order_1[] = "-rand";
	char input_order_2[] = "-nsorted";
	char input_order_3[] = "-sorted";
	char input_order_4[] = "-rev";

	call_generated_func(input_order_1, m, arr);
	ofstream fout("input_1.txt", ios::out);
	fout << m << endl;
	for (int i = 0; i < m; i++)
		fout << arr[i] << " ";
	fout.close();

	call_generated_func(input_order_2, m, arr);
	fout.open("output_2.txt", ios::out);
	fout << m << endl;
	for (int i = 0; i < m; i++)
		fout << arr[i] << " ";
	fout.close();
	
	call_generated_func(input_order_3, m, arr);
	fout.open("output_3.txt", ios::out);
	fout << m << endl;
	for (int i = 0; i < m; i++)
		fout << arr[i] << " ";
	fout.close();
	
	call_generated_func(input_order_4, m, arr);
	fout.open("output_4.txt", ios::out);
	fout << m << endl;
	for (int i = 0; i < m; i++)
		fout << arr[i] << " ";
	fout.close();

	cout << "Input order: Randomize" << endl;
	for (int i = 0; i < 5; i++)
		cout << "-----";
	cout << endl;
	output_param(requirements[4], requirements[2], select_sort_func(requirements[2]), m, arr);

	cout << endl;
	cout << "Input order: Nearly Sorted" << endl;
	for (int i = 0; i < 5; i++)
		cout << "-----";
	cout << endl;
	output_param(requirements[4], requirements[2], select_sort_func(requirements[2]), m, arr);
	
	cout << endl;
	cout << "Input order: Sorted" << endl;
	for (int i = 0; i < 5; i++)
		cout << "-----";
	cout << endl;
	output_param(requirements[4], requirements[2], select_sort_func(requirements[2]), m, arr);
	
	cout << endl;
	cout << "Input order: Reversed" << endl;
	for (int i = 0; i < 5; i++)
		cout << "-----";
	cout << endl;
	output_param(requirements[4], requirements[2], select_sort_func(requirements[2]), m, arr);
	delete[]arr;
}

//---------------------- COMPARE MODE ----------------------------

void print_TWOsorting_algorithm(char* sort_name1,char* sort_name2) {
	if (string(sort_name1) == "selection-sort")
		cout << "Algorithm: Selection Sort";
	else if (string(sort_name1) == "shaker-sort")
		cout << "Algorithm: Shaker Sort";
	else if (string(sort_name1) == "quick-sort")
		cout << "Algorithm: Quick Sort";
	else if (string(sort_name1) == "insertion-sort")
		cout << "Algorithm: Insertion Sort";
	else if (string(sort_name1) == "heap-sort")
		cout << "Algorithm: Heap Sort";
	else if (string(sort_name1) == "radix-sort")
		cout << "Algorithm: Radix Sort";
	else if (string(sort_name1) == "bubble-sort")
		cout << "Algorithm: Bubble Sort";
	else if (string(sort_name1) == "shell-sort")
		cout << "Algorithm: Shell Sort";
	else if (string(sort_name1) == "merge-sort")
		cout << "Algorithm: Merge Sort";
	else if (string(sort_name1) == "counting-sort")
		cout << "Algorithm: Counting Sort";
	else if (string(sort_name1) == "binary-insertion-sort")
		cout << "Algorithm: Binary Insertion Sort";
	else if (string(sort_name1) == "flash-sort")
		cout << "Algorithm: Flash Sort";
	cout<<" | "; 

	if (string(sort_name2) == "selection-sort")
		cout << "Selection Sort";
	else if (string(sort_name2) == "shaker-sort")
		cout << "Shaker Sort";
	else if (string(sort_name2) == "quick-sort")
		cout << "Quick Sort";
	else if (string(sort_name2) == "insertion-sort")
		cout << "Insertion Sort";
	else if (string(sort_name2) == "heap-sort")
		cout << "Heap Sort";
	else if (string(sort_name2) == "radix-sort")
		cout << "Radix Sort";
	else if (string(sort_name2) == "bubble-sort")
		cout << "Bubble Sort";
	else if (string(sort_name2) == "shell-sort")
		cout << "Shell Sort";
	else if (string(sort_name2) == "merge-sort")
		cout << "Merge Sort";
	else if (string(sort_name2) == "counting-sort")
		cout << "Counting Sort";
	else if (string(sort_name2) == "binary-insertion-sort")
		cout << "Binary Insertion Sort";
	else if (string(sort_name2) == "flash-sort")
		cout << "Flash Sort";

	cout<< endl;
}

void output_TWOsort(char* sort_name1, char* sort_name2, sortFunction sort_func1, sortFunction sort_func2, int n, int arr[])
{
	int* temparr = new int[n];
	int* arr_1 = new int[n]; int*arr_2 = new int[n];
	for (int i = 0; i < n; i++){
		arr_1[i] = arr[i];
		arr_2[i] = arr[i];
		temparr[i] = arr[i];
	}
	cout << "Running time: " << count_runtime(sort_func1, arr, n) << " | "<< count_runtime(sort_func2, temparr, n) << endl;
	long long cmp1 = perform_count_comp(sort_name1, arr_1, n),cmp2 = perform_count_comp(sort_name2, arr_2, n);
	cout << "Comparisons: " << cmp1 << " | "<< cmp2 << endl;
	delete[]arr_1; delete[]arr_2; delete[]temparr;

}


void do_command_4(int n, char* requirements[])
{
	ifstream fin(requirements[4], ios::out);
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
	cout << "COMPARE MODE" << endl;
	print_TWOsorting_algorithm(requirements[2],requirements[3]);
	cout << "Input file: " << requirements[4] << endl;
	cout << "Input size: " << m << endl;
	for (int i = 0; i < 5; i++)
		cout << "-----";
	cout << endl;
	output_TWOsort(requirements[2], requirements[3],select_sort_func(requirements[2]),select_sort_func(requirements[3]),m,arr);
	delete[]arr;
}

void do_command_5(int n, char* requirements[])
{
	cout << "COMPARE MODE" << endl;
	print_TWOsorting_algorithm(requirements[2],requirements[3]);
	cout << "Input size: " << requirements[4] << endl;
	cout << "Input order: " << requirements[5] << endl;

	for (int i = 0; i < 5; i++)
		cout << "-----";
	cout << endl;

	int m = stoi(requirements[4]);
	int* arr = new int[m];
	call_generated_func(requirements[5], m, arr);

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

	output_TWOsort(requirements[2], requirements[3], select_sort_func(requirements[2]), select_sort_func(requirements[3]), m, arr);

	delete[]arr;
}

