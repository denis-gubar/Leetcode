class Solution {
public:
	long long decode(string s)
	{
		long long result = 0;
		long long power = 1;
		while (!s.empty())
		{
			result += power * (s.back() - '0');
			power += power;
            s.pop_back();
		}
		return result;
	}
	string findDifferentBinaryString(vector<string>& nums) {
		string result;
		int N = nums[0].size();
		unordered_set<long long> A;
		for (string const& s : nums)
			A.insert(decode(s));
		for (long long mask = 0; mask < (1 << N); ++mask)
			if (A.find(mask) == A.end())
			{
				for (int k = 0; k < N; ++k)
					if (mask & (1 << k))
						result += '1';
					else
						result += '0';
				reverse(result.begin(), result.end());
				break;
			}
		return result;
	}
};