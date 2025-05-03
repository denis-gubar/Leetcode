class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int amount = accumulate(nums.begin(), nums.end(), 0);
		if (amount % 2) return false;
		amount >>= 1;
        int N = nums.size();
        bitset<20001> F;
		F[0] = true;
		for (int j = 0; j < N; ++j)
			for (int i = amount - nums[j]; i >= 0; --i)
				F[i + nums[j]] = F[i + nums[j]] || F[i];
        return F[amount];
	}
};