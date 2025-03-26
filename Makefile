# Makefile for benchmark programs

# Compiler and flags
CC = gcc
# Using -O0 to disable optimization for benchmarking purposes
CFLAGS = -O0 -Wall -std=c99

# Targets
int_benchmark: int_benchmark.c
	$(CC) $(CFLAGS) -o int_benchmark int_benchmark.c
