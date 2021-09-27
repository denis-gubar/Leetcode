class Solution {
public:
	vector<int> findOriginalArray(vector<int>& changed) {
		int N = changed.size();
		if (N % 2 == 1 || N == 0)
			return {};
		vector<int> M(100'001);
		for (int x : changed)
			++M[x];
		if (M[0] % 2 == 1)
			return {};
		vector<int>	result;
		for (int i = 100'000; i > 0; --i)
			if (M[i] > 0)
			{
				if (i % 2 == 1 || M[i / 2] < M[i])
					return {};
				for (int k = 0; k < M[i]; ++k)
					result.push_back(i / 2);
				M[i / 2] -= M[i];
				M[i] = 0;				
			}
		for (int k = 0; k < M[0]; k += 2)
			result.push_back(0);
		return result;
	}
};