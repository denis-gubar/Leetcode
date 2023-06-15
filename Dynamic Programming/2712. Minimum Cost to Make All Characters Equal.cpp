class Solution {
public:
    long long minimumCost(string s) {
        long long result = 0;
        int N = s.size();
        for (int i = 1; i < N; ++i)
            if (s[i - 1] != s[i])
                result += min(i, N - i);
        return result;
    }
};
