class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int N = nums.size(), M = nums[0].size();
        int result = 0;
        for (int i = 0; i < N; ++i)
            sort(nums[i].begin(), nums[i].end());
        for (int j = 0; j < M; ++j)
        {
            int x = 0;
            for (int i = 0; i < N; ++i)
                x = max(x, nums[i][j]);
            result += x;
        }        
        return result;
    }
};
