class Solution {
public:
    string crackSafe(int N, int K) {
        int total = 1;
        for (int i = 0; i < N; ++i)
            total *= K;
        vector<bool> visited(total);
        string result;
        result.reserve(2 * total);
        int left = total;
        auto calc = [&result, N, K]()
            {
                int hash = 0;
                int const M = result.size();
                for (int i = M - N; i <= M - 1; ++i)
                    hash = hash * K + result[i] - '0';
                return hash;
            };
        auto dfs = [&](this const auto& self) -> bool
            {
                if (left == 0)
                    return true;
                int const M = result.size() + 1;
                result += '$';
                for (int i = 0; i < K; ++i)
                {
                    result.back() = '0' + i;
                    if (M >= N)
                    {
                        int hash = calc();
                        if (visited[hash])
                            continue;
                        visited[hash] = true;
                        --left;
                        if (self())
                            return true;
                        ++left;
                        visited[hash] = false;
                    }
                    else if (self())
                        return true;
                }
                result.pop_back();
                return false;
            };
        dfs();
        return result;
    }
};
