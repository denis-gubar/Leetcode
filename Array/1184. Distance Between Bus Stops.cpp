class Solution {
public:
	int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
		int result1 = 0, result2 = 0;
		int N = distance.size();
		for (int x = start; x != destination; x = (x + 1) % N)
			result1 += distance[x];
		for (int x = destination; x != start; x = (x + 1) % N)
			result2 += distance[x];
		return min(result1, result2);
	}
};