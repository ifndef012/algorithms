#include "quickselect.h"
#include "reservoir_sampling.h"
#include "binary_search.h"
#include "segment_tree.h"

#include <vector>
#include <iostream>

int main(int argc, const char** args) {
    std::vector<int> arr{1, 3, 8, 2, 1, 9, 0, 6, 5, 0, 2, 4, 7};
    for (size_t i{1}; i < arr.size() + 1; ++i) {
        std::cout << QuickSelect(arr, i) << ' ';
    }
    std::cout << std::endl;


    for (size_t i{1}; i < arr.size() + 1; ++i) {
        for (auto&& n: ReservoirSampling(arr, i)) {
            std::cout << n << ' ';
        }
        std::cout << std::endl;
    }

    for (auto&& n: arr) {
        std::cout << arr[BinarySearch(arr, n)] << ' ';
    }
    std::cout << std::endl;

    std::cout << BinarySearch(arr, 13) << std::endl;

    std::cout << "[TEST] Segment Tree: \n";
    SegmentTree st{{1, 7, 6, 8, 2, 3, 4, 5, 0}};
    std::cout << st.Query(2, 6) << std::endl;
    st.Update(5, 100);
    std::cout << st.Query(2, 6) << std::endl;

    return 0;
}
