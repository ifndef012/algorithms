#include <vector>

template<typename T>
size_t BinarySearch(const std::vector<T>& arr, size_t left, size_t right, const T& val) {
    if (left > right || right == static_cast<size_t>(-1)) return static_cast<size_t>(-1);
    size_t mid{left + (right - left) / 2};
    if (arr[mid] == val) return mid;
    if (arr[mid] < val) return BinarySearch(arr, mid + 1, right, val);
    return BinarySearch(arr, left, mid - 1, val);
}


template<typename T>
size_t BinarySearch(const std::vector<T>& arr, const T& val) {
    return BinarySearch(arr, 0UL, arr.size() - 1, val);
}
