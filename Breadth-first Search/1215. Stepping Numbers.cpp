class Solution {
public:
	void calc(long long prefix, int low, int high, vector<int>& result)
	{
		long long next = prefix % 10 + 1;
		if (next < 10)
		{
			next += prefix * 10;
			if (next >= low && next <= high)
				result.push_back(next);
			if (next < high)
				calc(next, low, high, result);
		}
		next = prefix % 10 - 1;
		if (next >= 0)
		{
			next += prefix * 10;
			if (next >= low && next <= high)
				result.push_back(next);
			if (next < high)
				calc(next, low, high, result);
		}
	}
	vector<int> countSteppingNumbers(int low, int high) {
		vector<int> result;
		if (low == 0)
			result.push_back(0);
		for (int i = 1; i < 10; ++i)
		{
			if (i >= low && i <= high)
				result.push_back(i);
			if (i < high)
				calc(i, low, high, result);
		}
		sort(result.begin(), result.end());
		return result;
	}
};