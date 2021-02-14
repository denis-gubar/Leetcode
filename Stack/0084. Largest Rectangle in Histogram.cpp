class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int N = heights.size();
		stack<int> S;
        S.push(-1);
		int result = 0;
		for (int i = 0; i < N; ++i)
		{
			while (S.top() >= 0 && heights[i] <= heights[S.top()])
			{
                int height = heights[S.top()];
                S.pop();
                int width = i - S.top() - 1;
				result = max(result, height * width);
			}
			S.push(i);
		}
        while (S.top() >= 0)
        {
            int height = heights[S.top()];
            S.pop();
            int width = N - S.top() - 1;
            result = max(result, height * width);
        }
		return result;
	}
};