static int F[1'000];
static int A[1'000];
class Solution {
public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        vector<int> result;
        int const N = coins.size();
        if (N == 1)
            return { 1 };
        memset(F, 1, sizeof(F));
        memset(A, 1, sizeof(F));
        vector<vector<int>> P(N);
        int const INF = F[0];
        F[0] = 0;
        auto update = [&coins, &P](int pos, int prev)
            {
                if (coins[pos] < 0)
                    return;
                int const value = F[prev] + coins[pos];
                if (F[pos] > value)
                {
                    F[pos] = value, P[pos].clear(), P[pos].push_back(prev);
                    return;
                }
                if (F[pos] == value)
                    P[pos].push_back(prev);
            };
        for (int i = 0; i < N; ++i)
            if (F[i] < INF)
            {
                for (int j = i + 1, e = min(N - 1, i + maxJump); j <= e; ++j)
                    update(j, i);
            }
        if (F[N - 1] == INF)
            return result;
        result.reserve(N);
        vector<bool> visited(N);
        visited[N - 1] = true;
        for (int i = N - 1; i >= 0; --i)
            if (visited[i])
                for (int p : P[i])
                    visited[p] = true;
        for (int i = N - 1; i >= 0; --i)
            if (visited[i])
                for (int p : P[i])
                    if (visited[p])
                        A[p] = min(A[p], i);
        for (int i = 0; i < N - 1; )
        {
            result.push_back(i + 1);
            i = A[i];
        }
        if (N > 1)
            result.push_back(N);
        return result;
    }
};
