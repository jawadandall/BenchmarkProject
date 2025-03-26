#include <stdio.h>   // Standard input-output library for printf
#include <stdlib.h>  // Standard library for general utilities
#include <time.h>    // Library for measuring execution time

int main() {
    // Declare and initialize integer variables for arithmetic operations
    int a = 1;  // First operand
    int b = 2;  // Second operand
    int c = 0;  // Variable to store the result (ensures compiler doesn't optimize out calculations)

    // Declare a large loop counter for performing multiple operations
    long long i;  

    // Start measuring execution time
    clock_t start = clock();  // Captures the processor clock time at the beginning

    // Perform 10^10 (10 billion) addition operations
    for (i = 0; i < 10000000000LL; i++) {
        c = a + b;  // Simple addition of two integer constants
    }

    // Perform 5×10^9 (5 billion) multiplication operations
    for (i = 0; i < 5000000000LL; i++) {
        c = a * b;  // Multiplication of two integer constants
    }

    // Perform 2×10^9 (2 billion) division operations
    for (i = 0; i < 2000000000LL; i++) {
        c = a / b;  // Integer division (truncates result since operands are integers)
    }

    // Stop measuring execution time
    clock_t end = clock();  // Captures the processor clock time at the end

    // Compute the total elapsed time in seconds
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the total execution time for the benchmark
    printf("32-bit Integer Benchmark completed in %.2f seconds\n", elapsed_time);

    return 0;  // Indicate successful program termination
}

