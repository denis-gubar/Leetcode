class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int N = nums.size();
		int a = 0, b = 0, countA = 0, countB = 0;
		for (int x : nums)
		{
			if (countA > 0 && a == x)
				++countA;
			else if (countB > 0 && b == x)
				++countB;
			else if (countA == 0)
				a = x, ++countA;
			else if (countB == 0)
				b = x, ++countB;
			else
				--countA, --countB;
		}
		int realCountA = 0, realCountB = 0;
		for (int x : nums)
		{
			if (countA > 0)
				realCountA += x == a;
			if (countB > 0)
				realCountB += x == b;
		}
		vector<int>	result;
		if (realCountA > N / 3)
			result.push_back(a);
		if (realCountB > N / 3)
			result.push_back(b);
		return result;
	}
};