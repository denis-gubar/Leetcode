class Solution {
public:
    vector<int> minDifference(int N, int K) {
        vector<int> result(K, 1);
        result.back() = N;
        vector<int> divs;
        for(int i = 1; i * i <= N; ++i)
            if (N % i == 0)
            {
                divs.push_back(i);
                if (i * i < N)
                    divs.push_back(N / i);
            }
        sort(divs.begin(), divs.end());
        int const D = divs.size();
        int best = N;
        vector<int> A(K);
        auto dfs = [&divs, &A, N, D, K, &best, &result](this const auto& self, int i, int k, long long prod) -> void
            {
                if (prod > N)
                    return;
                if (i == K && prod == N)
                {
                    if (best > A.back() - A[0])
                        best = A.back() - A[0], result = A;
                    return;
                }
                if (i == K)
                    return;
                for (int j = k; j < D; ++j)
                {
                    A[i] = divs[j];
                    self(i + 1, j, prod * divs[j]);
                }
            };
        dfs(0, 0, 1);
        return result;
    }
};
