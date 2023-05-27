class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int N = s.size();
        for (int a = 0, b = N - 1; a < b; ++a, --b)
            s[a] = s[b] = min(s[a], s[b]);
        return s;
    }
};
