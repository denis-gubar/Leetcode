class Solution {
public:
    int maxScore(vector<int>& nums) {
        int N = nums.size();
        int result = 0;
        sort(nums.begin(), nums.end());
        long long sum = nums[N - 1];
        for (int i = N - 2; sum > 0 && i >= 0; --i)
        {
            if (sum > 0)
                ++result;
            sum += nums[i];
        }
        if (sum > 0)
            ++result;
        return result;
    }
};
