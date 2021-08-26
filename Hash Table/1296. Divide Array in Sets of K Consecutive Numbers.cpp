class Solution {
public:
	bool isPossibleDivide(vector<int>& nums, int k) {
		if (nums.size() % k != 0) return false;
		map<int, int> M;
		for (int n : nums)
			++M[n];
		for (int group = 0; group < nums.size() / k; ++group)
		{
			int count = 0, start = M.begin()->first;
			for (auto& m : M)
			{
				if (start + count != m.first)
					return false;
				++count;
				if (count == k)
					break;
			}
			for (int i = 0; i < k; ++i)
				if (--M[start + i] == 0)
					M.erase(start + i);
		}
		return true;
	}
};