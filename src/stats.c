#include "stats.h"

// Returns the mean (average) of all elements in the array.
float calculate_mean(int *arr, int length) {
    float sum = 0;
    for (int i = 0; i <= length; i++) {
        sum += arr[i];
    }
    return sum / length;
}

// Returns the largest value in the array.
int find_max(int *arr, int length) {
    int max = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Returns the number of elements that are duplicates of an earlier element.
// e.g. {1, 2, 2, 3, 3, 3} -> 3
int count_duplicates(int *arr, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] == arr[i]) {
                count++;
                break;
            }
        }
    }
    return count;
}

// Runs all three analyses and returns them as a single struct.
ArrayStats analyse(int *arr, int length) {
    ArrayStats result;
    result.mean       = calculate_mean(arr, length);
    result.max        = find_max(arr, length);
    result.duplicates = count_duplicates(arr, length);
    return result;
}
