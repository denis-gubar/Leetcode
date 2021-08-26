class Solution {
public:
	vector<int> sequentialDigits(int low, int high) {
		vector<int> result;
		vector<int> seqDigits;
		for (int n = 2; n < 10; ++n)
			for (int k = 1; k + n <= 10; ++k)
			{
				int x = 0;
				for (int z = 0; z < n; ++z)
					x = x * 10 + k + z;
				seqDigits.push_back(x);
			}
		sort(seqDigits.begin(), seqDigits.end());
		copy(lower_bound(seqDigits.begin(), seqDigits.end(), low),
			lower_bound(seqDigits.begin(), seqDigits.end(), high + 1),
			back_inserter(result));
		return result;
	}
};