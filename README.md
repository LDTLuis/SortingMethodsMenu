# Sorting Methods Menu in C

## Description

This is a simple console application, developed in the C language, that allows the user to compare the performance of three classic sorting algorithms: Bubble Sort, Insertion Sort, and Selection Sort.

The program generates an array of random numbers, and then the user can choose which sorting method to apply, viewing the execution time for each one.

## Technologies Used

* **Language:** C

## Adopted Practices

* **Procedural Programming**
* **Menu-Driven Interface**
* **Dynamic Memory Allocation**
* **Performance Measurement (Execution Time)**

## How to Run

1.  **Prerequisites:**
    * A C compiler installed (e.g., GCC).

2.  **Compilation:**
    * Clone the repository or download the `OrdençãoComMenu.c` file.
    * Open a terminal in the directory where the file is located.
    * Run the following command to compile the program:
        ```bash
        gcc OrdençãoComMenu.c -o sorting_menu
        ```

3.  **Execution:**
    * After compilation, run the program with the command:
        ```bash
        ./sorting_menu
        ```

## How to Use the System

After running the program, an interactive menu will be displayed in the console. The usage flow is as follows:

1.  **Generate the Array:**
    * First, choose **Option 1 (`Gerar Vetor`)** to generate an array with random numbers. You must do this before you can sort it.
2.  **Choose a Sorting Method:**
    * Choose one of the sorting options to apply to the generated array:
        * **Option 2:** Bubble Sort
        * **Option 3:** Insertion Sort
        * **Option 4:** Selection Sort
    * The program will display the original array, the sorted array, and the time the algorithm took to execute.
3.  **Repeat or Exit:**
    * You can test other sorting methods on the same array or generate a new one with **Option 1**.
    * To exit the program, choose **Option 5 (`Sair`)**.
