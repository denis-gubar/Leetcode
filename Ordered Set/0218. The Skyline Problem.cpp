class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		vector<vector<int>> result;
		int swipe_line = -1, height = 0;
		multiset<pair<int, int>> S;
		multiset<int> H;
		for (int i = 0; i < buildings.size(); ++i)
		{
			while (!S.empty() && S.begin()->first < buildings[i][0])
			{
				int swipe_line = S.begin()->first;
				while (!S.empty() && S.begin()->first == swipe_line)
				{
					H.erase(H.find(S.begin()->second));
					S.erase(S.begin());
				}
				int newHeight = 0;
				if (!H.empty())
					newHeight = *H.rbegin();
				if (height != newHeight)
				{
					height = newHeight;
					result.push_back({ swipe_line, height});
				}
			}
			int swipe_line = buildings[i][0];
			while (true)
			{
				H.insert(buildings[i][2]);
				S.insert({ buildings[i][1], buildings[i][2] });
				if (i + 1 < buildings.size() && buildings[i + 1][0] == swipe_line)
					++i;
				else
					break;
			}
			int newHeight = 0;
			if (!H.empty())
				newHeight = *H.rbegin();
			if (height != newHeight)
			{
				height = newHeight;
				result.push_back({ swipe_line, height });
			}
		}
		while (!S.empty())
		{
			int swipe_line = S.begin()->first;
			while (!S.empty() && S.begin()->first == swipe_line)
			{
				H.erase(H.find(S.begin()->second));
				S.erase(S.begin());
			}
			int newHeight = 0;
			if (!H.empty())
				newHeight = *H.rbegin();
			if (height != newHeight)
			{
				height = newHeight;
				result.push_back({ swipe_line, height });
			}
		}
		return result;
	}
};