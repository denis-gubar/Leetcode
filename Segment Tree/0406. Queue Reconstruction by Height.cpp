class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		int N = people.size();
		vector<vector<int>> result(N);
		sort(people.begin(), people.end());
		int pos = 0, hm = 0;
		bool flag = true;
		for (int i = 0; i < N; ++i)
		{
			int empty = 0;
			int skip = people[i][1];
			flag = i == 0 || result[pos][0] != people[i][0];
			if (flag)
				pos = hm;
			else
				skip -= result[pos][1] + 1;
			while (true)
			{
				while (!result[pos].empty())
					++pos;
				if (flag && empty == 0)
					hm = pos;
				if (empty == skip)
					break;
				++empty;
				++pos;
			}
			result[pos] = people[i];
		}
		return result;
	}
};