class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int N = nums.size();
        int last = -1;
        int result = 0;
        unordered_map<int, vector<int>> M;
        for (int i = 0; i < N; ++i)
        {
            M[nums[i]].push_back(i);
            auto& V = M[nums[i]];
            if (V.size() > k)
                last = max(last, V[V.size() - k - 1]);
            result = max(result, i - last);
        }
        return result;
    }
};
