/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
	vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
		vector<vector<int>> result;
		int lastY = 1001;
		for (int x = 1; x <= 1000; ++x)
			for (int y = 1; y < lastY; ++y)
			{
				int F = customfunction.f(x, y);
				if (F > z)
					break;
				if (F == z)
				{
					result.push_back({ x, y });
					lastY = y;
				}
			}		
		return result;
	}
};