class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int result = 0;
		int N = gas.size();
		int sum = 0, best = numeric_limits<int>::max();
		for (int i = 0; i < N; ++i)
		{
			sum += gas[i] - cost[i];
			if (sum < best)
				result = i + 1, best = sum;
		}
		if (sum < 0)
			return -1;
		return result % N;
	}
};