class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int a = 0, b = 1 << 30;
        auto calc = [&position, m](int threshold)
            {
                int count = 0;
                for (auto it = position.begin(); it != position.end() && count < m; it = lower_bound(it, position.end(), *it + threshold))
                    ++count;
                return count == m;
            };
        while (a + 1 < b)
        {
            int mid = (a + b) / 2;
            if (calc(mid))
                a = mid;
            else
                b = mid;
        }
        return a;
    }
};
