class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        points.resize(unique(points.begin(), points.end()) - points.begin());
        int const N = points.size();
        long long total = 0;
        for (int i = 0; i < N; ++i)
        {
            int& x = points[i][0];
            x += x;
            total += x;
        }
        if (total % N != 0)
            return false;
        int const X = total / N;        
        unordered_multiset<long long> S;
        auto hash = [](int x, int y) -> long long
            {
                return (x << 30LL) | y;
            };
        for (int i = 0; i < N; ++i)
        {
            int const& x = points[i][0];
            if (x == X)
                continue;
            int const& y = points[i][1];
            if (auto it = S.find(hash(2 * X - x, y)); it != S.end())
                S.erase(it);
            else
                S.insert(hash(x, y));
        }
        return S.empty();
    }
};
