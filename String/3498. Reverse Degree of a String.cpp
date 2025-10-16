class Solution {
public:
    int reverseDegree(string s) {
        int result = 0;
        int const N = s.size();
        for (int i = 0; i < N; ++i)
            result += (i + 1) * (26 - (s[i] - 'a'));
        return result;
    }
};
