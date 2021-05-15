class Solution {
public:
	int maximumPopulation(vector<vector<int>>& logs) {
		int result = 0;
		int count = 0;
		int best = 0;
		vector<int> M(2100);
		for (int i = 0; i < logs.size(); ++i)
			++M[logs[i][0]], --M[logs[i][1]];
		for(int i = 1900; i < 2100; ++i)
		{
			count += M[i];
			if (best < count)
				best = count, result = i;
		}
		return result;
	}
};