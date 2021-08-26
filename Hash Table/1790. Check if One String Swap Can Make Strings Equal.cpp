class Solution {
public:
	bool areAlmostEqual(string s1, string s2) {
		if (s1 == s2)
			return true;
		int N = s1.size();
		for (int i = 0; i < N; ++i)
			for (int j = i + 1; j < N; ++j)
			{
				swap(s1[i], s1[j]);
				if (s1 == s2)
					return true;
				swap(s1[i], s1[j]);
			}
		for (int i = 0; i < N; ++i)
			for (int j = i + 1; j < N; ++j)
			{
				swap(s2[i], s2[j]);
				if (s1 == s2)
					return true;
				swap(s2[i], s2[j]);
			}
		return false;
	}
};