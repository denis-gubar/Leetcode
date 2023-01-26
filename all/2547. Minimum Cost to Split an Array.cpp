class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int N = nums.size();
        vector<vector<int>> A(N, vector<int>(N));
        for (int i = 0; i < N; ++i)
        {
            unordered_map<int, int> M;
            int sum = k;
            for (int j = i; j < N; ++j)
            {
                int x = ++M[nums[j]];
                if (x > 1)
                    ++sum;
                if (x == 2)
                    ++sum;
                A[i][j] = sum;
            }
        }
        vector<int> F(N + 1, k + N);
        F[0] = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i; j < N; ++j)
                F[j + 1] = min(F[j + 1], F[i] + A[i][j]);
        return F[N];
    }
};
