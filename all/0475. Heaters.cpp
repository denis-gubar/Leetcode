class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		if (heaters.size() == 0 || houses.size() == 0)
			return 0;
		vector<int> h(heaters);
		sort(h.begin(), h.end());
		vector<int> results;
		for (int i = 0; i < houses.size(); ++i)
		{
			int dist = -1;
			vector<int>::iterator it = lower_bound(h.begin(), h.end(), houses[i]);
			if (it == h.end())
			{
				--it;
				dist = abs(*it - houses[i]);
			}
			else if (it == h.begin())
			{
				dist = abs(h[0] - houses[i]);
			}
			else
			{
				dist = min(abs(*it - houses[i]), abs(*(it - 1) - houses[i]));
			}
			results.push_back(dist);
		}
		return *max_element(results.begin(), results.end());
	}
};