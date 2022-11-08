#include <vector>
#include <cassert>

template<typename T>
size_t Partition(std::vector<T>& arr, size_t left, size_t right) {
    const auto& pivot{arr[right]};
    size_t idx_pivot{left};
    for (size_t i{left}; i < right; ++i) {
        if (arr[i] < pivot) {
            std::swap(arr[idx_pivot], arr[i]);
            ++idx_pivot;
        }
    }
    std::swap(arr[idx_pivot], arr[right]);
    return idx_pivot;
}

template<typename T>
T QuickSelect(std::vector<T>& arr, size_t left, size_t right, size_t k) {
    if (left == right) return arr[left];
    size_t idx_pivot{Partition(arr, left, right)};
    if (k == idx_pivot + 1) return arr[idx_pivot];
    if (k < idx_pivot + 1) return QuickSelect(arr, left, idx_pivot - 1, k);
    return QuickSelect(arr, idx_pivot + 1, right, k);
}

template<typename T>
T QuickSelect(std::vector<T>& arr, size_t k) {
    return QuickSelect(arr, 0UL, arr.size() - 1, k);
}
