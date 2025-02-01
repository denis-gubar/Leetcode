class Solution {
public:
    string findValidPair(string s) {
        string result;
        int const N = s.size();
        unordered_map<int, int> M;
        for (char c : s)
            ++M[c - '0'];
        for(int i = 1; i < N; ++i)
            if (s[i - 1] != s[i])
            {
                int a = s[i - 1] - '0', b = s[i] - '0';
                if (M[a] == a && M[b] == b)
                    return s.substr(i - 1, 2);
            }
        return result;
    }
};
