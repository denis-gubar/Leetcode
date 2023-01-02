class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int N = price.size();
        sort(price.begin(), price.end());
        int a = 0, b = price.back();
        auto check = [&price, k](int m)
        {
            int pos = 0;
            for (int i = 1; i < k; ++i)
            {
                auto it = lower_bound(price.begin(), price.end(), price[pos] + m);
                if (it == price.end())
                    return false;
                pos = it - price.begin();
            }
            return true;
        };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (check(m))
                a = m;
            else
                b = m;
        }
        return a;
    }
};
