import random
import time

def quicksort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quicksort(left) + middle + quicksort(right)

def measure_sorting_times():
    sizes = [10, 100, 1000, 10000, 100000, 1000000]
    results = {}

    for size in sizes:
        vector = [random.randint(0, size) for _ in range(size)]
        
        # quicksort manual
        start = time.time()
        quicksort(vector)
        manual_time = time.time() - start
        
        # sorted()
        start = time.time()
        sorted(vector)
        native_time = time.time() - start
        
        results[size] = (manual_time, native_time)
    
    print("Size\tManual Quicksort\tNative Sort")
    for size, (manual_time, native_time) in results.items():
        print(f"{size}\t{manual_time:.6f}s\t\t{native_time:.6f}s")

measure_sorting_times()