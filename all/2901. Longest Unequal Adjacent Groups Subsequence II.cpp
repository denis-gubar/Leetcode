class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int N, vector<string>& words, vector<int>& groups) {
        vector<string> result;
        vector<vector<int>> A(N);
        for (int i = 0; i < N; ++i)
        {
            int M = words[i].size();
            for (int j = i + 1; j < N; ++j)
                if (words[j].size() == M && groups[i] != groups[j])
                {
                    int x = 0;
                    for (int k = 0; k < M; ++k)
                        x += words[i][k] != words[j][k];
                    if (x == 1)
                        A[i].push_back(j);
                }
        }
        vector<int> F(N, 1);
        vector<int> P(N, -1);
        for (int i = 0; i < N; ++i)
            for (int j : A[i])
                if (F[j] <= F[i])
                    F[j] = F[i] + 1, P[j] = i;
        int pos = max_element(F.begin(), F.end()) - F.begin();
        while(pos != -1)
        {
            result.push_back(words[pos]);
            pos = P[pos];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
