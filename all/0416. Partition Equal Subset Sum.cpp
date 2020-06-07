class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int amount = accumulate(nums.begin(), nums.end(), 0);
		if (amount % 2) return false;
		amount >>= 1;
        bitset<20001> F;
		F[0] = true;
		for (int n: nums)
			F |= F << n;
        return F[amount];
	}
};