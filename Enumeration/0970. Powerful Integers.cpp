class Solution {
public:
	vector<int> powerfulIntegers(int x, int y, int bound) {
		vector<int> result;
		vector<bool> seive(bound + 1);
		for (int i = 0, a = 1; a < bound && i < 100; ++i, a *= x)
			for (int j = 0, b = 1; a + b <= bound && j < 100; ++j, b *= y)
				seive[a + b] = 1;
		for (int i = 0; i <= bound; ++i)
			if (seive[i])
				result.push_back(i);
		return result;
	}
};