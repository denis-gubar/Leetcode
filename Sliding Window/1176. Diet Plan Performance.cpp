class Solution {
public:
	int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
		int result = 0;
		int sum = 0;
		for (int i = 0; i < k; ++i)
			sum += calories[i];
		if (sum < lower)
			--result;
		if (sum > upper)
			++result;
		for (int i = k; i < calories.size(); ++i)
		{
			sum += calories[i];
			sum -= calories[i - k];
			if (sum < lower)
				--result;
			if (sum > upper)
				++result;
		}
		return result;
	}
};