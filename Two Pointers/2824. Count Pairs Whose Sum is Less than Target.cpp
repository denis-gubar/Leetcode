class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int result = 0;
        int N = nums.size();
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                result += (nums[i] + nums[j] < target);
        return result;
    }
};
