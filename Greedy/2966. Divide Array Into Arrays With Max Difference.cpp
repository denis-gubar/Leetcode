class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int N = nums.size();
        vector<vector<int>> result(N / 3);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N; ++i)
        {
            result[i / 3].push_back(nums[i]);
            if (i % 3 == 2 && result[i / 3][2] - result[i / 3][0] > k)
                return {};
        }
        return result;
    }
};
