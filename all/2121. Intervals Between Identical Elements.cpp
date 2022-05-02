class Solution {
public:
	vector<long long> getDistances(vector<int>& arr) {
		int N = arr.size();
		vector<long long> result(N);
		vector<vector<int>> M(100'001);
		for (int i = 0; i < N; ++i)
			M[arr[i]].push_back(i);
		for(int i = 1; i <= 100'000; ++i)
			if (M[i].size() > 1)
			{
				long long total = 0;
				int Z = M[i].size();
				for (int j = 1; j < Z; ++j)
					total += M[i][j] - M[i][0];
				result[M[i][0]] = total;
				long long left = 0;
				for (int j = 1; j < Z; ++j)
				{
					long long delta = M[i][j] - M[i][j - 1];
					total += -delta * (Z - j) + j * delta;
					result[M[i][j]] = total;
				}
			}
		return result;
	}
};