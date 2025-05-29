static int F[200'001];
class Solution {
public:
    int maxSubstrings(string word) {
        memset(F, 0, sizeof(F));
        int const N = word.size();
        vector<vector<int>> A(26);
        for (int i = 0; i < 26; ++i)
            A[i].reserve(200'000);
        for (int i = 0; i < N; ++i)
            A[word[i] - 'a'].push_back(i);
        auto next = [&A, &word](int pos)
            {
                char c = word[pos];
                auto it = lower_bound(A[c - 'a'].begin(), A[c - 'a'].end(), pos + 3);
                if (it == A[c - 'a'].end())
                    return -1;
                return *it;
            };
        for (int i = 0; i < N; ++i)
        {
            F[i + 1] = max(F[i + 1], F[i]);
            if (int j = next(i); j >= 0)
                F[j + 1] = max(F[j + 1], F[i] + 1);
        }
        return F[N];
    }
};

