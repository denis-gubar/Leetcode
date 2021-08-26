class Solution {
public:
	string orderlyQueue(string S, int K) {
		string result{ S };
		if (K > 1)
			sort(result.begin(), result.end());
		else
		{
			string s{ S };
			for (int i = 0; i < S.size(); ++i)
			{
				result = min(result, s);
				rotate(s.begin(), s.begin() + 1, s.end());
			}
		}
		return result;
	}
};