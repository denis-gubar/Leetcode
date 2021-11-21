class Solution {
public:
	vector<int> findBuildings(vector<int>& heights) {
		vector<int> result;
		int N = heights.size();
		int last = heights.back() - 1;
		for (int i = N - 1; i >= 0; --i)
			if (heights[i] > last)
			{
				result.push_back(i);
				last = heights[i];
			}
		reverse(result.begin(), result.end());
		return result;
	}
};