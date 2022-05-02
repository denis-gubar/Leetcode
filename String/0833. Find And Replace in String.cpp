class Solution {
public:
	string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
		string result;
		int N = indexes.size();
		vector<int>	A(N);
		iota(A.begin(), A.end(), 0);
		sort(A.begin(), A.end(), [&indexes](int a, int b)
			{
				return indexes[a] > indexes[b];
			});
		int pos = 0;
		while (pos < S.size())
		{
			if (!A.empty() && pos == indexes[A.back()])
			{
				int i = A.back(); A.pop_back();
				if (pos + sources[i].size() <= S.size() && equal(sources[i].begin(), sources[i].end(), S.begin() + pos, S.begin() + pos + sources[i].size()))
				{
					result += targets[i];
					pos += sources[i].size();
					continue;
				}
			}
			result += S[pos];
			++pos;
		}
		return result;
	}
};