class Solution {
public:
	int thirdMax(vector<int>& nums) {
		int M1 = *max_element(nums.begin(), nums.end());
		bool found = false;
		int M2 = M1;
		for (int n : nums)
			if (n != M1 && (!found || n > M2))
				M2 = n, found = true;
		int M3 = M1;
		found = false;
		for (int n : nums)
			if (n != M1 && n != M2 && (!found || n > M3))
				M3 = n, found = true;
		if (found)
			return M3;
		return M1;
	}
};