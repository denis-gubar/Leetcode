class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int const N = ribbons.size();
        int a = 0, b = 1 << 30;
        auto calc = [&ribbons, k](int m)
            {
                long long total = 0;
                for (int x : ribbons)
                    total += x / m;
                return total >= k;
            };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m))
                a = m;
            else
                b = m;
        }
        return a;
    }
};
