class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int N = ranks.size();
        long long a = 0, b = 100'000'000'000'000LL;
        sort(ranks.begin(), ranks.end());
        auto check = [&ranks, cars, N](long long m)
        {
            long long total = 0;
            for (int i = 0; total < cars && i < N && ranks[i] <= m; ++i)
            {
                long long x = sqrt(1.0 * m / ranks[i]) + 0.5;
                while (ranks[i] * x * x > m)
                    --x;
                total += x;
            }
            return total >= cars;
        };
        while (a + 1 < b)
        {
            long long m = (a + b) / 2;
            if (check(m))
                b = m;
            else
                a = m;
        }
        return b;
    }
};
