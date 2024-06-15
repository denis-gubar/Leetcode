class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long x = count(s.begin(), s.end(), c);
        long long result = x * (x + 1) / 2;
        return result;
    }
};
