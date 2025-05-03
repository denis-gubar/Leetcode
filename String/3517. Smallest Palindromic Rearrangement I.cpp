class Solution {
public:
    string smallestPalindrome(string s) {
        int const N = s.size();
        string result, t;
        result.reserve(N);
        t.reserve(N);
        result = s.substr(0, N / 2);
        sort(result.begin(), result.end());
        copy(result.rbegin(), result.rend(), back_inserter(t));
        if (N % 2 == 1)
            result += s[N / 2];
        result += t;
        return result;
    }
};
