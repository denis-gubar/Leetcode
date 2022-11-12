class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result = 1;
        int M = *max_element(nums.begin(), nums.end());
        nums.push_back(-2);
        int N = nums.size();
        int current = 0;
        int prev = -1;
        for (int i = 0; i < N; ++i)
        {
            if (prev == nums[i] && prev == M)
            {
                ++current;
                result = max(current, result);
            }
            else if (nums[i] == M)
                current = 1;
            prev = nums[i];
        }
        return result;
    }
};
