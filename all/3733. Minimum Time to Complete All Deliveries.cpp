class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long a = 0, b = 1LL << 60;
        auto calc = [&d, &r](long long m)
            {
                if (r[0] == r[1])
                    return m - m / r[0] >= d[0] + d[1];
                int x = r[0], y = r[1];
                long long fy = m / x - m / lcm(x, y), fx = m / y - m / lcm(x, y);
                long long common = m - fx - fy - m / lcm(x, y);
                return max(d[0] - fx, 0LL) + max(d[1] - fy, 0LL) <= common;
            };
        while (a + 1 < b)
        {
            long long m = (a + b) / 2;
            if (calc(m))
                b = m;
            else
                a = m;
        }
        return b;
    }
};
