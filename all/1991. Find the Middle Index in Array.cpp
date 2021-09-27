class Solution {
public:
	int findMiddleIndex(vector<int>& nums) {
		int total = accumulate(nums.begin(), nums.end(), 0);
		int left = 0, right = total;
		for (int pos = 0; pos < nums.size(); ++pos)
		{
            if (pos)
			    left += nums[pos - 1];
            right -= nums[pos];
			if (left == right)
				return pos;
		}
		return -1;
	}
};