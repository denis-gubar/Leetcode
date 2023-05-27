class Solution {
public:
    bool check(string const& s, int prefixSize)
    {
        for (int i = prefixSize, N = s.size(); i < N; ++i)
            if (s[i] != s[i % prefixSize])
                return false;
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int N = str1.size(), M = str2.size();
        for (int x = N; x > 0; --x)
            if (N % x == 0 && M % x == 0 && equal(str1.begin(), str1.begin() + x, str2.begin(), str2.begin() + x) &&
                check(str1, x) && check(str2, x))
                return str1.substr(0, x);
        return {};
    }
};
