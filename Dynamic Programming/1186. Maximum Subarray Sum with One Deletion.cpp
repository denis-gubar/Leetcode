class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int const INF = 1 << 30;
        int d0 = -INF, d1 = -INF;
        int result = -INF;
        for (int x : arr)
        {
            int nd0 = max(d0 + x, x);
            int nd1 = max(d1 + x, d0);
            d0 = nd0, d1 = nd1;
            result = max({ result, d0, d1 });
        }
        return result;
    }
};
