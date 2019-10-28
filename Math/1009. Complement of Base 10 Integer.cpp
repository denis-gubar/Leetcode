class Solution {
public:
	int bitwiseComplement(int N) {
        if (!N)
            return 1;
		int k = 0, x = N;
		while (x)
		{
			x >>= 1;
			++k;
		}
		return (1 << k) - N - 1;
	}
};