class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int count = 0;
        if (nums.size() > 1 && nums[0] > nums[1])
            ++count;            
		for (int i = 2; i < nums.size(); ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                ++count;
                if (nums[i] < nums[i - 2] && 
                    i + 1 != nums.size() &&
                   nums[i + 1] < nums[i - 1])
                    ++count;
            }
        }
		return count < 2;
	}
};