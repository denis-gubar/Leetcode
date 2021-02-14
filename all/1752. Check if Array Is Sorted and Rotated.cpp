class Solution {
public:
	bool check(vector<int>& nums) {		
		int N = nums.size();
		for (int i = 0; i < N; ++i)
		{
			if (is_sorted(nums.begin(), nums.end()))
				return true;
			rotate(nums.begin(), nums.begin() + 1, nums.end());
		}
		return false;
	}
};