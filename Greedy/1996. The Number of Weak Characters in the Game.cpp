class Solution {
public:
	int numberOfWeakCharacters(vector<vector<int>>& properties) {
		int result = 0;
		sort(properties.begin(), properties.end(), [](vector<int> const& a, vector<int> const& b)
			{
				if (a[0] != b[0])
					return a[0] < b[0];
				return a[1] < b[1];
			});
		multiset<int> S;
		int N = properties.size();
		for (int i = 0; i < N; ++i)
		{
			int const& attack = properties[i][0];
			int const& defense = properties[i][1];
			int j = i;
			while (j + 1 < N && properties[j + 1][0] == attack)
				++j;
			for (int k = i; k <= j; ++k)
				while(!S.empty() && *S.begin() < properties[k][1])
                {
					++result;
                    S.erase(S.begin());
                }
			for (int k = i; k <= j; ++k)
				S.insert(properties[k][1]);
            i = j;
		}
		return result;
	}
};