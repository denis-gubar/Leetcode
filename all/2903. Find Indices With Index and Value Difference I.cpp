class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> result = { -1, -1 };
        int N = nums.size();
        for (int i = 0; i < N; ++i)
            for (int j = i; j < N; ++j)
                if (abs(i - j) >= indexDifference && abs(nums[i] - nums[j]) >= valueDifference)
                    return { i, j };
        return result;
    }
};
