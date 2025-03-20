class Solution {
public:
    int maxSum(vector<int>& nums) {
        int const N = nums.size();
        int result = -100;
        for (int a = 0; a < N; ++a)
        {
            int total = 0;
            unordered_set<int> S;
            for (int b = a; b < N; ++b)
                if (nums[b] >= 0)
                {
                    if (S.insert(nums[b]).second)
                        total += nums[b];
                }
            if (S.empty())
                total = nums[a];
            result = max(result, total);
        }
        return result;
    }
};
