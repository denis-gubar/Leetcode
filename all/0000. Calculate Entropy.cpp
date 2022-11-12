class Solution {
public:
	double calculateEntropy(vector<int>& input) {
		double result = 0.0;
		int N = input.size();
		unordered_map<int, int> M;
		for (int x : input)
			++M[x];
		for (auto [x, count] : M)
			result -= (1.0 * count / N) * log(1.0 * count / N) / log(2);
		return result;
	}
};