class Solution {
public:
	int balancedString(string s) {
		vector<vector<int>> counts;
		int N = s.size();
		string QWER{ "QWER" };
		counts.push_back({ 0, 0, 0, 0 });
		for (char c : s)
		{
			counts.push_back(counts.back());
			++counts.back()[QWER.find(c)];
		}
		vector<int> delta(4);
		for (int i = 0; i < 4; ++i)
			delta[i] = N / 4 - counts.back()[i];
		int A = -1, B = N;
		while (A + 1 < B)
		{
			int M = (A + B) / 2;
			vector<int> curDelta(4);
			bool flag = false;
			for (int x = 0; !flag && x + M <= N; ++x)
			{
				flag = true;
				for (int k = 0; k < 4; ++k)
					curDelta[k] = counts[x + M][k] - counts[x][k];
				for (int k = 0; k < 4; ++k)
					if (curDelta[k] + delta[k] < 0)
						flag = false;
			}
			if (flag)
				B = M;
			else
				A = M;
		}
		return B;
	}
};