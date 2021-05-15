class Solution {
public:
	vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
		set<int> S;		
		vector<pair<int, pair<int, int>>> Q;
		for (int i = 0; i < queries.size(); ++i)
		{
			int const& preferred = queries[i][0];
			int const& minSize = queries[i][1];
			Q.push_back({ minSize, {preferred, i} });
		}
		sort(Q.begin(), Q.end());
		vector<int>	result(Q.size(), -1);
		sort(rooms.begin(), rooms.end(), [](vector<int>& a, vector<int>& b)
			{
				return a[1] > b[1];
			});
        for(int i = 0; i < rooms.size(); ++i)
            S.insert(rooms[i][0]);
		for (auto& x : Q)
		{
			int const& minSize = x.first;
			int const& preferred = x.second.first;
			int const& queryId = x.second.second;
			while (!rooms.empty() && rooms.back()[1] < minSize)
            {
				S.erase(rooms.back()[0]);
                rooms.pop_back();
            }
			auto it = S.lower_bound(preferred);
			if (it != S.end())
			{
				result[queryId] = *it;
				if (it != S.begin())
				{
					--it;
					if (preferred - *it <= result[queryId] - preferred)
						result[queryId] = *it;
				}
			}
            else if (it != S.begin())
            {
                --it;
                result[queryId] = *it;
            }
		}
		return result;
	}
};