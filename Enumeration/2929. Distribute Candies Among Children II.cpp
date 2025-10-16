static long long F[3'000'001];
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long result = 0;
        memset(F, 0, sizeof(F));
        for (int i = 0; i <= limit; ++i)
            F[i] = i + 1;
        for (int i = 0; i <= limit; ++i)
            F[i + limit] = limit - i + 1;
        for (int i = 0, end = min(limit, n); i <= end; ++i)
            result += F[n - i];
        return result;
    }
};
