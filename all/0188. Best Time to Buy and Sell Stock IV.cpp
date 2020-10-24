class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (k == 0) return 0;
		int INF = 1'000'000'000;
		vector<int>	F{ -INF, 0 };
		for (int p : prices)
		{
			vector<int>	NF(F);
			int FSize = F.size();
			if (FSize < 2 * k)
			{
				F.push_back(max(-INF, F[FSize - 1] - p));
				F.push_back(max(0, F[FSize - 2] + p));
			}
			for (int i = FSize - 2; i >= 0; i -= 2)
			{
				F[i + 1] = max(F[i + 1], F[i] + p);
				F[i] = max(F[i], (i > 0 ? F[i - 1] : 0) - p);
			}
            if (F.size() > FSize && F[FSize - 1] == F[FSize + 1])
            {
                F.pop_back();
                F.pop_back();
            }
		}
		int result = 0;
		for (int i = 1; i < F.size(); i += 2)
			result = max(result, F[i]);
		return result;
	}
};