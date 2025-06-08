class Solution {
public:
    long long calc(int x)
    {
        if (x < 0)
            return 0;
        return 1LL * x * (x - 1) / 2;
    }
    long long distributeCandies(int N, int limit) {
        return calc(N + 2) - 3 * calc(N - (limit + 1) + 2) + 3 * calc(N - 2 * (limit + 1) + 2) - calc(N - 3 * (limit + 1) + 2);
    }
};
