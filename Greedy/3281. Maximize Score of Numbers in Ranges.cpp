class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        int const N = start.size();
        sort(start.begin(), start.end());
        if (N == 2)
            return start[1] - start[0] + d;
        int a = 0, b = start.back() - start[0] + d + 1;
        auto calc = [&start, N, d](int m) -> bool
            {
                int x = start[0];
                for (int i = 1; i < N; ++i)
                {
                    if (0LL + x + m > start[i] + d)
                        return false;
                    x = max(x + m, start[i]);
                }
                return true;
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
