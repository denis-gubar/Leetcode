class Solution {
public:
	int minSkips(vector<int>& dist, int speed, int hoursBefore) {		
		int N = dist.size();
		long long H = 1LL * hoursBefore * speed;
		vector<int> F{ dist[0] };
		for (int i = 1; i < N; ++i)
		{
			vector<int> NF(F.size() + 1, 1 << 30);
			for (int j = 0; j < F.size(); ++j)
			{
				int T = 1LL * (F[j] + speed - 1) / speed * speed;
				T += dist[i];
				NF[j] = min(NF[j], T);
				NF[j + 1] = min(NF[j + 1], F[j] + dist[i]);
			}
			if (NF.back() == NF[NF.size() - 2])
				NF.pop_back();
			F = move(NF);
		}
		for (int result = 0; result < F.size(); ++result)
			if (F[result] <= H)
				return result;
		return -1;
	}
};