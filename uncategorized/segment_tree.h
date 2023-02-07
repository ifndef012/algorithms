#include <vector>

class SegmentTree {
public:
    SegmentTree(const std::vector<int>& nums): tree_(4 * nums.size(), 0) {
        BuildTree(1, 0, nums.size() - 1, nums);
    }

    void BuildTree(int node, int l, int r, const std::vector<int>& nums) {
        if (l == r) { // leaf
            tree_[node] = nums[l];
            return;
        }
        int m{l + (r - l) / 2};
        BuildTree(2 * node, l, m, nums);
        BuildTree(2 * node + 1, m + 1, r, nums);
        tree_[node] = tree_[2 * node] + tree_[2 * node + 1];
    }

    int Query(int l, int r) const {
        return Query(1, 0, tree_.size() / 4 - 1, l, r);
    }

    void Update(int idx, int val) {
        Update(1, 0, tree_.size() / 4 - 1, idx, val);
    }

private:
    int Query(int node, int l, int r, const int ql, const int qr) const {
        if (r < ql || l > qr) { // out of query range
            return 0;
        }
        if (ql <= l && r <= qr) { // completely in range
            return tree_[node];
        }
        int m{l + (r - l) / 2};
        return Query(2 * node, l, m, ql, qr) + Query(2 * node + 1, m + 1, r, ql, qr);
    }

    void Update(int node, int l, int r, const int idx, const int val) {
        if (l == r) { // leaf
            tree_[node] = val;
            return;
        }
        int m{l + (r - l) / 2};
        if (idx <= m) { // in left tree
            Update(2 * node, l, m, idx, val);
        } else { // in right tree
            Update(2 * node + 1, m + 1, r, idx, val);
        }
        tree_[node] = tree_[2 * node] + tree_[2 * node + 1];
    }
    std::vector<int> tree_;

};
