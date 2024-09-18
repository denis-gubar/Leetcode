class Solution {
public:
	vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
		vector<pair<int, int>> A;
        A.reserve(2 * (slots1.size() + slots2.size()));
		for (auto& x : slots1)
		{
			A.push_back({ x[0], 1 });
			A.push_back({ x[1], -1 });
		}
		for (auto& x : slots2)
		{
			A.push_back({ x[0], 1 });
			A.push_back({ x[1], -1 });
		}
		sort(A.begin(), A.end());
		int balance = 0;
		bool flag = false;
		int start = 0;
		for (auto& p : A)
		{
			balance += p.second;
			if (balance == 2)
			{
				start = p.first;
				flag = true;
			}
			else if (balance == 1)
			{
				if (flag)
				{
					if (p.first - start >= duration)
						return { start, start + duration };
					flag = false;
				}
			}
		}
		return {};
	}
};