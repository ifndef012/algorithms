#include <vector>
#include <random>

template<typename T>
std::vector<T> ReservoirSampling(const std::vector<T>& arr, size_t k) {
    std::vector<T> samples;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<size_t> uniform;

    for (size_t i{0}; i < k; ++i) {
        samples.push_back(arr[i]);
    }

    for (size_t i{k}; i < arr.size(); ++i) {
        uniform.param(std::uniform_int_distribution<size_t>::param_type(0UL, i));
        size_t idx{uniform(rng)};
        if (idx < k) {
            samples[idx] = arr[i];
        }
    }
    return samples;
}
