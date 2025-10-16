class Solution {
public:
    int minTime(string, vector<int>& order, int K) {
        int result = 0;
        int const N = order.size();
        long long total = 0;
        set<int> S;
        S.insert(-1);
        S.insert(N);
        for (int i = 0; i < N; ++i)
        {
            int const& x = order[i];
            auto it = S.lower_bound(x);
            int const L = *prev(it);
            int const R = *it;
            S.insert(x);
            total += 1LL * (x - L) * (R - x);
            if (total >= K)
                return i;
        }
        return -1;
    }
};
