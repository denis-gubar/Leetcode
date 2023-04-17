class Solution {
public:
    vector<int> mostSimilar(int N, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        vector<vector<bool>> G(N, vector<bool>(N));
        int K = targetPath.size();
        for (vector<int> const& r : roads)
        {
            int const& V = r[0];
            int const& U = r[1];
            G[V][U] = G[U][V] = true;
        }
        auto code = [](string const& s)
        {
            return ((s[0] - 'A') * 26 + (s[1] - 'A')) * 26 + (s[2] - 'A');
        };
        vector<int> codes(N);
        for (int V = 0; V < N; ++V)
            codes[V] = code(names[V]);
        vector<vector<int>> F(K, vector<int>(N, K + 1));
        vector<vector<int>> R(K, vector<int>(N, -1));
        for (int V = 0, C = code(targetPath[0]); V < N; ++V)
            F[0][V] = C != codes[V];
        for (int step = 1; step < K; ++step)
            for (int V = 0, C = code(targetPath[step]); V < N; ++V)
                if (F[step - 1][V] < K)
                    for (int U = 0; U < N; ++U)
                        if (G[V][U] && F[step][U] > F[step - 1][V] + (C != codes[U]))
                        {
                            F[step][U] = F[step - 1][V] + (C != codes[U]);
                            R[step][U] = V;
                        }
        vector<int> result(K);
        result[K - 1] = min_element(F[K - 1].begin(), F[K - 1].end()) - F[K - 1].begin();
        for (int step = K - 2; step >= 0; --step)
            result[step] = R[step + 1][result[step + 1]];
        return result;
    }
};
