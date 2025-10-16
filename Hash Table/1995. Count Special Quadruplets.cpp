class Solution {
public:
	int countQuadruplets(vector<int>& nums) {
		int result = 0;
		int N = nums.size();
		for (int a = 0; a < N; ++a)
			for (int b = a + 1; b < N; ++b)
				for (int c = b + 1; c < N; ++c)
					for (int d = c + 1; d < N; ++d)
						if (nums[a] + nums[b] + nums[c] == nums[d])
							++result;
		return result;
	}
};