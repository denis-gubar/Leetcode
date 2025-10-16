class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int total = 0;
        int const N = s.size();
        vector<int> A;
        A.reserve(N);
        char prev = '1';
        int count = 0;
        for (int i = 0; i < N; ++i)
        {
            total += s[i] == '1';
            if (s[i] == prev)
                ++count;
            else
                prev = s[i], A.push_back(count), count = 1;
        }
        A.push_back(count);
        int result = total;
        int const M = A.size();
        for (int i = 2; i + 1 < M; i += 2)
            result = max(result, total + A[i - 1] + A[i + 1]);
        return result;
    }
};
