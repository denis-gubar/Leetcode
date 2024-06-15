class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int result = 0;
        int N = points.size();
        auto f = [&points](int i)
            {
                return max(abs(points[i][0]), abs(points[i][1]));
            };
        vector<int> I(N);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&f](int a, int b)
            {
                return f(a) < f(b);
            });
        unordered_set<char> S;
        for (int i = 0; i < N; )
        {
            int j = i;
            while (j + 1 < N && f(I[j + 1]) == f(I[i]))
                ++j;
            for (int k = i; k <= j; ++k)
                if (!S.insert(s[I[k]]).second)
                    return result;
            i = j + 1;
            result = i;
        }
        return result;
    }
};
