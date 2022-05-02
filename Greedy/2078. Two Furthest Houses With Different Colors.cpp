class Solution {
public:
	int maxDistance(vector<int>& colors) {
		int result = 0;
		int N = colors.size();
		for (int i = 0; i < N; ++i)
			for (int j = i + 1; j < N; ++j)
				if (colors[i] != colors[j])
					result = max(result, j - i);
		return result;
	}
};