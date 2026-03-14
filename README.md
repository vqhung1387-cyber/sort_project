# SORTING ALGORITHMS PROJECT

## 1. Group Information
* Vuong Quoc Hung (25127055)
* Nguyen Quoc Thinh (25127507)
* Nguyen Mai Huong Binh (25127019)
* Tran Nguyen Anh Khoa (25127386)

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

g++ *.cpp -std=c++14 -o 03.exe

## 5. How to Run
After compiling successfully, you can run the program using the command line. There are 5 main command modes:

* Command 1 (Run on a specific file):
  03.exe -a [Algorithm] [Given input] [Output parameter(s)]
* Command 2 (Run on generated data):
  03.exe -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
* Command 3 (Run on all 4 data orders):
  03.exe -a [Algorithm] [Input size] [Output parameter(s)]
* Command 4 (Compare 2 algorithms on a specific file):
  03.exe -c [Algorithm 1] [Algorithm 2] [Given input]
* Command 5 (Compare 2 algorithms on generated data):
  03.exe -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]

Example: 03.exe -a Flash-Sort 500000 -rand -time

Thank you for reviewing our project!
