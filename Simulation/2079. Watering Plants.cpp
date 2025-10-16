class Solution {
public:
	int wateringPlants(vector<int>& plants, int capacity) {
		int result = 0;
		int N = plants.size();
		int x = capacity;
		int pos = -1;
		for (int i = 0; i < N; ++i)
		{
			if (x < plants[i])
			{
				result += pos + 1;
				pos = -1;
				x = capacity;
			}
			result += i - pos;
			pos = i;
			x -= plants[i];
		}
		return result;
	}
};