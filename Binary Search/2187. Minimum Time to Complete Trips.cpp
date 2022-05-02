class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long a = 0, b = 100'000'000'000'000LL;
        auto calc = [&time, totalTrips](long long m)
        {
            long long trips = 0;
            for (long long x : time)
            {
                trips += m / x;
                if (trips >= totalTrips)
                    return true;
            }
            return false;
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
