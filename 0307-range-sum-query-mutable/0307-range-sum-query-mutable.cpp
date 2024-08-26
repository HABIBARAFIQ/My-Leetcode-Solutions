class NumArray {
private:
    vector<int> segment_tree;
    int n;

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segment_tree.resize(4 * n, 0); // Allocating enough space for the segment tree
        buildSegmentTree(nums, segment_tree, 0, 0, n - 1);
    }

    void update(int index, int val) {
        updateSegmentTree(segment_tree, 0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return rangeSumQuery(segment_tree, 0, 0, n - 1, left, right);
    }

private:
    void buildSegmentTree(vector<int>& nums, vector<int>& segment_tree, int index, int left, int right) {
        if (left == right) {
            segment_tree[index] = nums[left];
        } else {
            int mid = left + (right - left) / 2;
            buildSegmentTree(nums, segment_tree, 2 * index + 1, left, mid);
            buildSegmentTree(nums, segment_tree, 2 * index + 2, mid + 1, right);
            segment_tree[index] = segment_tree[2 * index + 1] + segment_tree[2 * index + 2];
        }
    }

    int rangeSumQuery(vector<int>& segment_tree, int index, int left, int right, int L, int R) {
        if (L <= left && right <= R) {
            return segment_tree[index];
        }
        if (right < L || left > R) {
            return 0;
        }
        int mid = left + (right - left) / 2;
        return rangeSumQuery(segment_tree, 2 * index + 1, left, mid, L, R) +
               rangeSumQuery(segment_tree, 2 * index + 2, mid + 1, right, L, R);
    }

    void updateSegmentTree(vector<int>& segment_tree, int index, int left, int right, int idx, int val) {
        if (left == right) {
            segment_tree[index] = val;
        } else {
            int mid = left + (right - left) / 2;
            if (idx <= mid) {
                updateSegmentTree(segment_tree, 2 * index + 1, left, mid, idx, val);
            } else {
                updateSegmentTree(segment_tree, 2 * index + 2, mid + 1, right, idx, val);
            }
            segment_tree[index] = segment_tree[2 * index + 1] + segment_tree[2 * index + 2];
        }
    }
};
