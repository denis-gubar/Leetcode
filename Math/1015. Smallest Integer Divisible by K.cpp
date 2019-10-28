class Solution {
public:
	int smallestRepunitDivByK(int K) {
		int N = 0;
		for (int k = 1; k <= K; ++k)
		{
			N *= 10;
			++N;
			N %= K;
            if (N == 0)
                return k;
		}
		return -1;
	}
};