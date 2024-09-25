class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int const N = workerTimes.size();
        long long a = 0, b = 1LL << 60;
        auto calc = [&workerTimes, mountainHeight](long long m) -> bool
            {
                long long result = 0;
                for (int w : workerTimes)
                {
                    long long k = m / w;
                    long long x = sqrt(2.0 * k);                    
                    if (x * (x + 1) / 2 * w <= m)
                        result += x;
                    else if (x * (x - 1) / 2 * w <= m)
                        result += x - 1;
                }
                return result >= mountainHeight;
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
