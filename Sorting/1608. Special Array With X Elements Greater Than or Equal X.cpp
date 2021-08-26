class Solution {
public:
	int specialArray(vector<int>& nums) {
		int result = -1;
		for (int x = 1; x <= nums.size(); ++x)
		{
			int count = 0;
			for (int n : nums)
				count += n >= x;
			if (count == x)
				result = x;
		}
		return result;
	}
};