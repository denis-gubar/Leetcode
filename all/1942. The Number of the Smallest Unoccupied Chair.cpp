class Solution {
public:
	int smallestChair(vector<vector<int>>& times, int targetFriend) {
		int result = 0;
		int N = times.size();
		int const A = 1'000'000;
		set<int> free;
		for (int i = 0; i <= N; ++i)
			free.insert(i);
		set<pair<int, int>> P;
		for (int i = 0; i < N; ++i)
			P.insert({ times[i][0], i });
		while (!P.empty())
		{
			if (P.begin()->second >= 0)
			{
				auto x = *P.begin();
				P.erase(P.begin());
				const int i = x.second;
				int seat = *free.begin();
				if (i == targetFriend)
					return seat;
				free.erase(free.begin());
				P.insert({ times[i][1], seat - A });
			}
			else
			{
				auto x = *P.begin();
				P.erase(P.begin());
				int seat = x.second + A;
				free.insert(seat);
			}
		}
		return -1;
	}
};