# SORTING ALGORITHMS PROJECT - DSA LAB PROJECT

## 1. Group Information
* Vuong Quoc Hung - 25127055
* Nguyen Quoc Thinh - 25127507
* Nguyen Mai Huong Binh - 25127019
* Tran Nguyen Anh Khoa - 25127386
### Instructors: Tran Thi Thao Nhi and Tran Hoang Quan.
## 2. Project Overview
Welcome to our Sorting Algorithms project. This program implements 12 different sorting algorithms. It helps measure the running time (in milliseconds) and counts the total number of comparisons for each algorithm. The program runs completely on the command line.

## 3. Project Structure
Our source code is divided into several files:
* `main.cpp`: Contains the main function to take and execute command prompt inputs.
* `command.cpp`: Processes the arguments and outputs the results to the console.
* `DataGenerator.cpp`: Generates 4 data orders (Randomized, Sorted, Reversed, and Nearly Sorted).
* `sorting.cpp`: Contains the implementations of the 12 sorting algorithms.
* `sort_runtime.cpp`: Measures the execution time.
* `count_comparison.cpp`: Returns the number of comparisons made by each algorithm.

## 4. How to Compile
Please open your terminal or command prompt, navigate to the project folder, and run this command to compile all source files into a single executable:
```bash
g++ *.cpp -std=c++14 -o 03.exe
```
## 5. How to Run
After compiling successfully, you can run the program using the command line. There are 5 main command modes:
### Options Breakdown
Before running the commands, here is the list of valid options you can use:
* **-mode**: Use `-a` for Algorithm mode or `-c` for Comparison mode.
* **Algorithm**: The name of the algorithm (e.g., `selection-sort`, `insertion-sort`, `flash-sort`, etc.).
* **Input_file**: The path to your text file. The file format must be:
  * 1st line: an integer n (number of elements).
  * 2nd line: n integers, separated by a single space.
* **Input_size**: The size of the data to generate. It must be an integer (<= 1,000,000).
* **Input_order**: The initial order of the generated data. Use `-sorted`, `-nsorted`, `-rev`, or `-rand`.
* **Output_parameter**: What to display on the screen. Use `-time`, `-comp`, or `-both`.

---

* Command 1 (Run on a specific file):
```bash
  03.exe -a [Algorithm] [Given input] [Output parameter(s)]
```
Example:
```bash
03.exe -a radix-sort input.txt -both
```
* Command 2 (Run on generated data):
```bash
  03.exe -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
```
Example:
```bash
03.exe -a flash-sort 500000 -rand -time
```
* Command 3 (Run on all 4 data orders):
``` bash
  03.exe -a [Algorithm] [Input size] [Output parameter(s)]
```
 Example:
``` bash
03.exe -a quick-sort 100000 -comp
```
* Command 4 (Compare 2 algorithms on a specific file):
```bash
  03.exe -c [Algorithm 1] [Algorithm 2] [Given input]
```
Example:
```bash
03.exe -c merge-sort heap-sort input.txt
```
* Command 5 (Compare 2 algorithms on generated data):
```bash
  03.exe -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
```
Example:
```bash
03.exe -c bubble-sort shaker-sort 30000 -rev
```

Thank you for reviewing our project!
