double static F[1'001];
double static NF[1'001];
class Solution {
public:
	double probabilityOfHeads(vector<double>& prob, int target) {
		int N = prob.size();
		memset(F, 0, sizeof(F));
		F[0] = 1;
		for (int i = 1; i <= N; ++i)
		{
			memset(NF, 0, sizeof(NF));
			for (int j = 0; j < i; ++j)
				NF[j] = F[j] * (1.0 - prob[i - 1]);
			for (int j = 1; j <= i; ++j)
				NF[j] += F[j - 1] * prob[i - 1];
			copy(&NF[0], &NF[0] + N + 1, &F[0]);
		}
		return F[target];
	}
};