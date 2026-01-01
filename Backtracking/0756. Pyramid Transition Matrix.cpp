class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int const N = bottom.size();
        string next(N - 1, 'A');
        vector<bool> A(216);
        for (string const& s : allowed)
            A[(s[0] - 'A') * 36 + (s[1] - 'A') * 6 + (s[2] - 'A')] = true;
        auto dfs = [&A](this const auto& self, string const& s, string& next, int pos) -> bool
            {
                int const N = s.size();
                if (N == 1)
                    return true;
                if (N == pos)
                {
                    string ns = next;
                    string nnext(N - 2, 'A');
                    return self(ns, nnext, 1);
                }
                for(int c = 0; c < 6; ++c)
                    if (A[(s[pos - 1] - 'A') * 36 + (s[pos] - 'A') * 6 + c])
                    {
                        next[pos - 1] = 'A' + c;
                        if (self(s, next, pos + 1))
                            return true;
                    }
                return false;
            };
        return dfs(bottom, next, 1);
    }
};
