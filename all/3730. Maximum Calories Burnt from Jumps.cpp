class Solution {
public:
    long long maxCaloriesBurnt(vector<int>& heights) {
        long long result = 0;
        int prev = 0;
        int const N = heights.size();
        sort(heights.begin(), heights.end());
        for (int a = 0, b = N - 1; a <= b; ++a, --b)
        {
            result += 1LL * (prev - heights[b]) * (prev - heights[b]);
            prev = heights[b];
            if (a == b)
                break;
            result += 1LL * (prev - heights[a]) * (prev - heights[a]);
            prev = heights[a];
        }
        return result;
    }
};
