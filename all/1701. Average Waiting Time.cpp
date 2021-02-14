class Solution {
public:
	double averageWaitingTime(vector<vector<int>>& customers) {
		int N = customers.size();
		long long waitTime = 0;
		int pos = customers[0][0];
		for (int i = 0; i < N; ++i)
		{
			if (customers[i][0] >= pos)
			{
				pos = customers[i][0] + customers[i][1];
				waitTime += customers[i][1];
			}
			else
			{
                waitTime += (pos - customers[i][0]) + customers[i][1];
				pos += customers[i][1];				
			}
		}
		return 1.0 * waitTime / N;
	}
};