class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int result = 0;
        int const N = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < N - 2; ++i)
            for (int j = i + 1; j < N - 1; ++j)
            {
                int sum = nums[i] + nums[j];
                result += lower_bound(nums.begin() + j + 1, nums.end(), target - sum) - nums.begin() - j - 1;
            }
        return result;
    }
};
