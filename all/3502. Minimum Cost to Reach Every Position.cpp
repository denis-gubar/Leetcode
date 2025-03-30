class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int const N = cost.size();
        vector<int> result(N, 1 << 20);
        int last = 1 << 20;
        for (int i = 0; i < N; ++i)
        {
            last = min(last, cost[i]);
            result[i] = last;
        }
        return result;
    }
};
