class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int N = nums.size();
        int result = 0;
        for (int i = 0; i < N; ++i)
        {
            int x = nums[i];
            for (int j = i; x <= k && j < N; ++j)
            {
                x = lcm(x, nums[j]);
                if (x == k)
                    ++result;
            }
        }
        return result;
    }
};
