class Solution {
public:
	void sortColors(vector<int>& nums) {
		int a = 0, b = nums.size() - 1;
        for(int i = 0; i <= b;)
		{
            if (nums[i] == 0)
            {
                swap(nums[i], nums[a]);
                ++i, ++a;
            }
            else if (nums[i] == 2)
            {
                swap(nums[i], nums[b]);
                --b;
            }
			else
                ++i;
		}
	}
};