#include <vector>
#include <limits>
#include <iostream>

namespace {
template<typename T>
void BackTrack(std::vector<T>& path, const std::vector<std::vector<size_t>>& via, size_t start, size_t end) {
    if (start == end) {
        path.push_back(start);
        return;
    }
    BackTrack(path, via, start, via[start][end]);
    if (start == via[start][end]) return;
    BackTrack(path, via, via[start][end], end);
}
}

template<typename T>
std::vector<T> FloydWarshall(const std::vector<std::vector<T>>& graph, size_t start, size_t end) {
    constexpr T kInf{std::numeric_limits<T>::max()};
    size_t N{graph.size()};
    std::vector<std::vector<T>> distance{graph};
    std::vector<std::vector<size_t>> via{std::vector<std::vector<size_t>>(N, std::vector<size_t>(N, kInf))};
    for (size_t i{0}; i < N; ++i) {
        for (size_t j{0}; j < N; ++j) {
            if (graph[i][j] < kInf) {
                via[i][j] = i;
            }
        }
    }
    for (size_t k{0}; k < N; ++k) {
        for (size_t i{0}; i < N; ++i) {
            for (size_t j{0}; j < N; ++j) {
                if (distance[i][k] != kInf && distance[k][j] != kInf && distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    via[i][j] = k;
                }
            }
        }
    }
    std::vector<T> shortest_path;
    BackTrack(shortest_path, via, start, end);
    shortest_path.push_back(end);
    return shortest_path;
}
