class Solution {
public:
	bool isMajorityElement(vector<int>& nums, int target) {
        int N = nums.size();
		int balance = -N;
		for (int x : nums)
			balance += (x == target) << 1;
		return balance > 0;
	}
};