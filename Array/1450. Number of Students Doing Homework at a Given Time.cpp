class Solution {
public:
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		int result = 0;
		vector<int> Time(1002);
		for (int s : startTime)
			++Time[s];
		for (int e : endTime)
			--Time[e + 1];
		for (int k = 0; k <= queryTime; ++k)
			result += Time[k];
		return result;
	}
};