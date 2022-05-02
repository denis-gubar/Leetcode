class Solution {
public:
	int countPoints(string rings) {
		int result = 0;
		int N = rings.size();
		unordered_map<char, int> F{ {'R', 1}, {'G', 2}, {'B', 4 } };
		unordered_map<char, int> M;
		for (int i = 0; i < N; i += 2)
		{
			char c = rings[i];
			char r = rings[i + 1];
			M[r] |= F[c];
		}
		for (auto [key, value] : M)
			if (value == 7)
				++result;
		return result;
	}
};