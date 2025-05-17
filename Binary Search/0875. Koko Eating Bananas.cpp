class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int a = 0, b = 1 << 30;
        auto calc = [&piles, H](int k) -> bool
            {
                long long T = 0;
                for (int x : piles)
                    T += (x + k - 1) / k;
                return T <= H;
            };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m))
                b = m;
            else
                a = m;
        }
        return b;
    }
};
