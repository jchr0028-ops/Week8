// stats.h
// Function prototypes and types for statistical operations on integer arrays.

// Summary of results from a full analysis of an array.
typedef struct {
    float mean;
    int   max;
    int   duplicates;
} ArrayStats;

float      calculate_mean(int *arr, int length);
int        find_max(int *arr, int length);
int        count_duplicates(int *arr, int length);
ArrayStats analyse(int *arr, int length);
