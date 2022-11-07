#include <iostream>
#include <vector>

template<typename T>
void Merge(std::vector<T>& arr, size_t left, size_t right) {
    size_t mid{left + (right - left) / 2};
    std::vector<T> v1(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<T> v2(arr.begin() + mid + 1, arr.begin() + right + 1);
    size_t idx1{0};
    size_t idx2{0};
    size_t idxw{left};
    while (idx1 < v1.size() && idx2 < v2.size()) {
        if (v1[idx1] <= v2[idx2]) {
            arr[idxw] = v1[idx1];
            ++idx1;
        } else {
            arr[idxw] = v2[idx2];
            ++idx2;
        }
        ++idxw;
    }
    while (idx1 < v1.size()) {
        arr[idxw] = v1[idx1];
        ++idx1;
        ++idxw;
    }
    while (idx2 < v2.size()) {
        arr[idxw] = v2[idx2];
        ++idx2;
        ++idxw;
    }
}

template<typename T>
void MergeSort(std::vector<T>& arr, size_t left, size_t right) {
    if (left >= right) return;
    size_t mid{left + (right - left) / 2};
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, right);
}

template<typename T>
void MergeSort(std::vector<T>& arr) {
    if (arr.empty()) return;
    MergeSort(arr, 0UL, arr.size() - 1);
}

int main(int argc, const char** args) {
    std::vector<int> arr{4, 5, 9, 1, 1, 4, 6, 1, 2, 4, 8, 9, 9, 2, 3};
    MergeSort(arr);
    for (auto&& n: arr) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
    return 0;
}
