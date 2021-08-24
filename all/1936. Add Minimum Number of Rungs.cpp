class Solution {
public:
	int addRungs(vector<int>& rungs, int dist) {
		int result = 0;
		int N = rungs.size();
		int prev = 0;
		for (int i = 0; i < N; ++i)
		{
			result += (rungs[i] - prev + dist - 1) / dist - 1;
			prev = rungs[i];
		}
		return result;
	}
};