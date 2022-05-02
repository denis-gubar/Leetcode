class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int>	result(digits);
		int pos = result.size() - 1;
		while (pos >= 0 && result[pos] == 9)
			result[pos] = 0, --pos;
		if (pos < 0)
			result.insert(result.begin(), 1);
		else
			++result[pos];
		return result;
	}
};