class Solution {
public:
    bool makePalindrome(string s) {
        int const N = s.size();
        int count = 0;
        for (int a = 0, b = N - 1; a < b; ++a, --b)
            count += s[a] != s[b];
        return count <= 2;
    }
};
