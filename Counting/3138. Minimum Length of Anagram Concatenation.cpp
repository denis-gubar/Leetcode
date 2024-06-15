class Solution {
public:
    int minAnagramLength(string s) {
        int N = s.size();
        vector<vector<int>> A(26, vector<int>(N + 1));
        for (int c = 0; c < 26; ++c)
            for (int i = 0; i < N; ++i)
                A[c][i + 1] = A[c][i] + (s[i] == c + 'a');
        for(int length = 1; length <= N / 2; ++length)
            if (N % length == 0)
            {
                bool flag = true;
                for(int i = length; flag && i < N; i += length)
                    for (int c = 0; flag && c < 26; ++c)
                        flag = A[c][i + length] - A[c][i] == A[c][length];
                if (flag)
                    return length;
            }
        return N;
    }
};
