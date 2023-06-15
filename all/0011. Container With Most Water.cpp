class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int a = 0, b = N - 1;
        int result = 0;
        while (a < b)
        {
            result = max(result, min(height[a], height[b]) * (b - a));
            if (height[a] < height[b])
                ++a;
            else
                --b;
        }
        return result;
    }
};
