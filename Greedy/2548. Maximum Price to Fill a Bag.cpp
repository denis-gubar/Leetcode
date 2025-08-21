class Solution {
public:
    double maxPrice(vector<vector<int>>& items, int capacity) {
        double result = 0;
        sort(items.begin(), items.end(), [](vector<int> const& a, vector<int> const& b)
            {
                return a[0] * b[1] < a[1] * b[0];
            });
        while (!items.empty())
        {
            int const& price = items.back()[0];
            int const& weight = items.back()[1];
            if (weight <= capacity)
                capacity -= weight, result += price;
            else
                result += 1.0 * capacity / weight * price, capacity = 0;
            items.pop_back();
            if (capacity == 0)
                return result;
        }
        return -1.0;
    }
};
