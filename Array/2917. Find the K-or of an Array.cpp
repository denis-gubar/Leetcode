class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int result = 0;
        int N = nums.size();
        for (int j = 0; j < 31; ++j)
        {
            int count = 0;
            for (int i = 0; i < N; ++i)
                count += ((1 << j) & nums[i]) != 0;
            if (count >= k)
                result |= 1 << j;
        }
        return result;
    }
};
