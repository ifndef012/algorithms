#include "mergesort.h"
#include "quicksort.h"
#include "bubblesort.h"
#include "insertionsort.h"
#include "selectionsort.h"

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
        std::cout << "MergeSort:\n";
        MergeSort(arr);
    } else if (method == "q") {
        std::cout << "QuickSort:\n";
        QuickSort(arr);
    } else if (method == "b") {
        std::cout << "BubbleSort:\n";
        BubbleSort(arr);
    } else if (method == "i") {
        std::cout << "InsertionSort:\n";
        InsertionSort(arr);
    } else if (method == "s") {
        std::cout << "SelectionSort:\n";
        SelectionSort(arr);
    }

    for (auto&& n: arr) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
    return 0;
}
