#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100          // Maximum number of elements
#define Sedgewick_SIZE 10 // For Shell_Sort()
#define CUTOFF 50         // For Quick_Sort()

typedef double item_t;

void Bubble_Sort(item_t arr[], int n);
void Insertion_Sort(item_t arr[], int n);
void Shell_Sort(item_t arr[], int n);
void Selection_Sort(item_t arr[], int n);
void Heap_Sort(item_t arr[], int n);
void Merge_Sort(item_t arr[], int n);
void Quick_Sort(item_t arr[], int n);

#endif
