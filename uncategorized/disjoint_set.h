#include <vector>
#include <numeric>

class DisjointSet {
public:
    DisjointSet(int size): representor_(size, 0), rank_(size, 0) {
        std::iota(representor_.begin(), representor_.end(), 0);
    }

    int FindRepresentor(int x) {
        if (x == representor_[x]) return x;
        return representor_[x] = FindRepresentor(representor_[x]);
    }

    void Union(int x, int y) {
        int root_x{FindRepresentor(x)};
        int root_y{FindRepresentor(y)};
        if (root_x == root_y) return;
        if (rank_[root_x] < rank_[root_y]) {
            representor_[root_x] = root_y;
        } else if (rank_[root_x] > rank_[root_y]) {
            representor_[root_y] = root_x;
        } else {
            representor_[root_y] = root_x;
            ++rank_[root_x];
        }
    }

private:
    std::vector<int> representor_;
    std::vector<int> rank_;
};
