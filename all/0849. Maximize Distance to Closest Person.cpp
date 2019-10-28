class Solution {
public:
	int maxDistToClosest(vector<int>& seats) {
		int result = 0;
		int N = seats.size(), a = -1, b = 0;
		while (b < N)
		{
			if (seats[b])
				result = max(result, a < 0 ? b : (b - a) / 2), a = b;
			++b;
		}
		result = max(result, b - a - 1);
		return result;
	}
};