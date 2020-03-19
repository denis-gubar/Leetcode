class Solution {
public:
	vector<int> numOfBurgers(long long tomatoSlices, long long cheeseSlices) {
		if (cheeseSlices * 2 > tomatoSlices || cheeseSlices * 4 < tomatoSlices) return {};
		long long a = -1, b = cheeseSlices + 1;
		while (a + 1 < b)
		{
			long long x = (a + b) / 2;
			long long F = 2 * x + 4 * (cheeseSlices - x);
			if (F == tomatoSlices) return { static_cast<int>(cheeseSlices - x), static_cast<int>(x) };
			if (F > tomatoSlices)
				a = x;
			else
				b = x;
		}
		return {};
	}
};