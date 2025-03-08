static int F[1'001][1'001];
class Solution {
public:
    int minCost(vector<int>& nums) {
        int const N = nums.size();
        if (N < 3)
            return *max_element(nums.begin(), nums.end());
        memset(F, 60, sizeof(F));
        int const INF = F[0][0];
        vector<int> A(nums);
        A.push_back(0);
        sort(A.begin(), A.end());
        A.resize(unique(A.begin(), A.end()) - A.begin());
        int M = A.size();
        unordered_map<int, int> D;
        for (int i = 0; i < M; ++i)
            D[A[i]] = i;
        auto update = [](int& x, int value)
            {
                if (x > value)
                    x = value;
            };
        update(F[0][D[nums[0]]], max(nums[1], nums[2]));
        update(F[0][D[nums[1]]], max(nums[0], nums[2]));
        update(F[0][D[nums[2]]], max(nums[0], nums[1]));
        int i = 4, k = 1;
        for ( ; i < N; i += 2, ++k)
        {
            for(int j = 0; j < M; ++j)
                if (F[k - 1][j] < INF)
                {
                    update(F[k][j], max(nums[i - 1], nums[i]) + F[k - 1][j]);
                    update(F[k][D[nums[i - 1]]], max(A[j], nums[i]) + F[k - 1][j]);
                    update(F[k][D[nums[i]]], max(A[j], nums[i - 1]) + F[k - 1][j]);
                }
        }
        if (i == N)
            for (int j = 0; j < M; ++j)
                if (F[k - 1][j] < INF)
                    update(F[k][0], max(A[j], nums[i - 1]) + F[k - 1][j]);
        if (i == N + 1)
            for (int j = 0; j < M; ++j)
                if (F[k - 1][j] < INF)
                    update(F[k][0], A[j] + F[k - 1][j]);
        return F[k][0];
    }
};
