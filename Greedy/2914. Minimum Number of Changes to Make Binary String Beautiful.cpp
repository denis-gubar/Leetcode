class Solution {
public:
    int minChanges(string s) {
        int result = 0;
        int N = s.size();
        for (int i = 0; i < N; i += 2)
            result += s[i] != s[i + 1];
        return result;
    }
};
