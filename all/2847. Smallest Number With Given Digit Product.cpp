static int M[10];
class Solution {
public:
    string smallestNumber(long long N) {
        if (N == 1) return "1";
        memset(M, 0, sizeof(M));
        long long x = N;
        for (int i = 2; i < 10; ++i)
            while (N % i == 0)
                ++M[i], N /= i;
        if (N > 1)
            return "-1";
        int delta = M[3] / 2;
        M[3] -= 2 * delta;
        M[9] += delta;
        delta = M[2] / 3;
        M[2] -= 3 * delta;
        M[8] += delta;
        if (min(M[2], M[3]) == 1)
            --M[2], --M[3], ++M[6];
        delta = M[2] / 2;
        M[2] -= 2 * delta;
        M[4] += delta;
        string result;
        for (int i = 2; i < 10; ++i)
            for (int k = 0; k < M[i]; ++k)
                result += '0' + i;
        return result;
    }
};
