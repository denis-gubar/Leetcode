class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int N = s.size();
        int D = dictionary.size();
        vector<vector<int>> A(N);
        for(int i = 0; i < N; ++i)
            for (int j = 0; j < D; ++j)
            {
                int M = dictionary[j].size();
                if (M + i <= N &&
                    equal(s.begin() + i, s.begin() + i + M, dictionary[j].begin(), dictionary[j].end()))
                    A[i].push_back(M);
            }
        vector<int> F(N + 2, 100);
        F[0] = 0;
        for (int i = 0; i < N; ++i)
        {
            F[i + 1] = min(F[i + 1], F[i] + 1);
            for (int M : A[i])
                F[i + M] = min(F[i + M], F[i]);
        }
        return F[N];
    }
};
