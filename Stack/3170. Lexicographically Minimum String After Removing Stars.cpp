class Solution {
public:
    string clearStars(string s) {
        set<pair<char, int>> S;
        int N = s.size();
        for (int i = 0; i < N; ++i)
        {
            if (s[i] != '*')
                S.emplace(s[i], -i);
            else
                S.erase(S.begin());
        }
        string result;
        int M = S.size();
        result.reserve(M);
        vector<pair<int, char>> P;
        P.reserve(M);
        for (auto [c, pos] : S)
            P.emplace_back(-pos, c);
        sort(P.begin(), P.end());
        for (auto [pos, c] : P)
            result += c;
        return result;
    }
};
