class Solution {
public:
	int minStartValue(vector<int>& nums) {
		for (int i = 1; i <= 100000; ++i)
		{
			int s = i;
			bool f = true;
			for(int n: nums)
				if ((s += n) < 1)
				{
					f = false;
					break;
				}
			if (f) return i;
		}
		return 0;
	}
};