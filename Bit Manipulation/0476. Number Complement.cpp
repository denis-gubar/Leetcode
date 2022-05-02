class Solution {
public:
	int findComplement(int N) {
        if (!N)
            return 1;
		int k = 0, x = N;
		while (x)
		{
			x >>= 1;
			++k;
		}
		return (1LL << k) - N - 1;
	}
};