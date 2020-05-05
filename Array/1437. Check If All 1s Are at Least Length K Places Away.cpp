class Solution {
public:
	bool kLengthApart(vector<int>& nums, int k) {
		int count = k;
		for (int n : nums)
			if (!n)
				++count;
			else
			{
				if (count < k)
					return false;
				count = 0;
			}
		return true;
	}
};