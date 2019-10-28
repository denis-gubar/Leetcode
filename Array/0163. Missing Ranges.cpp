class Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> result;
		for (int n : nums)
		{
			if (n == lower + 1LL)
				result.push_back({ to_string(lower) });
			else if (n > lower)
				result.push_back(to_string(lower) + "->" + to_string(n - 1));
            if (n == upper)
                return result;
			lower = n + 1LL;
		}
		if (lower == upper)
			result.push_back({ to_string(lower) });
		else if (lower < upper)
			result.push_back({ to_string(lower) + "->" + to_string(upper) });
		return result;
	}
};