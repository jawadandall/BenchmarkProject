#include <stdio.h>   // Standard I/O library for printf
#include <stdlib.h>  // Standard library for general utilities
#include <time.h>    // Library for measuring execution time

// This function prevents the compiler from optimizing away calculations
// The use of "volatile static" ensures the value is stored in memory
void prevent_optimization(int value) {
    volatile static int sink;  // Volatile prevents compiler optimizations
    sink = value;  // Assign value to sink to ensure computations are not discarded
}

int main() {
    // Declare and initialize integer variables for arithmetic operations
    int a = 1;  // First operand
    int b = 2;  // Second operand
    int c = 0;  // Variable to store the result

    // Declare a loop counter for performing large-scale operations
    long long i;

    // Start measuring execution time
    clock_t start = clock();  // Captures the processor clock time at the beginning

    // Perform 10^10 (10 billion) addition operations
    for (i = 0; i < 10000000000LL; i++) {
        c = a + b;  // Simple integer addition
        // Every 1 billion iterations, store the result to prevent compiler optimization
        if (i % 1000000000 == 0) { 
            prevent_optimization(c);
        }
    }

    // Perform 5×10^9 (5 billion) multiplication operations
    for (i = 0; i < 5000000000LL; i++) {
        c = a * b;  // Simple integer multiplication
        // Every 1 billion iterations, store the result to prevent compiler optimization
        if (i % 1000000000 == 0) {
            prevent_optimization(c);
        }
    }

    // Perform 2×10^9 (2 billion) division operations
    for (i = 0; i < 2000000000LL; i++) {
        c = a / b;  // Integer division (truncates result)
        // Every 1 billion iterations, store the result to prevent compiler optimization
        if (i % 1000000000 == 0) {
            prevent_optimization(c);
        }
    }

    // Ensure the final computed value is used to avoid compiler optimizations
    prevent_optimization(c);

    // Stop measuring execution time
    clock_t end = clock();  // Captures the processor clock time at the end

    // Compute the total elapsed time in seconds
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the total execution time for the benchmark
    printf("32-bit Integer Benchmark completed in %.2f seconds\n", elapsed_time);

    return 0;  // Indicate successful program termination
}