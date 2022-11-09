#include "quickselect.h"
#include "reservoir_sampling.h"
#include "binary_search.h"

#include <vector>
#include <iostream>

int main(int argc, const char** args) {
    std::vector<int> arr{1, 3, 8, 2, 1, 9, 0, 6, 5, 0, 2, 4, 7};
    for (size_t i{1}; i < arr.size() + 1; ++i) {
        std::cout << QuickSelect(arr, i) << ' ';
    }
    std::cout << std::endl;


    for (size_t i{1}; i < arr.size() + 1; ++i) {
        for (auto&& n: ReservoirSampling(arr, i)) {
            std::cout << n << ' ';
        }
        std::cout << std::endl;
    }

    for (auto&& n: arr) {
        std::cout << arr[BinarySearch(arr, n)] << ' ';
    }
    std::cout << std::endl;

    std::cout << BinarySearch(arr, 13) << std::endl;

    return 0;
}
