class Solution {
public:
	string removeOccurrences(string s, string part) {
		string result;
		int P = part.size();
		for (char c : s)
		{
			result += c;
			int N = result.size();
			if (N >= P)
			{
				if (equal(result.begin() + (N - P), result.end(), part.begin(), part.end()))
					result.resize(N - P);
			}
		}
		return result;
	}
};