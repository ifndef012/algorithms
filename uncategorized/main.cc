#include "quickselect.h"

#include <vector>
#include <iostream>

int main(int argc, const char** args) {
    std::vector<int> arr{1, 3, 8, 2, 1, 9, 0, 6, 5, 0, 2, 4, 7};
    std::cout << QuickSelect(arr, 1) << std::endl;
    std::cout << QuickSelect(arr, 2) << std::endl;
    std::cout << QuickSelect(arr, 3) << std::endl;
    std::cout << QuickSelect(arr, 4) << std::endl;
    std::cout << QuickSelect(arr, 5) << std::endl;
    std::cout << QuickSelect(arr, 13) << std::endl;
    std::cout << QuickSelect(arr, 12) << std::endl;
    return 0;
}
