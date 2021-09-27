class Solution {
public:
	int finalValueAfterOperations(vector<string>& operations) {
		int result = 0;
		for (string const& s : operations)
			if (s[1] == '+')
				++result;
			else
				--result;
		return result;
	}
};