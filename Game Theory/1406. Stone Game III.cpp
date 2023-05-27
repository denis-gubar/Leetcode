static int F[50'003];
class Solution {
public:
	string stoneGameIII(vector<int>& stoneValue) {
		int N = stoneValue.size();
		stoneValue.push_back(0);
		stoneValue.push_back(0);
		stoneValue.push_back(0);
		F[N] = F[N + 1] = F[N + 2] = 0;
		for (int i = N - 1; i >= 0; --i)
		{
			F[i] = max({ -F[i + 1] + stoneValue[i],
				-F[i + 2] + stoneValue[i] + stoneValue[i + 1],
				-F[i + 3] + stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] });
		}
		if (F[0] == 0)
			return "Tie";
		if (F[0] > 0)
			return "Alice";
		return "Bob";
	}
};