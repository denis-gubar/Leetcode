class Solution {
public:
	int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		long long H = 0, V = 0;
		int const MOD = 1'000'000'007;
		int prevH = 0, prevV = 0;
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
		sort(horizontalCuts.begin(), horizontalCuts.end());
		sort(verticalCuts.begin(), verticalCuts.end());
		for (int i = 0; i < horizontalCuts.size(); ++i)
		{
			long long deltaH = horizontalCuts[i] - prevH;
			prevH = horizontalCuts[i];
            H = max(H, deltaH);
		}
        for (int j = 0; j < verticalCuts.size(); ++j)
        {
            long long deltaV = verticalCuts[j] - prevV;
            prevV = verticalCuts[j];
            V = max(V, deltaV);            
        }
		return H * V % MOD;
	}
};