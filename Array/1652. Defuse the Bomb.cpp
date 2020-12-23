class Solution {
public:
	vector<int> decrypt(vector<int>& code, int k) {
		int N = code.size();
		vector<int> result(N);
		for (int i = 0; i < N; ++i)
			if (k > 0)
			{
				for (int z = 1; z <= k; ++z)
					result[i] += code[(z + i) % N];
			}
			else if (k < 0)
			{
				for (int z = 1; z <= -k; ++z)
					result[i] += code[(-z + i + 100 * N) % N];
			}
		return result;
	}
};