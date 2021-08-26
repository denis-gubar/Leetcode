class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> result;
		int N = nums.size();
		for (int i = 0; i < N; ++i)
		{
			int x = nums[i];
			while (x > 0)
			{
                int nx = nums[x - 1];
                if (nx > 0)
				    nums[x - 1] = -nx;
				x = nx;
			}
		}
		for (int i = 0; i < N; ++i)
			if (nums[i] > 0)
				result.push_back(i + 1);
		return result;
	}
};