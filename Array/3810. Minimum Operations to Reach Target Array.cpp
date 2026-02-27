class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int const N = nums.size();
        unordered_set<int> S;
        for (int i = 0; i < N; ++i)
            if (nums[i] != target[i])
                S.insert(nums[i]);
        return S.size();
    }
};
