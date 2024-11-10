static int F[26][30'001];
class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        int const Q = queries.size(), N = s.size();
        vector<int> result(Q);
        for (int c = 0; c < 26; ++c)
            F[c][0] = 0;
        for (int i = 0; i < N; ++i)
        {
            int const x = s[i] - 'a';
            for (int c = 0; c < 26; ++c)
                F[c][i + 1] = F[c][i] + (c == x);
        }
        for (int q = 0; q < Q; ++q)
        {
            int const& L = queries[q][0];
            int const& R = queries[q][1];
            for (int c = 0; c < 26; ++c)
            {
                int const x = F[c][R + 1] - F[c][L];
                result[q] += x * (x + 1) / 2;
            }
        }
        return result;
    }
};
