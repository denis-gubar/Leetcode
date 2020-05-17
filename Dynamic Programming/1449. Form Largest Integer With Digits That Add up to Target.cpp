class Solution {
public:
	string largestNumber(vector<int>& cost, int target) {
		vector<string> F(target + 1);
		for (string& f : F)
			f.reserve(5000);
		map<int, int> C;
		for (int d = 1; d <= 9; ++d)
			C[cost[d - 1]] = d;
		for (int d = 1; d <= 9; ++d)
			if (C[cost[d - 1]] != d)
				cost[d - 1] = 0;
		auto comp = [](char a, char b)
		{
			return a > b;
		};
		for (int i = 0; i < target; ++i)
			if (i == 0 || !F[i].empty())
			{
				for (int d = 9; d > 0; --d)
					if (cost[d - 1] && i + cost[d - 1] <= target)
					{
						if (F[i + cost[d - 1]].empty() || F[i + cost[d - 1]].size() <= F[i].size())
						{
							F[i + cost[d - 1]] = F[i];
							auto it = lower_bound(F[i + cost[d - 1]].begin(), F[i + cost[d - 1]].end(), d + '0', comp);
							F[i + cost[d - 1]].insert(it, d + '0');
						}
						else if (F[i + cost[d - 1]].size() == F[i].size() + 1)
						{
							string x = F[i];
							auto it = lower_bound(F[i].begin(), F[i].end(), d + '0', comp);
							F[i].insert(it, d + '0');
							if (F[i] > F[i + cost[d - 1]])
								F[i + cost[d - 1]] = F[i];
							F[i] = x;
						}
					}
			}
		if (F[target].empty())
			return "0";
		return F[target];
	}
};