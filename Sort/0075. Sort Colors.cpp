class Solution {
public:
	void sortColors(vector<int>& nums) {
		int a = 0, b = nums.size() - 1;
		while (a < b)
		{
            if (a > 0 && nums[0] > nums[a])
                swap(nums[0], nums[a]);
            else if (b < nums.size() - 1 && nums.back() < nums[b])
                swap(nums[b], nums.back());
			else if (nums[a] == 0)
				++a;
			else if (nums[b] == 2)
				--b;
			else if (nums[a] > nums[b])
				swap(nums[a], nums[b]);
			else
                ++a;
		}
	}
};