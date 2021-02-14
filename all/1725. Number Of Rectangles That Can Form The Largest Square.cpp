class Solution {
public:
	int countGoodRectangles(vector<vector<int>>& rectangles) {
		int result = 0;
		int L = 0;
		for (int i = 0; i < rectangles.size(); ++i)
			L = max( L, min(rectangles[i][0], rectangles[i][1]) );
		for (int i = 0; i < rectangles.size(); ++i)
			result += L == min(rectangles[i][0], rectangles[i][1]);
		return result;
	}
};