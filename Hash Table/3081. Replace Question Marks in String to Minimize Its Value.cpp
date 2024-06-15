class Solution {
public:
    string minimizeStringValue(string s) {
        string result(s);
        int N = s.size();
        string t;
        t.reserve(N);
        vector<int> A(26);
        int x = 0;
        for (char c : s)
            if (c == '?')
                ++x;
            else
                ++A[c - 'a'];
        set<pair<int, char>> S;
        for (int i = 0; i < 26; ++i)
            S.emplace(A[i], i + 'a');
        for (int i = 0; i < x; ++i)
        {
            pair<int, char> P = *S.begin();
            S.erase(S.begin());
            S.emplace(P.first + 1, P.second);
            t += P.second;
        }
        sort(t.begin(), t.end());
        for(int i = 0, j = 0; j < x; ++i)
            if (result[i] == '?')
            {
                result[i] = t[j];
                ++j;
            }
        return result;
    }
};
