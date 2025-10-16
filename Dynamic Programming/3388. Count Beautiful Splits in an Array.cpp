class Solution {
public:
	int beautifulSplits(vector<int>& nums) {
		int result = 0;
		int const N = nums.size();
		string s;
		s.reserve(N);
		for (int x : nums)
			s += 'A' + x;
		for(int length = 1; length * 2 < N; ++length)
			for (int start = 0; start + 2 * length <= N; ++start)
				if (equal(s.begin() + start, s.begin() + start + length, s.begin() + start + length, s.begin() + start + 2 * length))
				{
					if (start == 0)
						result += N - 2 * length;
					else
					{
						if (start > length || (start * 2 < N && !equal(s.begin(), s.begin() + start, s.begin() + start, s.begin() + 2 * start)))
							++result;
					}
				}
		return result;
    }
};
