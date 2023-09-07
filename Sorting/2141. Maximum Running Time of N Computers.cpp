class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long a = 0, b = 1LL << 50;
        auto calc = [&batteries, n](long long m) -> bool
        {
            long long total = 0;
            for(int x : batteries)
                total += min<long long>(m, x);
            return total / m >= n;
        };
        while(a + 1 < b)
        {
            long long m = (a + b) / 2;
            if (calc(m))
                a = m;
            else
                b = m;
        }
        return a;
    }
};