class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        auto it = stable_partition(nums.begin(), nums.end(), [pivot](int x)
        {
            return x < pivot;
        });
        stable_partition(it, nums.end(), [pivot](int x)
        {
            return x == pivot;
        });
        return nums;
    }
};
