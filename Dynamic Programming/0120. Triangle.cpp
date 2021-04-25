class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {		
		vector<int> F{ triangle[0][0] };
		for (int i = 1; i < triangle.size(); ++i)
		{
			vector<int> NF(i + 1);
			for (int j = 0; j <= i; ++j)
				NF[j] = min(j < i ? F[j] : 1 << 30, j > 0 ? F[j - 1] : 1 << 30) + triangle[i][j];
			F = move(NF);
		}
		return *min_element(F.begin(), F.end());
	}
};