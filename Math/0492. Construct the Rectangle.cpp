class Solution {
public:
	vector<int> constructRectangle(int area) {
		for (int x = sqrt(area) + 0.5; x >= 1; --x)
		{
			if (area % x == 0)
				return { area / x, x };
		}			
		return {};
	}
};