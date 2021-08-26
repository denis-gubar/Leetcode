class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		if (nums.size() < 3)
			return false;
		int a = numeric_limits<int>::max();
		int b = numeric_limits<int>::max();
		for (int n : nums)
		{
			if (n < a)
				a = n;
			else if (n > a && n < b)
				b = n;
			else if (n > b)
				return true;
		}
		return false;
	}
};