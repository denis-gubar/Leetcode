class Solution {
public:
	bool calc(int N)
	{
		if (N == 1)
			return false;
		if (!F[N])
		{
			bool result = false;
			for (int i = 1; i * i <= N; ++i)
				if (N % i == 0)
					result |= !calc(N - i);
			F[N] = result + 1;
		}
		return F[N] == 2;
	}
	vector<int> F;
	bool divisorGame(int N) {
		F = vector<int>(1001);
		return calc(N);
	}
}; 