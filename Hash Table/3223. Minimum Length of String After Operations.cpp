class Solution {
public:
    int minimumLength(string s) {
        int const N = s.size();
        int result = N;
        vector<int> A(26);
        for (char c : s)
            ++A[c - 'a'];
        for (int c = 0; c < 26; ++c)
            if (A[c] > 2)
                result -= (A[c] - 1) / 2 * 2;
        return result;
    }
};
