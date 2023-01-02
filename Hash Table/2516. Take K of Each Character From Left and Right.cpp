class Solution {
public:
    int takeCharacters(string s, int k) {
        int N = s.size();
        vector<vector<int>> A(3, vector<int>(N + 1));
        for (int j = 0; j < N; ++j)
        {
            for (int i = 0; i < 3; ++i)
                A[i][j + 1] = A[i][j];
            ++A[s[j] - 'a'][j + 1];
        }
        if (A[0][N] < k || A[1][N] < k || A[2][N] < k)
            return -1;
        vector<int> M(3);
        int result = N;
        for (int right = N - 1, j = 0; right >= 0; --right, ++j)
        {
            int left = 0;
            for (int i = 0; i < 3; ++i)
                if (M[i] < k)
                    left = max<int>(left, lower_bound(A[i].begin(), A[i].end(), k - M[i]) - A[i].begin());
            result = min(result, j + left);
            ++M[s[right] - 'a'];
        }
        return result;
    }
};
