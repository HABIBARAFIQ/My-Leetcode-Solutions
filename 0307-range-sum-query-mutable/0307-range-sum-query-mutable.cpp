class NumArray {
private:
    vector<int> numscopy;
    vector<int> prefixSums;
    vector<int> segment_tree;
    int n;
    int size;
    void calculate_prefix_sum(int n, vector<int>& nums) {
        for (int i = 0; i < n; ++i) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
    }
    void create_seg_tree(int index, int left, int right) {
        if (left == right) {
            segment_tree[index] = numscopy[left];
            return;
        }
        int mid = (left + right) / 2;
        create_seg_tree(2 * index + 1, left, mid);
        create_seg_tree(2 * index + 2, mid + 1, right);
        segment_tree[index] = segment_tree[2 * index + 1] + segment_tree[2 * index + 2];
    }
    void update_seg_tree(int index, int left, int right, int indx, int val) {
        if (left == right) {
            segment_tree[index] = val;
            return;
        }
        int mid = (left + right) / 2;
        if (indx <= mid)
            update_seg_tree(2 * index + 1, left, mid, indx, val);
        else
            update_seg_tree(2 * index + 2, mid + 1, right, indx, val);
        segment_tree[index] = segment_tree[2 * index + 1] + segment_tree[2 * index + 2];
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        if (n == 0) return;
        size = (2 * n);
        segment_tree.resize(4 * n, 0);
        prefixSums.resize(n + 1, 0);
        numscopy = nums;

        calculate_prefix_sum(n, nums);
        create_seg_tree(0, 0, n - 1);
    }
    void update(int index, int val) {
        int diff = val - numscopy[index];
        numscopy[index] = val;
        update_seg_tree(0, 0, n - 1, index, val);
        for (int i = index + 1; i <= n; ++i) {
            prefixSums[i] += diff;
        }
    }
    int sumRange(int left, int right) {
        return prefixSums[right + 1] - prefixSums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
