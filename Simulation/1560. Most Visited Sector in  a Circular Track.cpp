class Solution {
public:
	vector<int> mostVisited(int n, vector<int>& rounds) {
		vector<int>	result;
		vector<int>	F(n + 1);
		int pos = rounds[0];
		for (int i = 1; i < rounds.size(); ++i)
		{
			while (pos != rounds[i])
				++F[pos], pos = pos % n + 1;
		}
        ++F[pos];
		int x = *max_element(F.begin(), F.end());
		for (int i = 1; i <= n; ++i)
			if (F[i] == x)
				result.push_back(i);
		return result;
	}
};