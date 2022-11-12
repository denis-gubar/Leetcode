class Solution {
public:
	double calculateEntropy(int N, unordered_map<int, int> const& M) {
		double result = 0.0;
		for (auto [x, count] : M)
			result -= (1.0 * count / N) * log(1.0 * count / N) / log(2);
		return result;
	}
	double calculateMaxInfoGain(vector<double>& petal_length, vector<string>& species) {
		int N = petal_length.size();
		vector<pair<double, string>> P(N);
		for (int i = 0; i < N; ++i)
			P[i] = { petal_length[i], species[i] };
		sort(P.begin(), P.end());
		unordered_map<string, int> groups;
		for (auto p : P)
			if (groups.find(p.second) == groups.end())
				groups[p.second] = groups.size();
		unordered_map<int, int> initial, left, right;
		for (int i = 0; i < N; ++i)
			++initial[groups[P[i].second]];
		left = initial;
		int leftSize = N, rightSize = 0;
		double initial_entropy = calculateEntropy(N, initial);
		double information_gain = 0;
		for (int i = N - 1; i > 0; --i)
		{
			int G = groups[P[i].second];
			if (--left[G] == 0)
				left.erase(G);
			++right[G];
			--leftSize;
			++rightSize;
			information_gain = max(information_gain, initial_entropy - 1.0 * calculateEntropy(leftSize, left) * leftSize / N - 1.0 * calculateEntropy(rightSize, right) * rightSize / N);
		}
		return information_gain;
	}
};