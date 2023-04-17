static int F[1'000][1'000];
class Solution {
public:
    int N;
    array<vector<int>, 26> A;
    int calc(int left, int right)
    {
        if (left > right)
            return 0;
        int& result = F[left][right];
        if (result < 0)
        {
            result = 0;
            for (int letter = 0; letter < 26; ++letter)
            {
                int nextLeft = *lower_bound(A[letter].begin(), A[letter].end(), left);
                if (nextLeft > right)
                    continue;
                int nextRight = *prev(upper_bound(A[letter].begin(), A[letter].end(), right));
                if (nextRight < left)
                    continue;
                if (nextLeft != nextRight)
                    result = max(result, 2 + calc(nextLeft + 1, nextRight - 1));
                else
                    result = max(result, 1);
            }
        }
        return result;
    }
    int longestPalindromeSubseq(string const& s) {
        memset(F, -1, sizeof(F));
        N = s.size();
        for (int letter = 0; letter < 26; ++letter)
            A[letter].push_back(-1);
        for (int i = 0; i < N; ++i)
            A[s[i] - 'a'].push_back(i);
        for (int letter = 0; letter < 26; ++letter)
            A[letter].push_back(N);
        return calc(0, N - 1);
    }
};
