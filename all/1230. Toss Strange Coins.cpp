class Solution {
public:
	double probabilityOfHeads(vector<double>& prob, int target) {
		int N = prob.size();
		vector<double> F(N + 1);
		F[0] = 1;
		for (int i = 1; i <= N; ++i)
		{
			vector<double> NF(N + 1);
			for (int j = 0; j < i; ++j)
				NF[j] = F[j] * (1.0 - prob[i - 1]);
			for (int j = 1; j <= i; ++j)
				NF[j] += F[j - 1] * prob[i - 1];
			F = move(NF);
		}
		return F[target];
	}
};