class Solution {
public:
	int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
		int result = 0;
		queue<int> q;
		for (int ib : initialBoxes)
			q.push(ib);
		vector<int> closed(status.size());
		vector<int> canBeOpened(status);
		while (!q.empty())
		{
			int box = q.front(); q.pop();
			if (canBeOpened[box])
			{
				result += candies[box];
				for (int key : keys[box])
					if (!canBeOpened[key])
					{
						canBeOpened[key] = 1;
						if (closed[key])
						{
							closed[key] = 0;
							q.push(key);
						}
					}
				for (int newBox : containedBoxes[box])
					q.push(newBox);
			}
			else
				closed[box] = 1;
		}
		return result;
	}
};