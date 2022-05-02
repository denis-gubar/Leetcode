class Solution {
public:
	int maximumRequests(int n, vector<vector<int>>& requests) {
		int result = 0;
		int N = requests.size();
		vector<int>	goodBalance(n);
		for (int x = 1; x < (1 << N); ++x)
		{
			vector<int>	balance(n);
			int current = 0;
			for(int k = 0; k < N; ++k)
				if (x & (1 << k))
				{
					--balance[requests[k][0]];
					++balance[requests[k][1]];
					++current;
				}
			if (current > result && balance == goodBalance)
				result = current;
		}
		return result;
	}
};