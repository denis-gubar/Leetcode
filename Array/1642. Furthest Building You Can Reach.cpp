class Solution {
public:
	int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
		int a = min(ladders, static_cast<int>(heights.size()) - 1), b = heights.size();
		vector<int> A;
		for (int i = 1; i < heights.size(); ++i)
			A.push_back(max(0, heights[i] - heights[i - 1]));
		while (a + 1 < b)
		{
			int x = (a + b) / 2;
			int z = x - ladders;
			vector<int> B(A.begin(), A.begin() + x);
			sort(B.begin(), B.end());
			int sum = 0;
			for (int k = 0; k < z; ++k)
			{
				sum += B[k];
				if (sum > bricks)
					break;
			}
			if (sum <= bricks)
				a = x;
			else
				b = x;
		}
		return a;
	}
};