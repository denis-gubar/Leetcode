class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> F(2, vector<int>(N));
        F[0] = nums;
        for (int k = 1; k < N; ++k)
            for (int i = 0; i < N - k; ++i)
                F[k % 2][i] = (F[(k + 1) % 2][i] + F[(k + 1) % 2][i + 1]) % 10;
        return F[(N + 1) % 2][0];
    }
};
