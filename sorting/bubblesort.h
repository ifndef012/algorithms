#include <vector>


template<typename T>
void BubbleSort(std::vector<T>& arr) {
    if (arr.empty()) return;

    for (size_t i{0}; i < arr.size() - 1; ++i) {
        bool swapped{false};
        for (size_t j{0}; j < arr.size() - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
