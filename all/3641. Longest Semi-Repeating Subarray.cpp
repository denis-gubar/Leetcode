class Solution {
public:
    int longestSubarray(vector<int>& nums, int K) {
        int const N = nums.size();
        int a = 0, b = 0, duplicateCount = 0;
        unordered_map<int, int> M;
        int result = 0;
        while (b < N)
        {
            if (++M[nums[b]] == 2)
                ++duplicateCount;
            ++b;
            while (duplicateCount > K)
            {
                if (--M[nums[a]] == 1)
                    --duplicateCount;
                ++a;
            }
            result = max(result, b - a);
        }
        return result;
    }
};
