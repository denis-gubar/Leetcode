class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> F(N + 2, vector<int>(N + 2));
        for (int length = 1; length <= N; ++length)
            for(int first = 0, last = first + length - 1; last < N; ++first, ++last)
                F[first + 1][last + 1] = max(nums[first] - F[first + 2][last + 1], nums[last] - F[first + 1][last]);
        return F[1][N] >= 0;
    }
};
