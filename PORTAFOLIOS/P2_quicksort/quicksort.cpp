#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

std::vector<int> generate_random_vector(size_t size) {
    std::vector<int> vec(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);
    
    for (size_t i = 0; i < size; i++) {
        vec[i] = dis(gen);
    }
    return vec;
}

template<typename Func>
double measure_time(Func f) {
    auto start = std::chrono::high_resolution_clock::now();
    f();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

int main() {
    std::vector<int> sizes = {10, 100, 1000, 10000, 100000, 1000000};
    
    std::cout << "Len\tQuicksort Manual(ms)\tSTL sort(ms)\n";
    std::cout << "----------------------------------------\n";
    
    for (int size : sizes) {
        auto vec1 = generate_random_vector(size);
        auto vec2 = vec1;
        
        // quicksort manual
        double time1 = measure_time([&]() {
            quicksort(vec1, 0, vec1.size() - 1);
        });
        
        // STL sort
        double time2 = measure_time([&]() {
            std::sort(vec2.begin(), vec2.end());
        });
        
        std::cout << size << "\t" << time1 << "\t\t\t" << time2 << "\n";
    }
    
    return 0;
}