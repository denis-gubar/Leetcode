class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int result = 0;
        int N = nums.size();
        int a = 0, b = 0;
        int zeroCount = 0;
        while (b < N)
        {
            if (nums[b] == 0)
                ++zeroCount;
            while (zeroCount > k)
            {
                if (nums[a] == 0)
                    --zeroCount;
                ++a;
            }
            ++b;
            result = max(result, b - a);
        }
        return result;
    }
};
