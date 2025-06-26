#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

void test_sorting(int size) {
    int *arr1 = malloc(size * sizeof(int));
    int *arr2 = malloc(size * sizeof(int));
    
    for(int i = 0; i < size; i++) {
        arr1[i] = rand() % 10000;
        arr2[i] = arr1[i];
    }
    
    double start, end;
    
    // Quicksort Manual
    start = get_time();
    quickSort(arr1, 0, size - 1);
    end = get_time();
    printf("Quicksort Manual  (n=%d): %f segundos\n", size, end - start);
    
    // stdlib qsort
    start = get_time();
    qsort(arr2, size, sizeof(int), compare);
    end = get_time();
    printf("Stdlib Qsort (n=%d): %f segundos\n\n", size, end - start);
    
    free(arr1);
    free(arr2);
}

int main() {
    srand(time(NULL));
    
    int sizes[] = {10, 100, 1000, 10000, 100000, 1000000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("Comparando algoritmos de ordenación...\n\n");
    
    for(int i = 0; i < num_sizes; i++) {
        test_sorting(sizes[i]);
    }
    
    return 0;
}