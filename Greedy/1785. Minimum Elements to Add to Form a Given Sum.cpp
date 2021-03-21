class Solution {
public:
	int minElements(vector<int>& nums, int limit, int goal) {		
		long long total = accumulate(nums.begin(), nums.end(), 0LL);
		long long delta = abs(goal - total);
		int result = (delta + limit - 1) / limit;
		return result;
	}
};