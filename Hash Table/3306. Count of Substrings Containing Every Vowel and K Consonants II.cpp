class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        string const vowels{ "aeiou" };
        int const N = word.size();
        long long result = 0;
        auto f = [&vowels](char c)
            {
                return vowels.find(c) == string::npos ? 5 : vowels.find(c);
            };
        vector<vector<int>> A(6);
        for (int c = 0; c < 6; ++c)
            A.reserve(N + N);
        for (int i = 0; i < N; ++i)
            A[f(word[i])].push_back(i);
        for (int c = 0; c < 5; ++c)
            A[c].push_back(N);
        for (int i = 0; i <= k; ++i)
            A[5].push_back(N);
        for (int L = 0; L < N; ++L)
        {
            int R = 0;
            for (int c = 0; c < 5; ++c)
                R = max(R, *lower_bound(A[c].begin(), A[c].end(), L));
            if (k == 0)
            {
                int b = *(lower_bound(A[5].begin(), A[5].end(), L) + k) - 1;
                result += max(0, b - R + 1);
                continue;
            }
            int a = *(lower_bound(A[5].begin(), A[5].end(), L) + (k - 1));
            int b = *(lower_bound(A[5].begin(), A[5].end(), L) + k) - 1;
            if (a < N)
            {
                if (a >= R)
                    result += b - a + 1;
                else if (b >= R)
                    result += b - R + 1;
            }
        }
        return result;
    }
};
