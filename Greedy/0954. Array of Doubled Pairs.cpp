class Solution {
public:
	bool canReorderDoubled(vector<int>& A) {
		vector<int> M(200001);
		for (int a : A)
			++M[a + 100000];
		if (M[100000] % 2)
			return false;
		for (int pos = 200000; pos > 100000; --pos)
			if (M[pos])
			{
				if (pos % 2)
					return false;
				int x = pos - 100000;
				int x2 = x / 2;
				if (M[pos] > M[x2 + 100000])
					return false;
				M[x2 + 100000] -= M[pos];
				M[pos] = 0;
			}
		for (int pos = 0; pos < 100000; ++pos)
			if (M[pos])
			{
				if (pos % 2)
					return false;
				int x = pos - 100000;
				int x2 = x / 2;
				if (M[pos] > M[x2 + 100000])
					return false;
				M[x2 + 100000] -= M[pos];
				M[pos] = 0;
			}
		return true;
	}
};