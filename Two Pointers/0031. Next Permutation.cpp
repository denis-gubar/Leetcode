class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int N = nums.size();
		if (N < 2) return;
		int pos = N - 2;
		while (pos >= 0 && nums[pos] >= nums[pos + 1])
			--pos;
		if (pos >= 0)
		{
            int bestPos = N - 1;
            while(bestPos >= 0 && nums[bestPos] <= nums[pos])
                --bestPos;
            swap(nums[pos], nums[bestPos]);
        }
		reverse(nums.begin() + pos + 1, nums.end());
	}
};