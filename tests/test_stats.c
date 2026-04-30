#include <stdio.h>
#include "../src/stats.h"

// ---------------------------------------------------------------------------
// Minimal test framework
// ---------------------------------------------------------------------------

int tests_run    = 0;
int tests_passed = 0;

void check_float(const char *name, float expected, float actual, float tol) {
    tests_run++;
    float diff = expected - actual;
    if (diff < 0) diff = -diff;
    if (diff <= tol) {
        printf("[PASSED] %s\n", name);
        tests_passed++;
    } else {
        printf("[FAILED] %s  =>  expected %.4f, got %.4f\n", name, expected, actual);
    }
}

void check_int(const char *name, int expected, int actual) {
    tests_run++;
    if (expected == actual) {
        printf("[PASSED] %s\n", name);
        tests_passed++;
    } else {
        printf("[FAILED] %s  =>  expected %d, got %d\n", name, expected, actual);
    }
}

// ---------------------------------------------------------------------------
// Tests — calculate_mean
// ---------------------------------------------------------------------------

void test_calculate_mean(void) {
    printf("\n-- calculate_mean --\n");

    int a[] = {2, 4, 6, 8, 10};
    check_float("mean of {2,4,6,8,10}",  6.0f, calculate_mean(a, 5), 0.01f);

    int b[] = {1, 1, 1, 1};
    check_float("mean of {1,1,1,1}",     1.0f, calculate_mean(b, 4), 0.01f);

    int c[] = {-5, 5};
    check_float("mean of {-5, 5}",       0.0f, calculate_mean(c, 2), 0.01f);

    // TODO: Add a test for a single-element array.
    //       int d[] = {42};
    //       The expected mean is 42.0.
    //       Use check_float() with an appropriate tolerance.
}

// ---------------------------------------------------------------------------
// Tests — find_max
// ---------------------------------------------------------------------------

void test_find_max(void) {
    printf("\n-- find_max --\n");

    int a[] = {3, 1, 4, 1, 5, 9, 2, 6};
    check_int("max of {3,1,4,1,5,9,2,6}", 9, find_max(a, 8));

    int b[] = {-3, -1, -4, -2};
    check_int("max of all negatives",     -1, find_max(b, 4));

    int c[] = {7};
    check_int("max of single element",    7,  find_max(c, 1));
}

// ---------------------------------------------------------------------------
// Tests — count_duplicates
// ---------------------------------------------------------------------------

void test_count_duplicates(void) {
    printf("\n-- count_duplicates --\n");

    int a[] = {1, 2, 3, 4, 5};
    check_int("no duplicates",            0, count_duplicates(a, 5));

    int b[] = {1, 1, 1, 1};
    check_int("all same {1,1,1,1}",       3, count_duplicates(b, 4));

    int c[] = {1, 2, 2, 3, 3, 3};
    check_int("mixed {1,2,2,3,3,3}",      3, count_duplicates(c, 6));

    // TODO: Add a test for a single-element array.
    //       int d[] = {99};
    //       A single element cannot have any duplicates — expected result is 0.
    //       Use check_int() to verify this.
}

// ---------------------------------------------------------------------------
// Entry point
// ---------------------------------------------------------------------------

int main(void) {
    printf("=== ArrayUtils Test Runner ===");
    test_calculate_mean();
    test_find_max();
    test_count_duplicates();
    printf("\n==============================\n");
    printf("%d / %d tests passed.\n", tests_passed, tests_run);
    return (tests_passed == tests_run) ? 0 : 1;
}
