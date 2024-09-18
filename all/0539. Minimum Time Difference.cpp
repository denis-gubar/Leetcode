class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		auto parse = [](string const& s)
		{
			int result = 0;
			result += (s[0] - '0') * 600;
			result += (s[1] - '0') * 60;
			result += (s[3] - '0') * 10;
			result += (s[4] - '0');
			return result;
		};
		int result = 1440;
		vector<int>	A;
        A.reserve(timePoints.size() + 1);
		for (string const& t : timePoints)
			A.push_back(parse(t));
		sort(A.begin(), A.end());
		A.push_back(A[0]);
		for (int i = 1; i < A.size(); ++i)
		{
			result = min(result, (1440 + A[i] - A[i - 1]) % 1440);
			result = min(result, (1440 + A[i - 1] - A[i]) % 1440);
		}
		return result;
	}
};