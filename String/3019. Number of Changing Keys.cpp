class Solution {
public:
    int countKeyChanges(string s) {
        int result = 0;
        int N = s.size();
        for (int i = 1; i < N; ++i)
            result += tolower(s[i]) != tolower(s[i - 1]);
        return result;
    }
};
