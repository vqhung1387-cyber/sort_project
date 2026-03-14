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
To run this project, you need a C++ compiler (such as GCC). Please open your terminal or command prompt, navigate to the folder containing our source code, and run this command to compile:

g++ -o main main.cpp command.cpp DataGenerator.cpp sort_runtime.cpp sorting.cpp count_comparison.cpp

## 5. How to Run
After compiling successfully, the compiler will create an executable file named `main` (or `main.exe` on Windows). You can run the program using the command line format below:

* For Windows:
main.exe [mode] [algorithm] [input_size] [input_order] [output_parameters]

* For macOS / Linux:
./main [mode] [algorithm] [input_size] [input_order] [output_parameters]

Example command:
main.exe -a Radix-Sort 10000 -rand -time

Thank you for reviewing our project!
