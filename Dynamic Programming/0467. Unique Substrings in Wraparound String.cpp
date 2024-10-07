class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int result = 0;
        int const N = s.size();
        vector<int> A(26);
        s += '$';
        for (int i = 0; i < N; )
        {
            int j = i;
            while ((s[i] + j + 1 - i) % 26 == s[j + 1] % 26)
                ++j;
            for (int k = 0, delta = j - i, kmax = min(25, delta); k <= kmax && i + k < N; ++k, --delta)
            {
                int const c = s[i + k] - 'a';
                A[c] = max(A[c], delta + 1);
            }
            i = j + 1;
        }
        for (int i = 0; i < 26; ++i)
            result += A[i];
        return result;
    }
};
