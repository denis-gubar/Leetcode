class Solution {
public:
	int calc(vector<int> const& nums, int pos)
	{
		int result = pos + 1;
		while (result < nums.size() && nums[result - 1] < nums[result])
			++result;
		return result - 1;
	}
	bool canBeIncreasing(vector<int>& nums) {
		int N = nums.size();
		int x = calc(nums, 0);
		if (x == N - 1)
			return true;
        vector<int> A(nums);
        A.erase(A.begin() + x);            
        if (calc(A, 0) == N - 2)
            return true;
		A = nums;
		A.erase(A.begin() + x + 1);
		if (calc(A, 0) == N - 2)
			return true;
		return false;
	}
};