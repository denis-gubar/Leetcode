class Solution {
public:
	int minimumSwap(string s1, string s2) {
		int result = 0;
		int N = s1.size();
		for (int i = 0; i < N; ++i)
			if (s1[i] == s2[i])
				s1[i] = s2[i] = '0';
		for(int i = 0; i < N; ++i)
			if (s1[i] != s2[i])
			{
				for (int j = i + 1; j < N; ++j)
					if (s1[i] == s1[j])
					{
						s1[i] = s2[i] = s1[j] = s2[j] = '0';
						++result;
						break;
					}
				if (s1[i] != '0')
				{
					swap(s1[i], s2[i]);
                    ++result;
					for (int j = i + 1; j < N; ++j)
						if (s1[i] == s1[j])
						{
							s1[i] = s2[i] = s1[j] = s2[j] = '0';
							++result;
							break;
						}
					if (s1[i] != '0')
						return -1;
				}
			}
		return result;
	}
};