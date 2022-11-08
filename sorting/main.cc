#include "mergesort.h"
#include "quicksort.h"

#include <string>
#include <limits>
#include <vector>

int main(int argc, const char** args) {
    std::vector<int> arr{4, 5, 9, 1, 1, 4, 6, 1, 2, 4, 8, 9, 9, 2, 3, 7, 0, 7};
    for (auto&& n: arr) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    std::string method{(argc > 1) ? args[1] : "q"};
    if (method == "m") {
        MergeSort(arr);
    } else if (method == "q") {
        QuickSort(arr);
    } else {

    }

    for (auto&& n: arr) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
    return 0;
}
