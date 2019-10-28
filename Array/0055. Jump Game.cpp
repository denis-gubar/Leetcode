class Solution {
public:
	bool canJump(vector<int>& nums) {
		int leftMoves = 1;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (!leftMoves)
				return false;
			leftMoves = max(leftMoves - 1, nums[i]);
		}
		return true;
	}
};