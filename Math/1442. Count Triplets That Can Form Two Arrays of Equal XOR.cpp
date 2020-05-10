class Solution {
public:
	int countTriplets(vector<int>& arr) {
		int result = 0;
		int N = arr.size();
		vector<int> A{ 0 };
		partial_sum(arr.begin(), arr.end(), back_inserter(A), bit_xor<int>());
		for (int i = 0; i < N; ++i)
			for (int j = i + 1; j <= N; ++j)
				for (int k = max(i + 2, j + 1); k <= N; ++k)
					if (A[j] ^ A[i] == A[k] ^ A[j])
						++result;
		return result;
	}
};