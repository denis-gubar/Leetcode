class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int N = candies.size();
        long long a = 0, b = 1'000'000'000'001LL;
        auto calc = [k, N, &candies](int m)
        {
            long long piles = 0;
            for (long long x : candies)
                piles += x / m;
            return piles >= k;
        };
        while (a + 1 < b)
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
