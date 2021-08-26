class Solution {
public:
	int maxArea(vector<int>& height) {
		int result = 0;
		int a = 0, b = height.size() - 1;
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