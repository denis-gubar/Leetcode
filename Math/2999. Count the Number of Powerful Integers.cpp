static long long F[17][2][2];
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        long long result = 0;
        string A = to_string(start), B = to_string(finish);
        int N = B.size(), K = s.size();
        reverse(A.begin(), A.end());
        while (A.size() != N)
            A.push_back('0');
        reverse(A.begin(), A.end());
        memset(F, 0, sizeof(F));
        F[0][1][1] = 1;
        for (int i = 0; i < N; ++i)
                for (int isA = 0, a = A[i] - '0', b = B[i] - '0'; isA < 2; ++isA)
                    for (int isB = 0; isB < 2; ++isB)
                    {
                        long long& prevF = F[i][isA][isB];
                        if (prevF)
                            for (int d = 0; d <= limit; ++d)
                                if ((!isA || d >= a) && (!isB || d <= b))
                                {
                                    if (i + K >= N && d + '0' != s[K - (N - i)])
                                        continue;
                                    long long& nextF = F[i + 1][isA && d == a][isB && d == b];
                                    nextF += prevF;
                                }
                    }
        for (int isA = 0; isA < 2; ++isA)
            for (int isB = 0; isB < 2; ++isB)
                result += F[N][isA][isB];
        return result;
    }
};
