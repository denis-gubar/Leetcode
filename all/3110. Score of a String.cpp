class Solution {
public:
    int scoreOfString(string s) {
        int result = 0;
        int N = s.size();
        for (int i = 1; i < N; ++i)
            result += abs(s[i - 1] - s[i]);
        return result;
    }
};
