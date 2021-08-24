class Solution {
public:
	int minCut(string s) {
		int N = s.size();
		vector<int> F(N + 1, N + 1);
		F[0] = -1;
		for (int i = 0; i < 2 * N - 1; ++i)
			for(int R = 0; R <= i && i + R <= 2 * N - 1; ++R)
				if (s[(i - R) / 2] == s[(i + R + 1) / 2])
					F[(i + R + 1) / 2 + 1] = min(F[(i + R + 1) / 2 + 1], F[(i - R) / 2] + 1);
                else
                    break;
		return F[N];
	}
};