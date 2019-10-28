class Solution {
public:
	vector<string> result;
	void calc(int pos, string& word, vector<vector<int>> const& A)
	{
		if (pos == word.size())
		{
			result.push_back(word);
			return;
		}
		for (int x = 0; x < A[pos].size(); ++x)
		{
			word[pos] = A[pos][x];
			calc(pos + 1, word, A);
		}
	}
	vector<string> permute(string S) {
		result.clear();
		vector<vector<int>> A;
		bool flag = false;
		for(int c: S)
			switch (c)
			{
				case '{':
					flag = true;
                    A.push_back({});
					break;
				case ',':
					break;
				case '}':
					flag = false;
					break;
				default:
					if (!flag)
						A.push_back({});
					A.back().push_back(c);
					break;
			}
		string word;
		for (vector<int> & row : A)
        {
            sort(row.begin(), row.end());
			word += row[0];
        }
		calc(0, word, A);
		return result;
	}
};