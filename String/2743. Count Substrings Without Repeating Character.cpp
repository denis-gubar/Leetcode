class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int result = 0;
        vector<int> A(26, -1);
        int last = 0;
        for (int i = 0, N = s.size(); i < N; ++i)
        {
            char const c = s[i] - 'a';
            last = max(last, A[c] + 1);
            A[c] = i;
            result += i - last + 1;
        }
        return result;
    }
};
