#include <vector>
#include <utility>
#include <cassert>

int Partition(std::vector<int>& arr, int l, int r) {
    int pivot{arr[r]};
    int idx_pivot{l};
    for (int i = l; i < r; ++i) {
        if (arr[i] < pivot) {
            std::swap(arr[i], arr[idx_pivot]);
            ++idx_pivot;
        }
    }
    std::swap(arr[r], arr[idx_pivot]);
    return idx_pivot;
}

int QuickSelect(std::vector<int>& arr, int l, int r, int k) {
    if (l == r) return arr[l]; // found
    int idx_pivot{Partition(arr, l, r)};
    if (idx_pivot + 1 == k) return arr[idx_pivot]; // found
    if (idx_pivot + 1 < k) return QuickSelect(arr, idx_pivot + 1, r, k); // right
    return QuickSelect(arr, l, idx_pivot - 1, k);
}

int QuickSelect(std::vector<int>& arr, int k) {
    return QuickSelect(arr, 0, arr.size() - 1, k);
}















// template<typename T>
// size_t Partition(std::vector<T>& arr, size_t left, size_t right) {
//     const auto& pivot{arr[right]};
//     size_t idx_pivot{left};
//     for (size_t i{left}; i < right; ++i) {
//         if (arr[i] < pivot) {
//             std::swap(arr[idx_pivot], arr[i]);
//             ++idx_pivot;
//         }
//     }
//     std::swap(arr[idx_pivot], arr[right]);
//     return idx_pivot;
// }

// template<typename T>
// T QuickSelect(std::vector<T>& arr, size_t left, size_t right, size_t k) {
//     if (left == right) return arr[left];
//     size_t idx_pivot{Partition(arr, left, right)};
//     if (k == idx_pivot + 1) return arr[idx_pivot];
//     if (k < idx_pivot + 1) return QuickSelect(arr, left, idx_pivot - 1, k);
//     return QuickSelect(arr, idx_pivot + 1, right, k);
// }

// template<typename T>
// T QuickSelect(std::vector<T>& arr, size_t k) {
//     return QuickSelect(arr, 0UL, arr.size() - 1, k);
// }
