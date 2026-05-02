class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> result;
        int const N = nums.size();
        for (int i = 0; i < N; ++i)
        {
            if (i == 0 || i == N - 1)
            {
                result.push_back(nums[i]);
                continue;
            }
            if (*max_element(nums.begin(), nums.begin() + i) < nums[i])
            {
                result.push_back(nums[i]);
                continue;
            }
            if (*max_element(nums.begin() + i + 1, nums.end()) < nums[i])
                result.push_back(nums[i]);
        }
        return result;
    }
};
