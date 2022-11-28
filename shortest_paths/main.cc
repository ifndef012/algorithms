#include "floyd_warshall.h"

#include <iostream>
#include <vector>
#include <limits>

int main(int argc, const char** args) {
    constexpr int kInf{std::numeric_limits<int>::max()};
    const std::vector<std::vector<int>> graph_1{
        {0, 3, kInf, 5},
        {2, 0, kInf, 4},
        {kInf, 1, 0, kInf},
        {kInf, kInf, 2, 0}
    };
    const std::vector<std::vector<int>> graph_2{
        {0, 5, kInf, 10},
        {kInf, 0, 3, kInf},
        {kInf, kInf, 0, 1},
        {kInf, kInf, kInf, 0}
    };
    const std::vector<std::vector<int>> graph_3{
        {0, 2, 6, kInf, kInf, kInf, kInf},
        {2, 0, kInf, 3, kInf, kInf, kInf},
        {6, kInf, 0, 8, kInf, kInf, kInf},
        {kInf, 5, 8, 0, 10, 15, kInf},
        {kInf, kInf, kInf, 10, 0, 6, 2},
        {kInf, kInf, kInf, 15, 6, 0, 6},
        {kInf, kInf, kInf, kInf, 2, 6, 0}
    };
    auto&& graph{graph_3};
    for (auto node: FloydWarshall(graph, 0, 6)) {
        std::cout << node << ", ";
    }
    std::cout << std::endl;
    return 0;
}
