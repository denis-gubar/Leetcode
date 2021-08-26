class Solution {
public:
	bool validWordSquare(vector<string>& words) {
		int N = words.size();
        for(string const& w : words)
            N = max<int>(N, w.size());
		auto get = [&words](int x, int y)
		{
			if (words.size() <= x || words[x].size() <= y)
				return ' ';
			return words[x][y];
		};
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (get(i, j) != get(j, i))
					return false;
		return true;
	}
};