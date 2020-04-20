class Solution {
public:
	int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;        
		if (nums[0] == target) return 0;
		if (nums.back() == target) return nums.size() - 1;
		int a = 0, b = nums.size() - 1;
		while (a <= b)
		{
			int m = (a + b) / 2;
			if (nums[m] == target) return m;
			if (nums[m] >= nums[a]) 
            {
                if (target >= nums[a] && target < nums[m]) 
                    b = m - 1;
                else 
                    a = m + 1;
            } 
            else 
            {
                if (target <= nums[b] && target > nums[m])
                    a = m + 1;
                else 
                    b = m - 1;
            }
		}
		return -1;
	}
};