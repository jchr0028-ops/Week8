#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stats.h"
#include "stats.h"

#define BENCH_SIZE 200000

int main(void) {
    // --- Basic demo using the analyse() convenience function ---
    int sample[] = {4, 7, 2, 9, 1, 7, 3, 2};
    int n = 8;

    ArrayStats s = analyse(sample, n);
    printf("Sample array: {4, 7, 2, 9, 1, 7, 3, 2}\n");
    printf("  Mean:        %.2f\n", s.mean);
    printf("  Max:         %d\n",   s.max);
    printf("  Duplicates:  %d\n\n", s.duplicates);

    // --- Benchmark: count_duplicates on a large array ---
    printf("Benchmarking count_duplicates on %d elements...\n", BENCH_SIZE);

    int *big = malloc(BENCH_SIZE * sizeof(int));
    for (int i = 0; i < BENCH_SIZE; i++) {
        big[i] = i % 1000;   // values 0-999 repeated, lots of duplicates
    }

    struct timespec t_start, t_end;
    clock_gettime(CLOCK_MONOTONIC, &t_start);

    int dupes = count_duplicates(big, BENCH_SIZE);

    clock_gettime(CLOCK_MONOTONIC, &t_end);

    double elapsed_ms = (t_end.tv_sec  - t_start.tv_sec)  * 1000.0
                      + (t_end.tv_nsec - t_start.tv_nsec) / 1.0e6;

    printf("  Found %d duplicates in %.1f ms\n", dupes, elapsed_ms);

    free(big);
    return 0;
}
