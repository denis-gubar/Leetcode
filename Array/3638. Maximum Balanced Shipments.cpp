class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int const N = weight.size();
        int result = 0;
        int last = 0;
        for (int i = 0; i < N; ++i)
        {
            if (i > last && weight[i - 1] > weight[i])
                ++result, last = i + 1;
        }
        return result;
    }
};
