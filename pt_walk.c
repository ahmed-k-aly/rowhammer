/**
 * @file pt_walk.c
 * @author Ahmed Aly (aaly24@amherst.edu)
 * @brief 
 * @version 0.1
 * @date 2024-04-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bits/time.h>


// Number of pages to allocate is 2^20 = 1048576
// Number that doesn't cause segfault =  1046741
// a pointer is 8 bytes, so 1046741 * 8 = 8373928 bytes = 8.38 MB

#define NUM_PAGES 1046741

void walk_page_table() {
    // Allocate virtual pages
    int* virtual_pages[NUM_PAGES];
    for (int i = 0; i < NUM_PAGES; i++) {
        virtual_pages[i] = (int*)malloc(sizeof(int));
    }

    // Walk the page table and access each physical page
    struct timespec start_time, end_time;
    long long elapsed_time;

    FILE* results_file = fopen("/home/ahmed/Documents/rowhammer/results.txt", "w");
    if (results_file == NULL) {
        printf("Failed to open results file\n");
        return;
    }
    for (int i = 0; i < NUM_PAGES; i++) {
        long long total_read_time = 0;
        long long total_write_time = 0;

        for (int j = 0; j < 1000; j++) {
            // Flush the cache
            __builtin___clear_cache(virtual_pages[i], virtual_pages[i] + 1);

            clock_gettime(CLOCK_MONOTONIC, &start_time);
            *virtual_pages[i] = 0; // Read operation
            clock_gettime(CLOCK_MONOTONIC, &end_time);

            elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000000LL + (end_time.tv_nsec - start_time.tv_nsec);
            total_read_time += elapsed_time;

            // Flush the cache
            __builtin___clear_cache(virtual_pages[i], virtual_pages[i] + 1);

            clock_gettime(CLOCK_MONOTONIC, &start_time);
            *virtual_pages[i] = 1; // Write operation
            clock_gettime(CLOCK_MONOTONIC, &end_time);

            elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000000LL + (end_time.tv_nsec - start_time.tv_nsec);
            total_write_time += elapsed_time;
        }

        double average_read_time = (double)total_read_time / 1000.0;
        double average_write_time = (double)total_write_time / 1000.0;

        fprintf(results_file, "R %d %.9f\n", i, average_read_time);
        fprintf(results_file, "W %d %.9f\n", i, average_write_time);
    }

    fclose(results_file);

    // Free virtual pages
    for (int i = 0; i < NUM_PAGES; i++) {
        free(virtual_pages[i]);
    }
}

int main() {
    walk_page_table();
    return 0;
}
