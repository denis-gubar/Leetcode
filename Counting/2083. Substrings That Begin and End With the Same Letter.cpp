class Solution {
public:
    long long numberOfSubstrings(string s) {
        long long result = 0;
        vector<int> A(26);
        for(char c: s)
            ++A[c - 'a'];
        for(long long x : A)
            result += x * (x + 1);
        return result / 2;
    }
};