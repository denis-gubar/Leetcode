class Solution {
public:
    int maximumLengthSubstring(string s) {
        int N = s.size();
        int result = 0;
        for (int start = 0; start < N; ++start)
        {
            vector<int> A(26);
            for (int pos = start; pos <= N; ++pos)
                if (pos == N || ++A[s[pos] - 'a'] == 3)
                {
                    result = max(result, pos - start);
                    break;
                }
        }
        return result;
    }
};
