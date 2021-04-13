class Solution {
public:
	vector<int> constructArray(int n, int k) {
		vector<int> result{ 1 };
		vector<int>	M{ 2, n };
		int pos = 1;
		for (int i = 1; i < k; ++i, pos = 1 - pos)
		{
			result.push_back(M[pos]);
			if (pos == 0)
				++M[pos];
			else
				--M[pos];
		}
		int& x = M[1 - pos];
		while (result.size() < n)
		{
			result.push_back(x);
			if (pos == 0)
				--x;
			else
				++x;
		}
		return result;
	}
};