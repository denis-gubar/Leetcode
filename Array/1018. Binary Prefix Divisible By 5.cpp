class Solution {
public:
	vector<bool> prefixesDivBy5(vector<int>& A) {
		vector<bool> result;
		int x = 0;
		for (int a : A)
		{
			x += x + a;
			x %= 5;
			result.push_back(x == 0);
		}
		return result;
	}
};