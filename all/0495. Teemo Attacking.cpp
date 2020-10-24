class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		int result = 0;
		int last = -1;
		for (int x : timeSeries)
		{
			result += min(duration, x + duration - last);
			last = x + duration;
		}
		return result;
	}
};