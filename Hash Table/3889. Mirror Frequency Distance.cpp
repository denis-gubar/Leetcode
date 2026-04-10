class Solution {
public:
    int mirrorFrequency(string s) {
        int result = 0;
        int const N = s.size();
        vector<int> A(128);
        for (char c : s)
            ++A[c];
        for (char c = 'a', d = 'z'; c < d; ++c, --d)
            result += abs(A[c] - A[d]);
        for (char c = '0', d = '9'; c < d; ++c, --d)
            result += abs(A[c] - A[d]);
        return result;
    }
};
