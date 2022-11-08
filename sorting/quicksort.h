#include <vector>


template<typename T>
size_t Partition(std::vector<T>& arr, size_t left, size_t right) {
    auto pivot{arr[right]};
    size_t idx_pivot{left};
    for (size_t i{left}; i < right; ++i) {
        if (arr[i] < pivot) {
            std::swap(arr[i], arr[idx_pivot]);
            ++idx_pivot;
        }
    }
    std::swap(arr[idx_pivot], arr[right]);
    return idx_pivot;
}


template<typename T>
void QuickSort(std::vector<T>& arr, size_t left, size_t right) {
    if (left >= right) return;
    size_t idx_pivot{Partition(arr, left, right)};
    QuickSort(arr, idx_pivot + 1, right);
    if (idx_pivot == 0) return;
    QuickSort(arr, left, idx_pivot - 1);
}


template<typename T>
void QuickSort(std::vector<T>& arr) {
    if (arr.empty()) return;
    QuickSort(arr, 0UL, arr.size() - 1);
}
