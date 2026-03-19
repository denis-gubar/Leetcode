class Solution {
public:
    vector<int> delayedCount(vector<int>& nums, int K) {
        int const N = nums.size();
        vector<int> result(N);
        unordered_map<int, vector<int>> M;
        for (int i = 0; i < N; ++i)
            M[nums[i]].push_back(i);
        for (int i = 0; i < N; ++i)
            result[i] = M[nums[i]].end() - upper_bound(M[nums[i]].begin(), M[nums[i]].end(), i + K);
        return result;
    }
};
