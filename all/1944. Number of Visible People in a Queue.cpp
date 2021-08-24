class Solution {
public:
	vector<int> canSeePersonsCount(vector<int>& heights) {
		int N = heights.size();
		vector<int> result(N);
		vector<int> S;
		for (int i = N - 1; i >= 0; --i)
		{
			int sum = 0;
			while (!S.empty() && S.back() <= heights[i])
			{
				++sum;
				S.pop_back();
			}
			result[i] = sum + !S.empty();
			S.push_back(heights[i]);
		}
		return result;
	}
};