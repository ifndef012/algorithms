#include <vector>

template<typename T>
void InsertionSort(std::vector<T>& arr) {
    for (size_t i{1}; i < arr.size(); ++i) {
        auto val{arr[i]};
        size_t j{i};
        while (j > 0 && val < arr[j - 1]) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = val;
    }
}
