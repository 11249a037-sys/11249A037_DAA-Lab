#include <stdio.h>
#include <stdlib.h>

#define MAX_BINS 100

// Utility function to sort items in decreasing order
void sortDescending(int items[], int n) {
int temp;
int i,j;
 for (i = 0; i < n - 1; i++) {
 
     for ( j = i + 1; j < n; j++) {
        if (items[i] < items[j]) {
            temp = items[i];
            items[i] = items[j];
            items[j] = temp;
            }
        }
    }
}

// First Fit Algorithm
void firstFit(int items[], int n, int capacity) {
    int bin_rem[MAX_BINS];
    int bin_count = 0;
int i;
    for ( i = 0; i < n; i++) {
        int j;
        for (j = 0; j < bin_count; j++) {
            if (bin_rem[j] >= items[i]) {
                bin_rem[j] -= items[i];
                break;
            }
        }

        if (j == bin_count) {
            bin_rem[bin_count] = capacity - items[i];
            bin_count++;
        }
    }

    printf("First Fit uses %d bins\n", bin_count);
}

// Best Fit Algorithm
void bestFit(int items[], int n, int capacity) {
    int bin_rem[MAX_BINS];
    int bin_count = 0;
int i;
    for ( i = 0; i < n; i++) {
        int best_index = -1;
        int min_space = capacity + 1;
int j;
        for ( j = 0; j < bin_count; j++) {
            if (bin_rem[j] >= items[i] &&
                bin_rem[j] - items[i] < min_space) {
                best_index = j;
                min_space = bin_rem[j] - items[i];
            }
        }

        if (best_index != -1) {
            bin_rem[best_index] -= items[i];
        } else {
            bin_rem[bin_count] = capacity - items[i];
            bin_count++;
        }
    }

    printf("Best Fit uses %d bins\n", bin_count);
}


void firstFitDecreasing(int items[], int n, int capacity) {
    int sorted_items[n];
    int i,j;
    for ( i = 0; i < n; i++)
        sorted_items[i] = items[i];

    sortDescending(sorted_items, n);

    int bin_rem[MAX_BINS];
    int bin_count = 0;

    for ( i = 0; i < n; i++) {
         
        for (j = 0; j < bin_count; j++) {
            if (bin_rem[j] >= sorted_items[i]) {
                bin_rem[j] -= sorted_items[i];
                break;
            }
        }

        if (j == bin_count) {
            bin_rem[bin_count] = capacity - sorted_items[i];
            bin_count++;
        }
    }

    printf("First Fit Decreasing uses %d bins\n", bin_count);
}

// Main function
int main() {
    int items[] = {4, 8, 1, 4, 2, 1};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 10;

    firstFit(items, n, capacity);
    bestFit(items, n, capacity);
    firstFitDecreasing(items, n, capacity);

    return 0;
}

