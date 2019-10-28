class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		auto it = max_element(nums.begin(), nums.end());
		int pos = it - nums.begin();
		int val = *it;
		if (all_of(nums.begin(), nums.end(), [val](int x)->bool
		{
			return x * 2 <= val || x == val;
		}))
			return pos;
		return -1;
	}
};