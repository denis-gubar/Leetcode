class Solution {
public:
	int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
		int result = 0;
		int sum = accumulate(calories.begin(), calories.begin() + k, 0);
		if (sum < lower)
			--result;
		if (sum > upper)
			++result;
		for (int i = k; i < calories.size(); ++i)
		{
			sum += calories[i] - calories[i - k];
			if (sum < lower)
				--result;
			if (sum > upper)
				++result;
		}
		return result;
	}
};