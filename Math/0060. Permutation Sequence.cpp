class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> F(10);
		F[0] = 1;
		for (int i = 1; i < 10; ++i)
			F[i] = F[i - 1] * i;
		string result;
		for (int t = n; t >= 1; --t)
		{
			int delta = (k - 1) / F[t - 1] + 1;
			int j = '1';
			while (result.find(j) != string::npos)
				++j;
			for (int z = 1; z < delta; ++z, ++j)
			{
				while (result.find(j) != string::npos)
					++j;
			}
			result += j;
			k = (k - 1) % F[t - 1] + 1;
		}
		return result;
	}
};