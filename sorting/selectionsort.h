#include <vector>
#include <algorithm>


template<typename T>
void SelectionSort(std::vector<T>& arr) {
    if (arr.empty()) return;
    for (size_t i{0}; i < arr.size() - 1; ++i) {
        auto&& it_min{std::min_element(arr.begin() + i, arr.end())};
        std::swap(arr[i], *it_min);
    }
}
