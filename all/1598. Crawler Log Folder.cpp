class Solution {
public:
	int minOperations(vector<string>& logs) {
		int result = 0;
		for (string const& s : logs)
			if (s[0] == '.')
			{
				if (s[1] == '.')
					result = max(0, result - 1);
			}
			else
				++result;
		return result;
	}
};