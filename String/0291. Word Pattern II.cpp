class Solution {
public:
    string_view pattern;
    string_view s;
    vector<string_view> A;
    unordered_map<char, int> M;
    unordered_map<char, int> inv;
    int total;
    int N, K, O;
    bool calc(int i, int totalLength, int prefixLength = 0)
    {
        if (i == N)
            return prefixLength == K;
        int const& pos = inv[pattern[i]];
        if (A[pos].empty())
        {
            while (true)
            {
                if (!A[pos].empty())
                    totalLength += M[pattern[i]];
                if (totalLength > K)
                {
                    A[pos] = s.substr(prefixLength, 0);
                    return false;
                }
                A[pos] = s.substr(prefixLength, A[pos].size() + 1);
                bool flag = true;
                for (int j = 0; j < pos; ++j)
                    if (A[j] == A[pos])
                    {
                        flag = false;
                        break;
                    }
                if (flag && calc(i + 1, totalLength, prefixLength + A[pos].size()))
                    return true;
            }
        }
        else
        {
            if (s.substr(prefixLength, A[pos].size()) != A[pos])
                return false;
            if (calc(i + 1, totalLength, prefixLength + A[pos].size()))
                return true;
        }
        return false;
    }
    bool wordPatternMatch(string pattern, string s) {
        this->pattern = pattern;
        this->s = s;
        M.clear();
        inv.clear();
        for (char c : pattern)
            if (++M[c] == 1)
                inv[c] = M.size() - 1;
        N = pattern.size(), K = s.size(), O = M.size(), total = 0;
        A.resize(O);
        return calc(0, N);
    }
};
