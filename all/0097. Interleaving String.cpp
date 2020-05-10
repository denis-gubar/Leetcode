class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int A = s1.size(), B = s2.size(), C = s3.size();
		if (A + B != C)
			return false;
		vector<vector<int>> F(2, vector<int>(B + 2));
		F[0][0] = 1;
		for (int i = 0; i <= A; ++i)
        {
            F[(i + 1) % 2].assign(B + 2, 0);
			for (int j = 0; j <= B; ++j)
				if (F[i % 2][j])
				{
					if (s1[i] == s3[i + j])
						F[(i + 1) % 2][j] = 1;
					if (s2[j] == s3[i + j])
						F[i % 2][j + 1] = 1;
				}
        }
		return F[A % 2][B];
	}
};