class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int N = s.size();
        int Q = queries.size();
        vector<vector<int>> result(Q);
        unordered_map<int, pair<int, int>> M;
        if (size_t pos = s.find("0"s); pos != string::npos)
            M[0] = { static_cast<int>(pos), static_cast<int>(pos) };
        if (size_t pos = s.find("1"s); pos != string::npos)
            M[1] = { static_cast<int>(pos), static_cast<int>(pos) };
        for (int i = 0; i < N; ++i)
            if (s[i] != '0')
            {
                long long x = 1LL;
                for (int j = i + 1; j < N; ++j)
                {
                    x = (x << 1LL) + (s[j] - '0');
                    if (x >= (1LL << 30))
                        break;
                    if (M.find(x) == M.end())
                        M[x] = { i, j };
                }
            }
        for (int q = 0; q < Q; ++q)
        {
            int const& first = queries[q][0];
            int const& second = queries[q][1];
            string t;
            int x = first ^ second;
            if (auto it = M.find(x); it == M.end())
                result[q] = { -1, -1 };
            else
                result[q] = { it->second.first, it->second.second };
        }
        return result;
    }
};
