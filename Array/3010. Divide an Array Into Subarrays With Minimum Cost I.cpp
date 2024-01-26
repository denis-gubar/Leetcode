class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int result = 150;
        int N = nums.size();
        for (int i = 1; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                result = min(result, nums[i] + nums[j]);
        return result + nums[0];
    }
};
