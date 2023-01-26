class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> result(score);
        int N = score.size(), M = score[0].size();
        vector<int> A(N);
        iota(A.begin(), A.end(), 0);
        sort(A.begin(), A.end(), [&score, k](int a, int b)
            {
                return score[a][k] > score[b][k];
            });
        for (int i = 0; i < N; ++i)
            result[i] = score[A[i]];
        return result;
    }
};
