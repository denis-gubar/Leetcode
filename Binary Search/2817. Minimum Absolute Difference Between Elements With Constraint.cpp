class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int N = nums.size();
        int result = 1 << 30;
        set<int> S;
        for (int i = x; i < N; ++i)
        {
            S.insert(nums[i - x]);
            auto it = S.lower_bound(nums[i]);
            if (it != S.end())
                result = min(result, abs(*it - nums[i]));
            if (it != S.begin())
                result = min(result, abs(*(prev(it)) - nums[i]));
        }
        return result;
    }
};
